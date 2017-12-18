/* xxt encryptor by aliver               */
/* Version 2.0                           */
/*                                       */
/* An implementation of xxtea encryption */
/* A very small (code wise) secure block */
/* cipher. Supposedly faster than btea   */
/* and for files of any non-trival size  */
/* it's gonna be way faster than TEA or  */
/* IDEA. At worst it's something like 4x */
/* the speed of DES, and more secure by  */
/* a factor of 2^72 ~ 4.7 x 10^21        */
/* My tests seemed to indicate that xxt  */
/* is about 3x the speed of mcrypt with  */
/* the same options. Not that mcrypt is  */
/* not a great piece of work. It is.     */
/*                                       */
/* The xxtea algorithm was designed by:  */
/* David Wheeler and Roger Needham. Some */
/* code from their publications was used */
/* for some of the encryption portions.  */
/* However it was altered to be 64 bit   */
/* architecture friendly.                */
/*                                       */
/* Rain Forest Puppy, Zen Parse, Steven  */
/* M. Christey, Hank Leininger, Daniel   */
/* Hartmeier, and anyone I forgot who    */
/* provided me with feedback, bugfixes,  */
/* or pointed out errors in the original */
/* release of xxt                        */
/*****************************************/
/* CHANGE LOG - CHANGE LOG - CHANGE LOG  */
/* Version 2                             */
/* o Tried to mitigate race condition in */
/*   -g by wiping the environment var as */
/*   soon as it's copied.                */
/* o Checked for NULL pointer on -g      */
/* o Added use of O_EXCL for opening the */
/*   output file.                        */
/* o Fixed problem whereby the hash of   */
/*   the key was being reduced to 64bits */
/*   since I was using a char array that */
/*   was being populated with ascii hex  */
/*   values rather than just binary      */
/* o Moved the argv trashing loop up so  */
/*   that it happens before any file I/O */
/* o Fixed an issue whereby someone may  */
/*   create a malicious xxt crypted file */
/*   with a bad filesize header. Now I   */
/*   check for this.                     */
/* o Checked for access to read & write  */
/*   to file in case someone is dumb     */
/*   enough to make this setuid root     */
/* o Added the -f functionality to use a */
/*   whole file as the key. The file is  */
/*   hashed to a 128 bit key.            */
/*****************************************/
/* Compile with cc -O3 -o xxt xxt.c      */
/* "xxt -h" for help, after that         */
/* tested on IRIX, Solaris, Linux        */
/* NetBSD, and AIX                       */

