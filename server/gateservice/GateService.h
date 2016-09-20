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

enum GateMessage
{
    MSG_TEST = 2001,
};

void message_test(DMMessage& message);

class GateService : public DMService
{
public:
    void init_cmd();
};

typedef ACE_Singleton<GateService, ACE_Thread_Mutex> GateSrv; 
