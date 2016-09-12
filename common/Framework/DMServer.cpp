#include "DMServer.h"

DM_BOOL DMServer::init(const string& config_path, DM_INT argc, DM_CHAR *argv[])
{
    DMJsonCfg::instance()->load_config_file(config_path);
    
    DM_INT process_num = DMJsonCfg::instance()->GetItemInt("service_config", "process_num");
    init_process(process_num, argc, argv);
    
    return true;
}

void DMServer::run(DMService* pService)
{
    //_acceptor.open();
    //run_event_loop();
}