/*****************************************/
/* CHANGE LOG - CHANGE LOG - CHANGE LOG  */
/* Anagha Mudigonda version 3*/
/* I used most alivers logic as is but I */
/* removed main and a lot of functions I */
/* do not need for kamaelia. Also I use  */
/* my own keygen function so I removed   */
/* the MD5 related code                  */
/*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
//#include <inttypes.h>
#include <string.h>
#include <errno.h>
#include <time.h>
//#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

#include "XXTeaMgr.h"

// 原来的没加 () 导致报错 
// #define XXTEA_MX (z >> 5 ^ y << 2) + (y >> 3 ^ z << 4) ^ (sum ^ y) + (k[p & 3 ^ e] ^ z)
#define XXTEA_MX ((((z >> 5) ^ (y << 2)) + ((y >> 3) ^ (z << 4))) ^ ((sum ^ y) + (k[(p & 3) ^ e] ^ z)))

#define XXTEA_DELTA 0x9e3779b9

CXXTeaMgr::CXXTeaMgr()
{
    m_sFailStr = "(null)";
}

CXXTeaMgr::~CXXTeaMgr()
{
}

CXXTeaMgr * CXXTeaMgr::Instance()
{
    static CXXTeaMgr inst;
    return &inst;
}

void CXXTeaMgr::xxtea_long_encrypt(uint32_t *v, uint32_t len, uint32_t *k)
{
    uint32_t n = len - 1;
    uint32_t z = v[n], y = v[0], p, q = 6 + 52 / (n + 1), sum = 0, e;
    if (n < 1)
    {
        return;
    }

    while (0 < q--)
    {
        sum += XXTEA_DELTA;
        e = sum >> 2 & 3;
        for (p = 0; p < n; p++)
        {
            y = v[p + 1];
            z = (v[p] += XXTEA_MX);
        }
        y = v[0];
        z = (v[n] += XXTEA_MX);
    }
}

void CXXTeaMgr::xxtea_long_decrypt(uint32_t *v, uint32_t len, uint32_t *k)
{
    uint32_t n = len - 1;
    uint32_t z = v[n], y = v[0], p, q = 6 + 52 / (n + 1), sum = q * XXTEA_DELTA, e;
    if (n < 1)
    {
        return;
    }

    while (sum != 0) 
    {
        e = sum >> 2 & 3;
        for (p = n; p > 0; p--) 
        {
            z = v[p - 1];
            y = (v[p] -= XXTEA_MX);
        }
        z = v[n];
        y = (v[0] -= XXTEA_MX);
        sum -= XXTEA_DELTA;
    }
}

uint32_t * CXXTeaMgr::xxtea_to_long_array(const unsigned char *data, uint32_t len, int include_length, uint32_t *ret_len, unsigned char * raw, uint32_t raw_len) 
{
    uint32_t i, n, *result;
    uint32_t real_len = 0;

	n = len >> 2;
    n = (((len & 3) == 0) ? n : n + 1);
    
    result = (uint32_t *) raw;
    if (include_length) 
    {
        // result = (uint32_t *) malloc((n + 1) << 2);
        result[n] = len;
		*ret_len = n + 1;
        real_len = (n + 1) << 2;
	}
    else
    {
        // result = (uint32_t *)malloc(n << 2);
		*ret_len = n;
        real_len = n << 2;
    }

    if (real_len >= raw_len)
    {
        return NULL;
    }

	memset(result, 0, n << 2);
	for (i = 0; i < len; i++) 
    {
        result[i >> 2] |= (uint32_t)data[i] << ((i & 3) << 3);
    }

    return result;
}

unsigned char * CXXTeaMgr::xxtea_to_byte_array(uint32_t *data, uint32_t len, int include_length, uint32_t *ret_len, unsigned char * out, uint32_t out_len)
{
    uint32_t i, n, m;
    unsigned char *result;
    n = len << 2;
    if (include_length)
    {
        m = data[len - 1];
        if ((m < n - 7) || (m > n - 4))
        {
            return NULL;
        }
        n = m;
    }

    if ((n + 1) >= out_len)
    {
        return NULL;
    }

    // result = (unsigned char *)malloc(n + 1);
	result = (unsigned char *) out;

    for (i = 0; i < n; i++)
    {
        result[i] = (unsigned char)((data[i >> 2] >> ((i & 3) << 3)) & 0xff);
    }
	result[n] = '\0';
	*ret_len = n;
	return result;
}

unsigned char * CXXTeaMgr::xxtea_encrypt(const unsigned char *data, uint32_t len, unsigned char *key, uint32_t *ret_len)
{
    unsigned char *result;
    uint32_t *v, *k, v_len, k_len;
    v = xxtea_to_long_array(data, len, 1, &v_len, m_szRaw, sizeof(m_szRaw));
    if (NULL == v)
    {
        return NULL;
    }

    k = xxtea_to_long_array(key, 16, 0, &k_len, m_szKey, sizeof(m_szKey));
    if (NULL == k)
    {
        return NULL;
    }

    xxtea_long_encrypt(v, v_len, k);
    result = xxtea_to_byte_array(v, v_len, 0, ret_len, m_szResult, sizeof(m_szResult));
    if (NULL == result || 0 == strncmp((char *) result, m_sFailStr.c_str(), m_sFailStr.size()))
    {
        result = NULL;
    }
    // free(v);
    // free(k);
    return result;
}

unsigned char * CXXTeaMgr::xxtea_decrypt(const unsigned char *data, uint32_t len, unsigned char *key, uint32_t *ret_len)
{
    unsigned char *result;
    uint32_t *v, *k, v_len, k_len;

    v = xxtea_to_long_array(data, len, 0, &v_len, m_szRaw, sizeof(m_szRaw));
    if (NULL == v)
    {
        return NULL;
    }

    k = xxtea_to_long_array(key, 16, 0, &k_len, m_szKey, sizeof(m_szKey));
    if (NULL == k)
    {
        return NULL;
    }

    xxtea_long_decrypt(v, v_len, k);
    result = xxtea_to_byte_array(v, v_len, 1, ret_len, m_szResult, sizeof(m_szResult));

    if (NULL == result || 0 == strncmp((char *) result, m_sFailStr.c_str(), m_sFailStr.size()))
    {
        result = NULL;
    }

    // free(v);
    // free(k);
    return result;
}

void CXXTeaMgr::get_key(char *random_key, unsigned key_len, unsigned int usec) 
{
    char tmp[11]; // max of 10 digits ( i am assuming rand returns a 32 bit number)
    unsigned key_cnt = 0;
    int i = 0;
    int tmp_len = 0;

    // struct timeval tp;
    //gettimeofday(&tp, NULL);
    //localtime()
    srand(usec);

    while(key_cnt < key_len)
    {
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "%x", rand());
        tmp_len = strlen(tmp);
        for(i=0; ((i < tmp_len) && (key_cnt < key_len)); i++, key_cnt++) 
        {
            random_key[key_cnt] = tmp[i];
        }
    }

    random_key[key_cnt] = 0;
}

