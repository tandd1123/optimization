#include "DMServer.h"

DM_BOOL DMServer::init(const string& config_path, DM_INT argc, DM_CHAR *argv[])
{
    DMJsonCfg::instance()->load_config_file(config_path);  
    init_process(argc, argv);
    //_acceptor.open();
    //run_event_loop();    
    return true;
}

void DMServer::run(/*DMService* pService*/)
{        
    int pid = getpid();
    DM_PRINT("pid = %d",pid);
    run_event_loop();
}
