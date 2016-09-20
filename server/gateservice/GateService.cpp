#include "GateService.h"

void message_test(DMMessage& message)
{
    DM_TRACE("message test!data=%s,addr=%d",message.body,&message.body);
    GateSrv::instance()->send_message(message.head.msg_uid,message,DM_MQ);
}

void GateService::init_cmd()
{
    register_cmd(MSG_TEST, message_test);
}