#pragma once
#include"RespondMsg.pb.h"
#include"Codec.h"
#include <string>
using namespace std;


class Response: virtual public Codec
{
private:
	string m_encStr;
	RespondtMsg m_msg;
public:
	Response();
	Response(string encStr);
	Response(int status, int seckeyID, string clientID, string severID, string data);
	void initMessage(string encStr);
	void initMessage(int status, int seckey, string clientID, string severID, string data);
	string encodeMsg(void);
	void* decodeMsg(void);
	~Response();
};