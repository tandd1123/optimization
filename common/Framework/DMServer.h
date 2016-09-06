//=============================================================================
/* 
*  File: DMServer.h
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

class DMServer : public DMServerImpl
{
public:

	DM_BOOL init(const std::string& config_path);
    
	void run(DMService* pService);

private:

    DMAcceptor _acceptor;
    
	DMDispatcher _dispatcher;
    
	DMService* _service;
};

