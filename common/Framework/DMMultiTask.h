//=============================================================================
/* 
*  File: DMMultiTask.h
*
*  Author: bing
*
*  Date: 2016-09-18
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

typedef struct MsgData
{
    DM_INT msg_cmd;
    DM_INT data_length;
    char* data;
    
    MsgData()
    {
        msg_cmd = 0;
        data_length = 0;
        data = nullptr;
    }
}MsgBlock;
 
class DMMultiTask : public ACE_Task<ACE_MT_SYNCH>
{
public:
    
    void init();
    
    virtual DM_INT svc(void);

private:
    DM_INT _task_num;        
};

typedef ACE_Singleton<DMMultiTask, ACE_Thread_Mutex> DMTask; 

