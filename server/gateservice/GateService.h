//=============================================================================
/* 
*  File: GateService.h
*
*  Author: bing
*
*  Date: 2016-09-20
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
#include "DMService.h"

void get_proxy_message(DMMessage& message);

class GateService : public DMService
{
public:
    virtual DMService* clone();
    void get_proxy_info(DMMessage& message);
};

typedef ACE_Singleton<GateService, ACE_Thread_Mutex> GateSrv; 
