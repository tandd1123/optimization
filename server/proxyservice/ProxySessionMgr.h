#pragma once
#include "ProxySession.h"
#include "ace/Singleton.h"
#include <map>

class ProxySessionManager
{
public:
	int add_session(ACE_HANDLE handle, short uid, ProxySession* pSession);
    
	int activate_session(ACE_HANDLE fd);

    int deactivate_session(ACE_HANDLE fd);

    int activate_session(short uid);

    int deactivate_session(short uid);
    
	ProxySession* find_session(short uid);

	ProxySession* find_session(ACE_HANDLE fd);

	ACE_HANDLE find_fd(short uid);

	int del_session(short uid);

    int del_session(ACE_HANDLE fd);

protected:
private:
	ACE_Thread_Mutex _mutex_lock;
	std::map<ACE_HANDLE, ProxySession*> _sessions;   //fd session
};

typedef ACE_Singleton<ProxySessionManager, ACE_Thread_Mutex> ProxySessionMgr; 
