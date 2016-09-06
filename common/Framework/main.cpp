#include "DMaker.h"
#include "DMMultiProcess.h"

int main()
{
    DMMultiProcess _process;
    _process.create_process(10);
    ACE_DEBUG((LM_INFO,"PID=%d",getpid()));
    _process.wait_all_process();
    return 0;
}
