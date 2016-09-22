#include "DMMultiTask.h"
#include "DMSession.h"

void DMMultiTask::init()
{
    _task_num = DMJsonCfg::instance()->GetItemInt("service_config", "task_num");
    activate(THR_NEW_LWP | THR_JOINABLE |THR_INHERIT_SCHED , _task_num);//创建线程
}

void DMMultiTask::put_msg(DMMessage* msg)
{
    ACE_Data_Block *Data_Block = new ACE_Data_Block; //线程做释放

    DM_CHAR *p = reinterpret_cast <DM_CHAR*>(msg);
    Data_Block->base(p,sizeof(DMMessage));
    ACE_Message_Block* msg_block = new ACE_Message_Block(Data_Block); 
    putq(msg_block);
}

int DMMultiTask::svc(void)
{
    ACE_Message_Block *msg_block;// = new ACE_Message_Block();
    while(True)
    {
        getq(msg_block);            //空闲线程阻塞
        ACE_Data_Block *Data_Block = msg_block->data_block();
        DMMessage* pData = reinterpret_cast <DMMessage*>(Data_Block->base());

        DMSession* pSession = DMSessionMgr::instance()->find_session(pData->head.msg_uid);

        if (nullptr != pSession)
        {
            _func_callback = pSession->get_service_callback();
            _func_callback(*pData);
        }
        
        msg_block->release();        //release
    }
}

