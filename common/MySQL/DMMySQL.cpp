#include "json/json.h"
#include <fstream>
#include <ace/Log_Msg.h>
#include "DMMySQL.h"
#include <cxxabi.h>

#define TRY_SQL \
    try{
    
#define CATCH_SQL_ERROR \
}\
catch(const mysqlpp::BadQuery& error)\
{\
    ACE_DEBUG((LM_ERROR,"MySQL Query error:%s!\n",error.what()));\
    return false;\
}\
catch (const mysqlpp::BadConversion& error)\
{\
    ACE_DEBUG((LM_ERROR,"MySQL Conversion error:%s!\n",error.what()));\
    return false;\
}\
catch (const mysqlpp::Exception& error)\
{\
    ACE_DEBUG((LM_ERROR,"MySQL Exception error:%s!\n",error.what()));\
    return false;\
}

DMMySQL::DMMySQL()
{
    init();
}

DMMySQL::~DMMySQL()
{
    disconnect_mysql();
}

bool DMMySQL::load_mysql_config()
{
    std::ifstream cfg_file;
    cfg_file.open(MYSQL_CFG_FILE, std::ios::binary);

    if (!cfg_file.is_open())
    { 
        return 0;
    }

    Json::Reader Reader;
    Json::Value Root;

    if (Reader.parse(cfg_file,Root))
    {
        _mysql_cfg.ip = Root["mysql_ip"].asString();
        _mysql_cfg.port = Root["mysql_port"].asInt();
        _mysql_cfg.user = Root["mysql_user"].asString();
        _mysql_cfg.passwd = Root["mysql_passwd"].asString();
        _mysql_cfg.database_name = Root["database_name"].asString();
    }
    else
    {
        ACE_DEBUG((LM_ERROR,"parse mysql config file failure!\n"));    
        return false;
    }
    
    return true;
}

void DMMySQL::init()
{
    if (load_mysql_config())
    {
        conncet_mysql();
    }
}

bool DMMySQL::conncet_mysql()
{ 
    if (!_conn.connect(_mysql_cfg.database_name.c_str(), _mysql_cfg.ip.c_str(),
        _mysql_cfg.user.c_str(), _mysql_cfg.passwd.c_str(), _mysql_cfg.port))
    {
        ACE_DEBUG((LM_ERROR,"connect MySQL database failure!\n"));    
        return false;
    }

    return true;
}

void DMMySQL::show_databases_info(int flag, std::vector<std::string>& databases)
{
    std::string opration;    
   
    switch (flag)
    {
    case SHOW_VERISON:
        {
            std::string version_info = _conn.client_version();
            databases.push_back(version_info);
            return;
        }
    case SHOW_DATABASES:
        {
            opration = "show databases";
            break; 
        }
    case SHOW_TABLES:
        {
            
            opration = "show tables";
            break; 
        }
    default:
        {
            return;
        }
    }

    mysqlpp::Query query = _conn.query(opration);
    if (mysqlpp::StoreQueryResult res = query.store())
    {           
        mysqlpp::StoreQueryResult::iterator rit;	
        for (rit = res.begin(); rit != res.end(); ++rit) 
        {
            databases.push_back((*rit)[0].c_str());
        }    
    }
}

bool DMMySQL::get_table_desc(std::string table_name, mysql_table_info& tbl_info)
{
    TRY_SQL
    std::string opration = "describe " + table_name;    
    mysqlpp::Query query = _conn.query(opration);
    mysqlpp::StoreQueryResult res = query.store();

    int field_num = res.size();
    for (int i = 0; i < field_num; ++i)
    {
        mysql_field_info field_i;
        
        field_i.Field   = res[i]["field"].c_str();
        field_i.Type    = res[i]["type"].c_str();
        field_i.Null    = res[i]["null"].c_str();
        field_i.Key     = res[i]["key"].c_str();
        field_i.Default = res[i]["default"].c_str();
        field_i.Extra   = res[i]["extra"].c_str();
        
        tbl_info.push_back(field_i);
    }
    CATCH_SQL_ERROR
    return true;
}

void DMMySQL::disconnect_mysql()
{
    _conn.disconnect();
}

bool DMMySQL::insert_mysql(std::string sql)
{
    TRY_SQL
    mysqlpp::Query query = _conn.query(sql);
    query.execute();
    CATCH_SQL_ERROR
    return true;
}

bool DMMySQL::insert_mysql(std::string table_name, std::map<std::string, std::string>& insert_data)
{
    TRY_SQL
    std::string fields;
    std::string values;
    std::map<std::string, std::string>::iterator it = insert_data.begin();
    while (it != insert_data.end())
    {
        fields += it->first;
        values += it->second; 
        
        ++it;
        
        if (it != insert_data.end())
        {
            fields += ",";
            values += ",";
        }
    }
    
    std::string opration = "insert into " + table_name + "(" + fields + ")" + " values(" + values + ")";
    mysqlpp::Query query = _conn.query(opration);
    query.execute();
    CATCH_SQL_ERROR
    return true;
}

bool DMMySQL::update_mysql(std::string sql)
{
    TRY_SQL
    mysqlpp::Query query = _conn.query(sql);
    query.execute();
    CATCH_SQL_ERROR
    return true;
}

