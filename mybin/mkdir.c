#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("mkdir error\n");
    }

    if(mkdir(argv[1],0770) != 0)
    {
        perror("mkdir");
        exit(-1);
    }
    exit(0);
}
