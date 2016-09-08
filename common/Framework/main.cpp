#include "DMaker.h"
#include "DMMultiProcess.h"

int DM_MAIN(int argc, ACE_TCHAR *argv[])
{
    DMJsonCfg::instance()->load_config_file("main.json");

    DMMultiProcess _process;
    _process.create_process(1,argc,argv);
    DM_TRACE("PID=%d,argc=%s\n",getpid(),argv[0]);
    _process.wait_all_process();
    ACE_Reactor::instance()->run_reactor_event_loop();
    return 0;
}
