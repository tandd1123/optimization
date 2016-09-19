#include "DMServiceImpl.h"

DMServiceImpl::DMServiceImpl()
{
    
}

void DMServiceImpl::init()
{
    DMTask::instance()->init();
}
    
void DMServiceImpl::register_message_factory(DMMessageFactory* msg_factory)
{
    _msg_factory = msg_factory;
}

