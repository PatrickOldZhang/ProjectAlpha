#include <iostream>
#include "Request.h"
#include "Response.h"
#include "RequestMsg.pb.h"
#include "RespondMsg.pb.h"
#include "Factory.h"


using namespace std;

// 编码 父类指针或引用调用子类函数
string encodeMsg(Codec* c)
{
	return c->encodeMsg();
}

// 解码
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
	// 创建工厂对象 RequestFactory();


	RequestInfo reqInfo;
	reqInfo.cmd = 9;
	reqInfo.clientID = "Manu Ginobili";
	reqInfo.serverID = "Agentina";
	reqInfo.data = "Score Guard";
	reqInfo.sign = "我太难了";
	
	// 创建 RequestFactory 对象
	baseFactory* base = new RequestFactory(&reqInfo);
	// Req工厂生产 Request 对象
	Codec* reqCode = base->createObj();	
	// 编码
	string reqMsg = encodeMsg(reqCode);
	

	// Req工厂生产 Request 对象 
	Codec* reqDec = base->createObj();
	((Request*)reqDec)->initMessage(reqMsg); // 初始化，也可以修改构造函数，在构造函数中进行初始化。
	// 解码
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
	//////          华丽的分隔线          ////////////
	////////////////////////////////////////////////
	RespondInfo resInfo;
	resInfo.status = false;
	resInfo.clientID = "Tim Duncan";
	resInfo.serverID = "Spurs";
	resInfo.data = "Power Forward";
	resInfo.seckeyID = 123;

	// 创建 res对象
	base = new RespondFactory(&resInfo);
	Codec* res = createObj(base);
	// 编码
	string resMsg = encodeMsg(res);
	// 解码
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