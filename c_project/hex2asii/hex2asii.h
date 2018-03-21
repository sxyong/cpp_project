/**************************************************
 * author:		songxy
 * daste:		2018/03/14
 * function:	convert hex buf to asii buf
 * 				convert asii buf to hex buf
 *************************************************/
#pragma once

/**
 * @Discription : convert hex buf to asii buf
 *
 * @Parameter : hex_buf store hex data
 * @Parameter : hex_len hex buf's size
 * @Parameter : asii_buf store asii buf 
 * @Parameter : asii_len asii buf's size
 *
 * @Return : <=0 failed >0 store asii data's size
 */
int hex2asii(const char* hex_buf, int hex_len, char* asii_buf, int asii_len);

/**
 * @Discription : 
 *
 * @Parameter : asii_buf store asii data
 * @Parameter : asii_len asii buf's size
 * @Parameter : hex_buf store hex data
 * @Parameter : hex_len hex buf's size
 *
 * @Return : <=0 failed >0 store hex data's size
 */
int asii2hex(const char* asii_buf, int asii_len, char* hex_buf, int hex_len);
