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

    void print_log(const DM_CHAR* fmt, ...);
   
    void trace_log(string file, string func, DM_INT line, const DM_CHAR* fmt, ...);
          
    void write_log(DM_INT log_level, string file, string func, DM_INT line, const DM_CHAR* fmt, ...);
    
private:
    void init();

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

//console output without code info
#define DM_PRINT(LOG_FMT,args...) DMLogMgr::instance()->print_log(LOG_FMT,##args)
//console output with code info
#define DM_TRACE(LOG_FMT,args...) DMLogMgr::instance()->trace_log(__FILE__,__FUNCTION__,__LINE__,LOG_FMT,##args)
//write logs into log file
#define DM_LOG(LOG_LEVEL,LOG_FMT,args...) DMLogMgr::instance()->write_log(LOG_LEVEL,__FILE__,__FUNCTION__,__LINE__,LOG_FMT,##args)
