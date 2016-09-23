#include "GateMessageFactory.h"
#include "GateService.h"

#include <lua.hpp>

void GateMessageFactory::init_cmd()
{
    register_cmd(GET_PROXY_MSG, get_proxy_message);
}
