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

    void set_process_options();
    
    void create_process(DM_INT process_num, int argc, char *argv[]);
    
    DM_BOOL is_master_process();
    
    void wait_all_process();
    
protected:
    ACE_Process* _child_process;
    ACE_Process_Options _options;
    DM_INT _process_num;
    pid_t* _pids;
    
private:
    int _argc;
    char** _argv;
};