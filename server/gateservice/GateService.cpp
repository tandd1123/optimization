#include "GateService.h"

void message_test(DMMessage& message)
{
    DMMessage msg = message;
    DM_TRACE("message test!data=%s,addr=%d",message.body,&message.body);
    GateSrv::instance()->send_message(msg.head.msg_uid,msg,DM_APP);
}

void GateService::init_cmd()
{
    register_cmd(MSG_TEST, message_test);
}