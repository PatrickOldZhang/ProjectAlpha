#include <iostream>
#include <string>
#include "Request.h"
#include "Response.h"


int main(void)
{
	Request rq("hello world");
	rq.initMessage("hello world");
	rq.decodeMsg();
	string res = rq.encodeMsg();

	Response rp("Hello");
	rp.initMessage("Fuck you too!");
	rp.decodeMsg();
	res = rp.encodeMsg();

	cout << "¿ò¼Ü´î½¨Íê±Ï" << endl;
	return 0;
}

