#pragma once
#include <string>
#include "RequestMsg.pb.h"
#include "Codec.h"
using namespace std;

struct RequestInfo
{
	int cmd;
	string clientID;
	string serverID;
	string sign;
	string data;
};


class Request:  public Codec
{
private:
	string m_encStr;
	RequestMsg m_msg;
public:
	Request();
	Request(string m_encStr);
	Request(RequestInfo& info);
	Request(RequestInfo* info);
	Request(int cmd, string clientID, string serverID, string sign, string data);
	void initMessage(string encStr);
	void initMessage(RequestInfo& info);
	void initMessage(RequestInfo* info);
	void initMessage(int cmd, string clientID, string severID, string sign, string data);
	string encodeMsg(void);
	void* decodeMsg(void);
	~Request();
};