//=============================================================================
/* 
*  File: DMLogManager.h
*
*  Author: bing
*
*  Date: 2016-09-07
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

enum LOG_LEVEL
{
    DM_ERROR = 0x0001,
    DM_WARNING  = 0x0010,
    DM_INFO = 0x0100,
    DM_DEBUG = 0x1000
};

class DMLogManager
{
public:
    DMLogManager();
    
    ~DMLogManager();
    
    void init();

    void write_function_trace(string file, string func, DM_INT line);
    
    void write_log(DM_INT log_level, const DM_CHAR* fmt, ...);
    
private:
    void get_log_config();
    
    inline void open_log_file();
    
    inline void close_log_file();
    
    void set_log_level();

private:
    FILE* _log_file;
    string _log_name;
    string _log_level;
    DM_INT _log_mask;
};

typedef ACE_Singleton<DMLogManager, ACE_Thread_Mutex> DMLogMgr;

#define __DM_LOG__   __FILE__,__FUNCTION__,__LINE__

#define DM_TRACE() DMLogMgr::instance()->write_function_trace(__DM_LOG__)

#define DM_LOG(LOG_LEVEL,LOG_FMT,args...) DMLogMgr::instance()->write_log(LOG_LEVEL,LOG_FMT,##args)
