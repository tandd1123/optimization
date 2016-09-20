//=============================================================================
/* 
*  File: DMMessageFactory.h
*
*  Author: bing
*
*  Date: 2016-09-01
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
#include "DMMultiTask.h"
#include "DMMessage.h"

//消息指定编解码类

class DMMessageFactory
{
public:
    
    virtual void init_cmd()=0;
  
    void register_cmd(DM_INT message_cmd, MESSAGE_CALLBACK_HANDLE func);

    MESSAGE_CALLBACK_HANDLE find_callback_handle(DM_INT cmd);
    
private:
    map<DM_INT, MESSAGE_CALLBACK_HANDLE> _cmd_map;
};

