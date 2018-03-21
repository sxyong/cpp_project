#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>
#include "hex2asii.h"

uint8_t hex_to_asii(uint8_t var)
{
	if(var >= 0 && var <= 9)
	{
		return var + '0';
	}
	else
	{
		return var - 10 + 'A';
	}
}

uint8_t asii_to_hex(uint8_t var)
{
	if(isdigit(var))
	{
		return var - '0';
	}
	else if(isupper(var))
	{
		return var - 'A' + 10;
	}
	else if(islower(var))
	{
		return var - 'a' + 10;
	}
}

int hex2asii(const char* hex_buf, int hex_len, char* asii_buf, int asii_len)
{
	if(hex_buf == NULL || hex_len <= 0 || asii_buf == NULL || asii_len <=0)
		return -1;

	if(asii_len < hex_len*2)
		return -2;

	for(int i=0;i<hex_len;i++)
	{
		uint8_t c = (uint8_t)hex_buf[i];
		uint8_t c1 = (c&0xF0) >> 4;
		uint8_t c2 = (c&0x0F);
		asii_buf[2*i] = hex_to_asii(c1);
		asii_buf[2*i + 1] = hex_to_asii(c2);
	}

	return hex_len*2;
}

int asii2hex(const char* asii_buf, int asii_len, char* hex_buf, int hex_len)
{
	if(asii_buf == NULL || asii_len <= 0 || hex_buf == NULL || hex_len <=0)
		return -1;

	if(hex_len < asii_len/2)
		return -2;

	for(int i=0;i<asii_len;i++)
	{
		uint8_t c1 = asii_to_hex(asii_buf[2*i]);
		uint8_t c2 = asii_to_hex(asii_buf[2*i+1]);

		hex_buf[i] = (c1<<4) | c2;
	}

	return asii_len/2;
}
