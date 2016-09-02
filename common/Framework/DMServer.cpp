#include "DMService.h"

DMServer::DMServer()
{
    _service = SERVICE_HANDLE;
    _dispatcher.register_service(_service);
}

DM_BOOL DMServer::init(const string& config_path);
{
    _acceptor.open();
}

void DMServer::run();
{
    
}

