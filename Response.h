#pragma once
#include"RespondMsg.pb.h"
#include"Codec.h"
#include <string>
using namespace std;


struct RespondInfo
{
	int status;
	int seckeyID;
	string clientID;
	string serverID;
	string data;
};


class Response: public Codec
{
private:
	string m_encStr;
	RespondMsg m_msg;
public:
	Response();
	Response(string encStr);
	Response(int status, int seckeyID, string clientID, string severID, string data);
	Response(RespondInfo& info);
	void initMessage(string encStr);
	void initMessage(RespondInfo& info);
	void initMessage(int status, int seckey, string clientID, string severID, string data);
	string encodeMsg(void);
	void* decodeMsg(void);
	~Response();
};