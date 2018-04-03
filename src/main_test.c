/**
 * Created by yzwuestc on 2018/4/2.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sha256.h"

int
main(int argc, char **argv)
{
    /**
    struct timespec time1 = {0, 0};
    clock_gettime(CLOCK_REALTIME, &time1);
    printf("CLOCK_REALTIME: %d, %d\n", time1.tv_sec, time1.tv_nsec);
    clock_gettime(CLOCK_MONOTONIC, &time1);
    printf("CLOCK_MONOTONIC: %d, %d\n", time1.tv_sec, time1.tv_nsec);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    printf("CLOCK_PROCESS_CPUTIME_ID: %d, %d\n", time1.tv_sec, time1.tv_nsec);
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time1);
    printf("CLOCK_THREAD_CPUTIME_ID: %d, %d\n", time1.tv_sec, time1.tv_nsec);
    printf("%d\n", time(NULL));
    sleep(1);
    **/

    printf("start test sha256\n");

    u8 out[SHA256_BLOCK_SIZE*2+1];
    while(1) {
        printf("please input a string:\n");
        u8 in[100];
        scanf("%s", in);
        if(strcmp("next",in)==0){
            break;
        }
        printf("in  string:%s\n", in);
        int inLen = strlen(in);
        printf("in     len:%d\n", inLen);
        sha256(in, inLen, out, sizeof(out)-1);
        printf("out string:%s\n", out);
        printf("out    len:%d\n", strlen(out));
        u8 salt[SHA256_SALT_SIZE+1]={0};
        generateSalt(salt, sizeof(salt)-1);
        printf("salt string:%s\n",salt);
        printf("salt    len:%d\n",strlen(salt));
        sha256_salt(in,inLen,out,sizeof(out)-1,salt,sizeof(salt)-1);
        printf("out with salt string:%s\n",out);
        printf("out with salt    len:%d\n",strlen(out));
    }
    printf("start test spend time of 20000 sha256\n");
    int i =0;
    struct timespec start = {0, 0};
    u8 testSrc[15]="sha256seed";
    u8 testSalt[SHA256_SALT_SIZE+1]={0};
    generateSalt(testSalt, sizeof(testSalt)-1);
    clock_gettime(CLOCK_MONOTONIC, &start);
    u8 testOut[SHA256_BLOCK_SIZE*2];
    for(i;i<20000;i++){
        sha256_salt(testSrc, strlen(testSrc),testOut,strlen(testOut),testSalt,strlen(testSalt));
    }
    struct timespec end = {0, 0};
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("spend time:%dns\n",end.tv_nsec-start.tv_nsec);
    return 0;
}