/*********************************************************************
* Filename:   sha256.h
* Author:     Brad Conte (brad AT bradconte.com)
* Copyright:  Public Domain
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Defines the API for the corresponding SHA1 implementation.
*********************************************************************/

#ifndef SHA256_H
#define SHA256_H

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SHA256_BLOCK_SIZE 32
#define SHA256_SALT_SIZE 32

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;


typedef int32_t s32;
typedef int64_t limb;

typedef struct {
	u8 data[64];
	u32 datalen;
	u64 bitlen;
	u32 state[8];
} SHA256_CTX;


void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const u8 data[], size_t len);
void sha256_final(SHA256_CTX *ctx, u8 hash[]);

int sha256(const u8 src[],size_t srcLen,u8 hash[],size_t hashLen);

int generateSalt(u8 salt[],size_t len);

int sha256_salt(const u8 src[],size_t srcLen,u8 hash[],size_t hashLen,const u8 salt[],size_t saltLen);
#endif /* SHA256_H */

