//=============================================================================
/* 
*  File: DMServerImpl.h
*
*  Author: bing
*
*  Date: 2016-09-06
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

#pragma once
#include "DMaker.h"
#include "DMMultiProcess.h"

class DMServerImpl : private DMMultiProcess
{
public:
    void init_process(DM_INT argc, DM_CHAR *argv[]);
    
    void run_event_loop();
    
private:

    void run_master_process();
};
