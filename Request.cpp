#include "Request.h"

Request::Request()
{

}

Request::Request(string encStr)
{
	initMessage(encStr);
}

Request::Request(RequestInfo& info)
{
	initMessage(info);
}

Request::Request(int cmd, string clientID, string severID, string sign, string data)
{
	

}

Request::~Request()
{

}

void Request::initMessage(string encStr)
{
	m_encStr = encStr;
}

void Request::initMessage(RequestInfo& info)
{
	m_msg.set_cmdtype(info.cmd);
	m_msg.set_clientid(info.clientID);
	m_msg.set_serverid(info.serverID);
	m_msg.set_sign(info.sign);
	m_msg.set_data(info.data);

}


void Request::initMessage(int cmd, string clientID, string severID, string sign, string data)
{

}

string Request::encodeMsg(void)
{
	string output;
	m_msg.SerializeToString(&output);
	return ::std::move(output);
}

void* Request::decodeMsg(void)
{

	m_msg.ParseFromString(m_encStr);
	return &m_msg;
}






