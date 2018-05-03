#include <iostream>
#include <string>
#include "ConfigParse.h"

using namespace std;

int main(int argc, char* argv[])
{
	ConfigParse parse;
	if(parse.Load("config.txt") != 0)
	{
		cout<<"Load failed"<<endl;
		return -1;
	}

	char* pValue = NULL;
	if(parse.GetNameValue("src_ip", pValue) != 0)
	{
		cout<<"get src_ip failed"<<endl;
	}

	cout<<"src_ip="<<pValue<<endl;

	if(parse.GetNameValue("src_ip1", pValue) != 0)
	{
		cout<<"get src_ip1 failed"<<endl;
	}

	return 0;
}
