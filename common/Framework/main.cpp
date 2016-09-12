#include "DMaker.h"
#include "DMMultiProcess.h"

int DM_MAIN(int argc, ACE_TCHAR *argv[])
{
    DMJsonCfg::instance()->load_config_file("main.json");

    DMMultiProcess _process;
    if (1 == _process.create_process(4,argc,argv))
    {
        _process.wait_all_process();
    }
    ACE_Reactor::instance()->run_reactor_event_loop();
    return 0;
}
