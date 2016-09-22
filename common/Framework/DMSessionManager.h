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

class DMService;
class DMMessageFactory;
class DMSession;

class DMSessionManager
{
public:
    void init(DMService* service, DMMessageFactory* factory);
    
	int add_session(DM_INT uid, ACE_HANDLE handle);
    
	int activate_session(DM_INT uid);

    int deactivate_session(DM_INT uid);

	DMSession* find_session(DM_INT uid);

	ACE_HANDLE find_fd(DM_INT uid);

	int del_session(DM_INT uid);

protected:
    
private:
    DMService* _service;

    DMMessageFactory* _factory;
    
	ACE_Thread_Mutex _mutex_lock;
    
	std::map<DM_INT, DMSession*> _sessions;   //fd session
};

typedef ACE_Singleton<DMSessionManager, ACE_Thread_Mutex> DMSessionMgr; 

