#include "DMJsonConfig.h"

DM_BOOL DMJsonConfig::load_config_file(string& file_path)
{
    _cfg_file.open(SERVICE_MAP_PATH, std::ios::binary);

    if (!_cfg_file.is_open())
    {   
        ACE_DEBUG((LM_INFO,"open DMaker.json config failure!\n"));
        return false;
    }
    if (!_json_reader.parse(cfg_file,_json_root))
    {
        return false;
    }
    return true;
}

string DMJsonConfig::GetItemInt(const string& element,const string& attribute) const
{
    return _json_root[element][attribute].asString;
}
    
string DMJsonConfig::GetItemString(const string& element,const string& attribute) const
{
    return _json_root[element][attribute].asInt;
}
