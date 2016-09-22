//=============================================================================
/* 
*  File: GateMessageFactory.h
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
#include "DMMessageFactory.h"
#include "DMProtoMessage.h"

enum GateServiceMessage
{
    GET_PROXY_MSG = 2001,
};

//protoc message process
class GateMessageFactory : public DMMessageFactory
{
public:
    void init_cmd();
    
    virtual DMMessageFactory* clone();
};
