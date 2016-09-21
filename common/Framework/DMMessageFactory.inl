//=============================================================================
/* 
*  File: DMMessageFactory.inl
*
*  Author: bing
*
*  Date: 2016-09-21
*
*  Version: v2.0
*
*  Github/Mail: https://github.com/binchen-china    <563853086@qq.com>
*
*  Note:
*/
//=============================================================================

template<class PROTO_NAME>
DM_BOOL DMMessageFactory::paser_proto_message(DM_CHAR* msg, PROTO_NAME& proto_msg, DM_INT msg_length)
{
	//pb decode
	string msg_data(msg,msg_length);
	if (!proto_msg.ParseFromString(msg_data))
	{
		DM_LOG(DM_ERROR,"ParseFromString error!\n");
		return False;
	}
    return True;
}

template<class PROTO_NAME>
DM_BOOL pack_proto_message(DM_CHAR* msg, PROTO_NAME& proto_msg)
{
    std::string msg_data;
    if (!proto_msg.SerializeToString(msg_data))
	{
        DM_LOG(DM_ERROR,"SerializeToString error!\n");
		return False;
	}
    memcpy(msg,msg_data.c_str(),msg_data.length());
    return True;
}
