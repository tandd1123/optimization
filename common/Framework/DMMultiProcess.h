//=============================================================================
/* 
*  File: DMMultiProcess.h
*
*  Author: bing
*
*  Date: 2016-09-06
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note: set master process as a daemon  
*/
//=============================================================================

#pragma once
#include "DMaker.h"

class DMMultiProcess
{
public:
    DMMultiProcess();

    DM_INT set_process_options(ACE_Process_Options& options);
    
    DM_INT create_process(DM_INT argc, DM_CHAR *argv[]);

    void wait_all_process();

private:
    ACE_Process_Manager* _process_manager;
    DM_INT _process_num;
    int _argc;
    char** _argv;
};
