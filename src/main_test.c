/**
 * Created by yzwuestc on 2018/4/2.
 * */

#include "../config.h"
#include <stdio.h>
#include <stdlib.h>
#include "sha256.h"


int
main(int argc, char **argv)
{
    printf("hello world\n");
    
    return 0;
}



static void
hmac_final(SHA256_CTX *ctx, const u8 *key, u8 *hash)
{
    int i;
    u8 pad[SHA256_BLOCK_SIZE];
    sha256_final(ctx, hash);
    sha256_init(ctx);
    for (i = 0; i < SHA256_BLOCK_SIZE; i++)
        pad[i] = key[i] ^ 0x5cU;
    sha256_update(ctx, pad, sizeof(pad));
    sha256_update(ctx, hash, SHA256_BLOCK_SIZE);
    sha256_final(ctx, hash);
}
