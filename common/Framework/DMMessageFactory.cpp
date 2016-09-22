#include "DMMessageFactory.h"

void DMMessageFactory::register_cmd(DM_INT message_cmd, MESSAGE_CALLBACK_HANDLE func)
{
    _cmd_map[message_cmd] = func;
}

MESSAGE_CALLBACK_HANDLE DMMessageFactory::find_callback_handle(DM_INT cmd)
{
    map<DM_INT, MESSAGE_CALLBACK_HANDLE>::iterator it = _cmd_map.find(cmd);
    if (it != _cmd_map.end())
    {
        return it->second;
    }
    
    return nullptr;
}

