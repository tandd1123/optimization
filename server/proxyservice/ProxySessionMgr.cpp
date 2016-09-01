#include "ProxySessionMgr.h"
#include <ace/Log_Msg.h>

int ProxySessionManager::add_session(ACE_HANDLE handle, short uid, ProxySession* pSession)
{
	_mutex_lock.acquire();
    
    pSession->uid = uid;
	_sessions[handle] = pSession;
    
	_mutex_lock.release();
    
	return 0;
}

int ProxySessionManager::activate_session(ACE_HANDLE fd)
{
	int ret = -1;
    
	if (nullptr != find_session(fd))
	{
		_sessions[fd]->enable = true;
		ret = 0;
	}
    
	return ret;
}

int ProxySessionManager::deactivate_session(ACE_HANDLE fd)
{
	int ret = -1;
    
	if (nullptr != find_session(fd))
	{
		_sessions[fd]->enable = false;
		ret = 0;
	}
    
	return ret;
}

int ProxySessionManager::activate_session(short uid)
{
	int ret = -1;

    ProxySession* pSession = find_session(uid);
	if (nullptr != pSession)
	{
		pSession->enable = true;
		ret = 0;
	}
    
	return ret;
}

int ProxySessionManager::deactivate_session(short uid)
{
	int ret = -1;
    
    ProxySession* pSession = find_session(uid);
	if (nullptr != pSession)
	{
		pSession->enable = false;
		ret = 0;
	}

    
	return ret;
}

ProxySession* ProxySessionManager::find_session(ACE_HANDLE fd)
{
	std::map<ACE_HANDLE, ProxySession*>::iterator it = _sessions.find(fd);
    
	if (it != _sessions.end())
	{
		return it->second;
	}
    
	return nullptr;
}

ProxySession* ProxySessionManager::find_session(short uid)
{
    std::map<ACE_HANDLE, ProxySession*>::iterator it = _sessions.begin();
    for (; it != _sessions.end(); ++it)
    {
        ProxySession* pSession = it->second;
        if (uid == pSession->uid)
        {
            return it->second;
        }
    }
    return nullptr;
}

ACE_HANDLE ProxySessionManager::find_fd(short uid)
{
	ProxySession* pSession = find_session(uid);
    
    std::map<ACE_HANDLE, ProxySession*>::iterator it = _sessions.begin();
    for (; it != _sessions.end(); ++it)
    {
        if (pSession == it->second)
        {
            return it->first;
        }
    }
        
	return -1;
}

int ProxySessionManager::del_session(ACE_HANDLE fd)
{
	_mutex_lock.acquire();
    
	int ret = -1;
    
	if (nullptr != find_session(fd))
	{
	    delete _sessions[fd];
		_sessions.erase(fd);
		ret = 0;
	}
    
	_mutex_lock.release();
    
	return ret;
}

int ProxySessionManager::del_session(short uid)
{
	_mutex_lock.acquire();
    
	int ret = -1;

    std::map<ACE_HANDLE, ProxySession*>::iterator it = _sessions.begin();
    for (; it != _sessions.end(); ++it)
    {
        ProxySession* pSession = it->second;
        if (uid == pSession->uid)
        {
            delete it->second;
            _sessions.erase(it);
            ret = 0;
        }
    }
    
	_mutex_lock.release();
    
	return ret;
}

