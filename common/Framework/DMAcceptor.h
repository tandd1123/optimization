//=============================================================================
/* 
*  File: DMAcceptor.h
*
*  Author: bing
*
*  Date: 2016-09-12
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
#include "DMDispatcher.h"

typedef ACE_Acceptor<DMDispatcher, ACE_SOCK_ACCEPTOR> Acceptor;

class DMAcceptor : public Acceptor
{
public:
    static DMAcceptor* instance()
	{
		if (nullptr == _instance)
		{
			_instance = new DMAcceptor;
		}
		return _instance;
	}

    DM_INT init(DM_INT argc, DM_CHAR *argv[]);
    
    ACE_Reactor* get_reactor();
    
private:
    
    ACE_Reactor* _reactor;
    
    static DMAcceptor *_instance;
};
