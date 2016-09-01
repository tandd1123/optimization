#pragma once
#include "amqpcpp/include/message.h"
#include "DMServiceHandle.h"
#include "DMRouter.h"

//调整类成员结构，可单独运行，业务接入采取策略模式，降低代码耦合，DMServiceHandle为接入对象,心跳和维护处理虽也是到业务层，但由底层类封装屏蔽处理
//控制类应该处于网络层和应用层之间，需要封装底层IO和dispatch，route应该在更底层，放在dispatch下一层
//dispatch除了包含route，还需要包含一个消息工厂。这个消息工厂由业务层提供，包括了消息定义注册和消息头处理和proto规则。对业务直接提供可靠数据
//由此，业务上只需要提供业务handle策略和消息工厂即可，这两个都必须提供一套完整的底层基本功能类，上层只需要进行基本的注册操作即可
//所有ACE和MQ接口均在底层处理转接到业务上的接口重新在此基础上重命名调用
//数据库和其他第三方接口单独存在，完全独立通用，以组合形式引用到业务上

template <typename SERVICE_HANDLE>
class DMServer
{
public:
    //接收器
    typedef ACE_Acceptor<SERVICE_HANDLE, ACE_SOCK_ACCEPTOR> DMAcceptor;
    //初始化进程数量
	int init();
    
	void run();

	void register_service(DMService* service);
    
	void register_message_factory(DMMessageFactory* handle) { _handle = handle; };
private:
    //IO层，底层统一处理，不对外提供
    DMAcceptor _acceptor;
    //dispatch层，底层定义，对外提供消息工厂的注册
	DMDispatcher _dispatcher;
    //业务层，策略实现
	DMService* _service;
};

