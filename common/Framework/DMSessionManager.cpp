#include "DMSessionManager.h"

void DMSessionManager::init(DMService* service, DMMessageFactory* factory)
{
    _service = service;
    _factory = factory;
}

int DMSessionManager::add_session(DM_INT uid, ACE_HANDLE handle)
{         
	_mutex_lock.acquire();

    if (nullptr != _sessions[uid])
    {
        return 0;
    }
    
	_sessions[uid] = new DMSession(handle);
    _sessions[uid]->_service = _service->Clone();
    _sessions[uid]->_msg_factory = _factory->Clone();
    
	_mutex_lock.release();
    
	return 0;
}

int DMSessionManager::activate_session(DM_INT uid)
{
	int ret = -1;
    
	if (nullptr != find_session(uid))
	{
		_sessions[uid]->_enable = true;
		ret = 0;
	}
    
	return ret;
}

int DMSessionManager::deactivate_session(DM_INT uid)
{
	int ret = -1;
    
	if (nullptr != find_session(uid))
	{
		_sessions[uid]->_enable = false;
		ret = 0;
	}
    
	return ret;
}

DMSession* DMSessionManager::find_session(DM_INT uid)
{
	std::map<ACE_HANDLE, DMSession*>::iterator it = _sessions.find(uid);
    
	if (it != _sessions.end())
	{
		return it->second;
	}
    
	return nullptr;
}

ACE_HANDLE DMSessionManager::find_fd(DM_INT uid)
{
	DMSession* pSession = _sessions[uid];
    
    if (nullptr != pSession)
    {
        return pSession->_fd;
    }
        
	return -1;
}

int DMSessionManager::del_session(DM_INT uid)
{
	_mutex_lock.acquire();
    
	int ret = -1;
    
	if (nullptr != find_session(uid))
	{
	    delete _sessions[uid]->_service;
        delete _sessions[uid]->_msg_factory;
	    delete _sessions[uid];
		_sessions.erase(uid);
		ret = 0;
	}
    
	_mutex_lock.release();
    
	return ret;
}

