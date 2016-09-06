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

class DMJsonConfig
{
public:

    DM_BOOL load_config_file(string& file_path);
    
    string GetItemInt(const string& element,const string& attribute) const;
    
    string GetItemString(const string& element,const string& attribute) const;
    
private:

    std::ifstream _cfg_file;
    
    Json::Reader _json_reader;
    Json::Value _json_root;
};