#include "DMMultiTask.h"

void DMMultiTask::init()
{
    _task_num = DMJsonCfg::instance()->GetItemInt("service_config", "task_num");
    activate(THR_NEW_LWP | THR_JOINABLE |THR_INHERIT_SCHED , _task_num);//创建线程
}

int DMMultiTask::svc(void)
{
    ACE_Message_Block *msg_block;// = new ACE_Message_Block();
    while(True)
    {
        getq(msg_block);            //空闲线程阻塞
        DM_TRACE("recevie msg:%s,time:%d\n",msg_block->rd_ptr(),(int)ACE_OS::time());
        msg_block->release();        //release
        ACE_OS::sleep(1);    //延时1s模拟业务处理耗时
    }
}

