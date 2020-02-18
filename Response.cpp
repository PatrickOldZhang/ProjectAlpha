#include "Response.h"

Response::Response()
{
}

Response::Response(string encStr)
{
}

Response::Response(int status, int seckeyID, string clientID, string severID, string data)
{
}

void Response::initMessage(string encStr)
{
}

void Response::initMessage(int status, int seckey, string clientID, string severID, string data)
{
}

string Response::encodeMsg(void)
{
	return string();
}

void* Response::decodeMsg(void)
{
	return nullptr;
}

Response::~Response()
{
}


