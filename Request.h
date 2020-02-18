#pragma once
#include <string>
#include "RequestMsg.pb.h"
#include "Codec.h"
using namespace std;
class Request: virtual public Codec
{
private:
	string m_encStr;
	RequestMsg m_msg;
public:
	Request();
	Request(string m_encStr);
	Request(int cmd, string clientID, string serverID, string sign, string data);
	void initMessage(string encStr);
	void initMessage(int cmd, string clientID, string severID, string sign, string data);
	string encodeMsg(void);
	void* decodeMsg(void);
	~Request();
};