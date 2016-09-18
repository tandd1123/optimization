//=============================================================================
/* 
*  File: DMJsonConfig.h
*
*  Author: bing
*
*  Date: 2016-09-05
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

#pragma once
#include "DMaker.h"
#include "ace/Singleton.h"

class DMJsonConfig
{
public:

    DM_BOOL load_config_file(string file_path);
    
    string GetItemString(string element, string attribute);
    
    DM_INT GetItemInt(string element, string attribute);
    
private:

    std::ifstream _cfg_file;
    
    Json::Reader _json_reader;
    Json::Value _json_root;
};

typedef ACE_Singleton<DMJsonConfig, ACE_Thread_Mutex> DMJsonCfg;

