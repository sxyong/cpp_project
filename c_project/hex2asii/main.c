#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hex2asii.h"

int main()
{
#if 0
	char* buf = "a3b40a";
	char buf_out[100] = {0};

	int len = asii2hex(buf, strlen(buf), buf_out, 100);
#else
	char buf[4];
	buf[0] = 0xa0;
	buf[1] = 0xf1;
	buf[2] = 0xff;
	buf[3] = 0x14;

	char buf_out[100] = {0};
	int len = hex2asii(buf, 4, buf_out, 100);
#endif

	return 0;
}
