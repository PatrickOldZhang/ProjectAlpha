#include "Request.h"

Request::Request()
{

}

Request::Request(string encStr)
{

}

Request::Request(int cmd, string clientID, string severID, string sign, string data)
{

}

Request::~Request()
{

}

void Request::initMessage(string encStr)
{

}


void Request::initMessage(int cmd, string clientID, string severID, string sign, string data)
{

}

string Request::encodeMsg(void)
{
	return string();
}

void* Request::decodeMsg(void)
{
	return nullptr;
}






