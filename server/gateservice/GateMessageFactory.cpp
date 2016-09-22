#include "GateMessageFactory.h"
#include "GateService.h"

void GateMessageFactory::init_cmd()
{
    DM_TRACE("register_cmd");
    register_cmd(GET_PROXY_MSG, get_proxy_message);
}

DMMessageFactory* GateMessageFactory::clone()
{
    //调用拷贝构造函数
    return new GateMessageFactory(*this);
}
