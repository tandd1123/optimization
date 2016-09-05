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