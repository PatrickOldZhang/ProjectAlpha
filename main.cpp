#include <iostream>
#include "Request.h"
#include "Response.h"
#include "RequestMsg.pb.h"
#include "RespondMsg.pb.h"
#include "Factory.h"


using namespace std;

// ���� ����ָ������õ������ຯ��
string encodeMsg(Codec* c)
{
	return c->encodeMsg();
}

// ����
void* decodeMsg(Codec* c)
{
	return c->decodeMsg();
}


Codec* createObj(baseFactory* base)
{
	return base->createObj();
}

int main()
{
	// ������������ RequestFactory();


	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.clientID = "Manu Ginobili";
	reqInfo.serverID = "Agentina";
	reqInfo.data = "Score Guard";
	reqInfo.sign = "��̫����";
	
	// ���� RequestFactory ����
	baseFactory* base = new RequestFactory(&reqInfo);
	// Req�������� Request ����
	Codec* reqCode = base->createObj();	
	// ����
	string reqMsg = encodeMsg(reqCode);
	

	// Req�������� Request ���� 
	Codec* reqDec = base->createObj();
	((Request*)reqDec)->initMessage(reqMsg); // ��ʼ����Ҳ�����޸Ĺ��캯�����ڹ��캯���н��г�ʼ����
	// ����
	RequestMsg* rqMsg = (RequestMsg*)decodeMsg(reqDec);
	cout << "CmdType: " << rqMsg->cmdtype()
		<< ", ClientID: " << rqMsg->clientid()
		<< ", ServerID: " << rqMsg->serverid()
		<< ", Data: " << rqMsg->data()
		<< ", Sign: " << rqMsg->sign() << endl;
	delete reqDec;
	delete reqCode;
	delete base;

	////////////////////////////////////////////////
	//////          �����ķָ���          ////////////
	////////////////////////////////////////////////
	RespondInfo resInfo;
	resInfo.status = false;
	resInfo.clientID = "Tim Duncan";
	resInfo.serverID = "Spurs";
	resInfo.data = "Power Forward";
	resInfo.seckeyID = 123;

	// ���� res����
	base = new RespondFactory(&resInfo);
	Codec* res = createObj(base);
	// ����
	string resMsg = encodeMsg(res);
	// ����
	Codec* resDec = createObj(base);

	RespondMsg* rsMsg = (RespondMsg*)decodeMsg(resDec);
	cout << "Status: " << rsMsg->rv()
		<< ", ClientID: " << rsMsg->clientid()
		<< ", ServerID: " << rsMsg->serverid()
		<< ", Data: " << rsMsg->data()
		<< ", SecKeyID: " << rsMsg->seckeyid() << endl;

	// clean up 
	delete res;
	delete resDec;
	delete base;
	return 0;
}