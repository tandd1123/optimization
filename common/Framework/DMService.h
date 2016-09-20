//=============================================================================
/* 
*  File: DMService.h
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
#include "DMServiceImpl.h"
//底层封装消息接收和消息发送

enum message_cmd
{
    //系统消息   
};

class DMService : public DMServiceImpl
{
	//注册系统消息
};

