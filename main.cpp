#include <iostream>
#include "Request.h"
#include "Response.h"
#include "RequestMsg.pb.h"
#include "RespondMsg.pb.h"

using namespace std;

// ����
string encodeMsg(Codec* c)
{
	return c->encodeMsg();
}

// ����
void* decodeMsg(Codec* c)
{
	return c->decodeMsg();
}

int main()
{
	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.clientID = "Manu Ginobili";
	reqInfo.serverID = "Agentina";
	reqInfo.data = "Score Guard";
	reqInfo.sign = "Team Winner";
	Request req(reqInfo);
	// ����
	string reqMsg = encodeMsg(&req);
	// ����
	Request req1(reqMsg);
	RequestMsg* rqMsg = (RequestMsg*)decodeMsg(&req1);
	cout << "CmdType: " << rqMsg->cmdtype()
		<< ", ClientID: " << rqMsg->clientid()
		<< ", ServerID: " << rqMsg->serverid()
		<< ", Data: " << rqMsg->data()
		<< ", Sign: " << rqMsg->sign() << endl;

	////////////////////////////////////////////////
	//////          �����ķָ���          ////////////
	////////////////////////////////////////////////
	RespondInfo resInfo;
	resInfo.status = false;
	resInfo.clientID = "Tim Duncan";
	resInfo.serverID = "Spurs";
	resInfo.data = "Power Forward";
	resInfo.seckeyID = 123;
	Response res(resInfo);
	// ����
	string resMsg = encodeMsg(&res);
	// ����
	Response res1(resMsg);
	RespondMsg* rsMsg = (RespondMsg*)decodeMsg(&res1);
	cout << "Status: " << rsMsg->rv()
		<< ", ClientID: " << rsMsg->clientid()
		<< ", ServerID: " << rsMsg->serverid()
		<< ", Data: " << rsMsg->data()
		<< ", SecKeyID: " << rsMsg->seckeyid() << endl;

	return 0;
}