#include "DMaker.h"
#include "DMMultiProcess.h"

int main(int argc, char *argv[])
{
    DMJsonCfg::instance()->load_config_file("main.json");
    //DMLogMgr::instance()->init();
    DMMultiProcess _process;
    _process.create_process(1,argc,argv);
    ACE_DEBUG((LM_INFO,"PID=%d,argc=%s\n",getpid(),argv[0]));
    _process.wait_all_process();
    return 0;
}
