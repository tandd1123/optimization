//=============================================================================
/* 
*  File: DMSessionManager.h
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

class DMSessionManager
{
public:
	int add_session(ACE_HANDLE handle, short uid, DMSession* pSession);
    
	int activate_session(ACE_HANDLE fd);

    int deactivate_session(ACE_HANDLE fd);

    int activate_session(short uid);

    int deactivate_session(short uid);
    
	DMSession* find_session(short uid);

	DMSession* find_session(ACE_HANDLE fd);

	ACE_HANDLE find_fd(short uid);

	int del_session(short uid);

    int del_session(ACE_HANDLE fd);

protected:
private:
	ACE_Thread_Mutex _mutex_lock;
	std::map<ACE_HANDLE, DMSession*> _sessions;   //fd session
};

typedef ACE_Singleton<DMSessionManager, ACE_Thread_Mutex> ProxySessionMgr; 
