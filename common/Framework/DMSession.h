//=============================================================================
/* 
*  File: DMSession.h
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
#include "DMServer.h"
#include "DMMessageFactory.h"

class DMSession
{
public:
	DMSession(ACE_HANDLE fd, DM_BOOL enable = False);

    ~DMSession();

    void init();

    MESSAGE_CALLBACK_HANDLE get_service_callback();
    
	ACE_HANDLE _fd;   //fd

    DMService* _service;  //service

    DMMessageFactory* _msg_factory;    

    DM_BOOL _enable;

protected:
private:
};
