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
    void init_process(DM_INT process_num, DM_INT argc, DM_CHAR *argv[]);
    
    virtual void run()=0;
    
private:

    void run_master_process();
    
    void run_subprogram_process();
};