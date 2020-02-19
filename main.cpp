#include <iostream>
#include "Request.h"
#include "Response.h"
#include "RequestMsg.pb.h"
#include "RespondMsg.pb.h"

using namespace std;

// 编码
string encodeMsg(Codec* c)
{
	return c->encodeMsg();
}

// 解码
void* decodeMsg(Codec* c)
{
	return c->decodeMsg();
}

int main()
{
	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.clientID = "OncePice";
	reqInfo.serverID = "Luffy";
	reqInfo.data = "我是要成为海贼王的男人";
	reqInfo.sign = "哈哈,呵呵,嘿嘿";
	Request req(reqInfo);
	// 编码
	string reqMsg = encodeMsg(&req);
	// 解码
	Request req1(reqMsg);
	RequestMsg* rqMsg = (RequestMsg*)decodeMsg(&req1);
	cout << "CmdType: " << rqMsg->cmdtype()
		<< ", ClientID: " << rqMsg->clientid()
		<< ", ServerID: " << rqMsg->serverid()
		<< ", Data: " << rqMsg->data()
		<< ", Sign: " << rqMsg->sign() << endl;

	////////////////////////////////////////////////
	//////          华丽的分隔线          ////////////
	////////////////////////////////////////////////
	RespondInfo resInfo;
	resInfo.status = false;
	resInfo.clientID = "宇智波佐助";
	resInfo.serverID = "宇智波鼬";
	resInfo.data = "火影忍者";
	resInfo.seckeyID = 123;
	Response res(resInfo);
	// 编码
	string resMsg = encodeMsg(&res);
	// 解码
	Response res1(resMsg);
	RespondMsg* rsMsg = (RespondMsg*)decodeMsg(&res1);
	cout << "Status: " << rsMsg->rv()
		<< ", ClientID: " << rsMsg->clientid()
		<< ", ServerID: " << rsMsg->serverid()
		<< ", Data: " << rsMsg->data()
		<< ", SecKeyID: " << rsMsg->seckeyid() << endl;

	return 0;
}