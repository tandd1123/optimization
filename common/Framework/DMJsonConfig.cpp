#include "ace/Log_Msg.h"
#include "DMJsonConfig.h"

DM_BOOL DMJsonConfig::load_config_file(string file_path)
{
    _cfg_file.open(file_path.c_str(), std::ios::binary);

    if (!_cfg_file.is_open())
    {   
        return false;
    }
    if (!_json_reader.parse(_cfg_file,_json_root))
    {
        return false;
    }
    return true;
}

string DMJsonConfig::GetItemString(string element, string attribute)
{
    return _json_root[element][attribute].asString(); 
}
    
DM_INT DMJsonConfig::GetItemInt(string element, string attribute)
{
    return _json_root[element][attribute].asInt();
}