bool DMMySQL::update_mysql(std::string table_name, std::string field_name, std::string field_value, 
    std::string filter_key, std::string filter_value)
{
    TRY_SQL
    std::string opration = "update "+ table_name + " set " + field_name + " = " + field_value
        + " where " + filter_key + " = " + filter_value;    
    mysqlpp::Query query = _conn.query(opration);
    query.execute();
    CATCH_SQL_ERROR
    return true;
}

bool DMMySQL::select_mysql(std::string table_name, mysql_table& table_data)
{
    TRY_SQL
    std::string opration = "select * from " + table_name;    
    mysqlpp::Query query = _conn.query(opration);
    mysqlpp::StoreQueryResult res = query.store();
    
    int field_num = res.num_fields();
    if (!field_num)
    {
        return false;
    }    

    int row_size = res.size();
    for (int i = 0; i < field_num; ++i)  //字段
    {    
        std::vector<mysql_field> fields;
        for (int j = 0; j < row_size; ++j) //数据条数
        {
            mysqlpp::Row row = res[j];
            
            std::string sql_data = row[res.field_name(i).c_str()].c_str();
            std::string sql_type = res.field_type(i).name();

            mysql_field field_data;
            trans_data_type(sql_data, sql_type, field_data);
            fields.push_back(field_data);
        }
        table_data.insert(make_pair(res.field_name(i).c_str(),fields));
    }
    CATCH_SQL_ERROR
    return true;
}

bool DMMySQL::select_mysql(std::string table_name, std::string field_name, std::vector<mysql_field>& field_data)
{
    TRY_SQL
    std::string opration = "select " + field_name + " from " + table_name;    
    mysqlpp::Query query = _conn.query(opration);
    mysqlpp::StoreQueryResult res = query.store();
    
    int field_num = res.num_fields();
    if (!field_num)
    {
        return false;
    }    

    int field_index;
    for (int i = 0; i < field_num; ++i)  //字段
    {
        if (field_name == res.field_name(i).c_str())
        {
            field_index = i;
        }
    }
    
    int row_size = res.size();
    std::vector<mysql_field> fields;
    for (int i = 0; i < row_size; ++i) //数据条数
    {
        mysqlpp::Row row = res[i];
                    
        std::string sql_data = row[res.field_name(field_index).c_str()].c_str();
        std::string sql_type = res.field_type(field_index).name();

        mysql_field field;
        trans_data_type(sql_data, sql_type, field);
        field_data.push_back(field);
    }
    CATCH_SQL_ERROR
    return true;
}

bool DMMySQL::select_mysql(std::string table_name, std::string field_name, 
    std::string filter_key, std::string filter_value, 
    std::vector<mysql_field>& field_data, std::string filter_opt)
{
    TRY_SQL
    std::string opration = "select " + field_name + " from " + table_name 
        + " where " + filter_key + " " + filter_opt + "　" + filter_value;    
    mysqlpp::Query query = _conn.query(opration);
    mysqlpp::StoreQueryResult res = query.store();
    
    int field_num = res.num_fields();
    if (!field_num)
    {
        return false;
    }    

    int field_index;
    for (int i = 0; i < field_num; ++i)  //字段
    {
        if (field_name == res.field_name(i).c_str())
        {
            field_index = i;
        }
    }
    
    int row_size = res.size();
    std::vector<mysql_field> fields;
    for (int i = 0; i < row_size; ++i) //数据条数
    {
        mysqlpp::Row row = res[i];
                    
        std::string sql_data = row[res.field_name(field_index).c_str()].c_str();
        std::string sql_type = res.field_type(field_index).name();

        mysql_field field;
        trans_data_type(sql_data, sql_type, field);
        field_data.push_back(field);
    }
    CATCH_SQL_ERROR
    return true;
}

void DMMySQL::trans_data_type(std::string input_data, std::string data_type, mysql_field& field_data)
{
    int result;
    data_type = abi::__cxa_demangle(data_type.c_str(), 0, 0, &result);

    if (data_type.find("tiny_int") != std::string::npos)
    {
        field_data.SHORT = atoi(input_data.c_str());
    }
    else if (data_type.find("short") != std::string::npos)
    {
        field_data.SHORT = atoi(input_data.c_str());
    }
    else if (data_type.find("int") != std::string::npos)
    {
        field_data.INTEGER= atoi(input_data.c_str());
    }
    else if (data_type.find("long") != std::string::npos)
    {
        field_data.BIGINT = atol(input_data.c_str());
    }
    else if (data_type.find("float") != std::string::npos)
    {
        field_data.FLOAT= atof(input_data.c_str());
    }
    else if (data_type.find("double") != std::string::npos)
    {
        field_data.DOUBLE = atof(input_data.c_str());
    }
    else if (data_type.find("DateTime") != std::string::npos)
    {
        field_data.DATETIME = input_data;    
    }
    else if (data_type.find("string") != std::string::npos)
    {
        field_data.VARCHAR = input_data;
    }
    else
    {
        field_data.VARCHAR = input_data;
    }
}

