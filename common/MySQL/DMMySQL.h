#pragma once
#include "mysql++.h"

#define MYSQL_CFG_FILE "..//..//common//MySQL//config.json"
//sql语句操作全部修改为配置加载，全部入参修正为配置读上来的命令映射的sql语句，保留一个通配接口。

typedef struct mysql_config
{
    std::string ip;
    int port;
    std::string user;
    std::string passwd;
    std::string database_name;
}mysql_cfg;

typedef struct mysql_field_information
{
    std::string Field;
    std::string Type;
    std::string Null;
    std::string Key;
    std::string Default;
    std::string Extra;
}mysql_field_info;

typedef std::vector<mysql_field_info> mysql_table_info;

typedef struct mysql_field_data
{
    //数字类型
    short SHORT;
    int INTEGER;
    long long BIGINT;
    float FLOAT;
    double DOUBLE;
    //时间戳类型
    std::string DATETIME;
    //字符类型
    std::string VARCHAR;
}mysql_field;

typedef std::map<std::string, std::vector<mysql_field>> mysql_table; //字段，值

enum mysql_database_info
{
    SHOW_VERISON,
    SHOW_DATABASES,
    SHOW_TABLES
};

class DMMySQL
{
public:
    DMMySQL();
    ~DMMySQL();

    void show_databases_info(int flag, std::vector<std::string>& databases);

    bool get_table_desc(std::string table_name, mysql_table_info& table_info);

    bool insert_mysql(std::string sql);
    
    bool insert_mysql(std::string table_name, std::map<std::string, std::string>& insert_data);
    
    bool update_mysql(std::string sql);

    bool update_mysql(std::string table_name, std::string field_name, std::string field_value,
        std::string filter_key, std::string filter_value);

    bool select_mysql(std::string table_name, mysql_table& table_data);

    bool select_mysql(std::string table_name, std::string field_name, std::vector<mysql_field>& field_data);

    bool select_mysql(std::string table_name, std::string field_name, 
        std::string filter_key, std::string filter_value, 
        std::vector<mysql_field>& field_data, std::string filter_opt = "=");
    
private:
    bool load_mysql_config();
    
    void init();
     
    bool conncet_mysql();

    void disconnect_mysql();

    void trans_data_type(std::string input_data, std::string data_type, mysql_field& field_data);

private:
    mysql_cfg _mysql_cfg;
    mysqlpp::Connection _conn;
};

