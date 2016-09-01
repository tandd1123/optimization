#include "DMService.h"
#include <ace/Log_Msg.h>

int DMServer::init();
{
    
}

void DMServer::run();
{
    
}

void DMServer::register_service(DMService* handle) { _handle = handle; };
{
    _service = service;
}

void DMServer::register_message_factory(DMService* handle) { _handle = handle; };
{

}

