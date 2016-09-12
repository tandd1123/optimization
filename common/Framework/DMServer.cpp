#include "DMServer.h"

DM_BOOL DMServer::init(const string& config_path, int argc, char *argv[])
{
    DMJsonCfg::instance()->load_config_file(config_path);
    //_acceptor.open();
    return true;
}

void DMServer::run(DMService* pService)
{
    //run_event_loop();
}

