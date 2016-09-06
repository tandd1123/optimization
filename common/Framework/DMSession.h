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

typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH> Svc_Handler;

class DMSession
{
public:
	DMSession(Svc_Handler* handle):_handle(handle){};

	short uid;   //uid

    bool enable;

	void bind(Svc_Handler* handle) { _handle = handle; };
protected:
private:
	Svc_Handler* _handle;
};