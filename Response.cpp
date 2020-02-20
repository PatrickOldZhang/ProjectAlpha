#include "Response.h"

Response::Response()
{
}

Response::Response(string encStr)
{
	m_encStr = encStr;
}

Response::Response(int status, int seckeyID, string clientID, string severID, string data)
{
	
}

Response::Response(RespondInfo& info)
{
	initMessage(info);

}

Response::Response(RespondInfo* info)
{
	initMessage(info);
}

void Response::initMessage(string encStr)
{
	m_encStr = encStr;
}

void Response::initMessage(RespondInfo& info)
{
	m_msg.set_rv(info.status);
	m_msg.set_seckeyid(info.seckeyID);
	m_msg.set_clientid(info.clientID);
	m_msg.set_serverid(info.serverID);
	m_msg.set_data(info.data);

}

void Response::initMessage(RespondInfo* info)
{
	m_msg.set_rv(info->status);
	m_msg.set_seckeyid(info->seckeyID);
	m_msg.set_clientid(info->clientID);
	m_msg.set_serverid(info->serverID);
	m_msg.set_data(info->data);
}

void Response::initMessage(int status, int seckey, string clientID, string severID, string data)
{
}

string Response::encodeMsg(void)
{
	string output;
	m_msg.SerializeToString(&output);
	return ::std::move(output);
}

void* Response::decodeMsg(void)
{

	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}

Response::~Response()
{
}


