#include "DMServiceImpl.h"
#include "DMMultiTask.h"

map<DM_INT, MESSAGE_CALLBACK_HANDLE>  DMServiceImpl::_cmd_map;

void DMServiceImpl::init()
{
    DMTask::instance()->init();
    DMTask::instance()->register_message_callback(message_task_callback);
}
    
void DMServiceImpl::register_message_factory(DMMessageFactory* msg_factory)
{
    _factory = msg_factory;   
}

void DMServiceImpl::register_cmd(DM_INT message_cmd, MESSAGE_CALLBACK_HANDLE func)
{
    _cmd_map[message_cmd] = func;
}

void DMServiceImpl::send_message(DM_INT uid, DMMessage& msg, DM_INT dest)
{
    if (DM_APP == dest)//session
    {
    
    }
    else if (DM_MQ == dest)//route
    {
    
    }
}

void DMServiceImpl::message_task_callback(DMMessage& msg)
{
    DM_TRACE("service recivie message!");
    map<DM_INT, MESSAGE_CALLBACK_HANDLE>::iterator it = _cmd_map.find(msg.head.msg_cmd);
    if (it != _cmd_map.end())
    {
        (it->second)(msg);
    }
}

