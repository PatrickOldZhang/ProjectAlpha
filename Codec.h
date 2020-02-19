#pragma once
#include <string>
using namespace std;
class Codec
{
public:
	Codec();
	virtual ~Codec();
	virtual string encodeMsg()=0;
	virtual void* decodeMsg()=0;
};