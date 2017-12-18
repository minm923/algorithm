/***************************************************************
 *
 * OpenBeacon.org - XXTEA encryption / decryption
 *                  exported functions
 *
 * Copyright 2006 Milosch Meriac <meriac@openbeacon.de>
 * 
 * https://xxtea-algorithm.googlecode.com/svn/trunk
 *
 ***************************************************************


 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; version 2.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along
 with this program; if not, write to the Free Software Foundation, Inc.,
 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#ifndef __XXTEA_H__
#define __XXTEA_H__

#include <stdint.h>
#include <string>

class CXXTeaMgr
{
    public :
        CXXTeaMgr();
        ~CXXTeaMgr();

        static CXXTeaMgr * Instance();

    public :
        /**
         * @brief xxtea 加密算法, 下一次调用会把上一次的结果给覆盖掉 
         * @param[in] data 加密数据
         * @param[in] len 加密数据长度
         * @param[in] key 秘钥, 长度为 16 byte，也就是 128 bit
         * @param[out] ret_len 加密数据长度 
         *
         * @retval 加密后的数据; 失败则返回 NULL
         */
        unsigned char * xxtea_encrypt(const unsigned char *data, uint32_t len, unsigned char *key, uint32_t *ret_len);
        
        /**
         * @brief xxtea 解密算法, 下一次调用会把上一次的结果给覆盖掉 
         * @param[in] data 要解密数据
         * @param[in] len 要解密据长度
         * @param[in] key 秘钥, 长度为 16 byte，也就是 128 bit
         * @param[out] ret_len 要解密的数据长度 
         *
         * @retval 解密后的数据; 失败则返回 NULL
         */
        unsigned char * xxtea_decrypt(const unsigned char *data, uint32_t len, unsigned char *key, uint32_t *ret_len);

        /**
         * @brief 生成 key, key_len = 17
         * @param[out] random_key 生成的 key
         * @param[in] key_len random_key 长度，都传 17
         * @param[in] usec 随机种子，传当前时间的微秒数，从 gettimeofday 里获取 
         *
         */
        void get_key(char * random_key, unsigned key_len, unsigned int usec);

    private :
        void xxtea_long_encrypt(uint32_t *v, uint32_t len, uint32_t *k);
        void xxtea_long_decrypt(uint32_t *v, uint32_t len, uint32_t *k);

        uint32_t * xxtea_to_long_array(const unsigned char *data, uint32_t len, int include_length, uint32_t *ret_len, unsigned char * raw, uint32_t raw_len);
        unsigned char *xxtea_to_byte_array(uint32_t *data, uint32_t len, int include_length, uint32_t *ret_len, unsigned char * out, uint32_t out_len);

    private :
        const static int MAX_RAW_BUFF_SIZE = 64 * 1024;
        unsigned char m_szRaw[MAX_RAW_BUFF_SIZE];

        const static int MAX_RESULT_BUFF_SIZE = 64 * 1024;
        unsigned char m_szResult[MAX_RESULT_BUFF_SIZE];

        const static int MAX_KEY_BUFF_SIZE = 64;
        unsigned char m_szKey[MAX_KEY_BUFF_SIZE];

        std::string m_sFailStr;
};

#endif/*__XXTEA_H__*/

