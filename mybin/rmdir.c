#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        printf("rmdir error\n");
    }

    if(rmdir(argv[1]) != 0)
    {
        perror("rmdir");
        exit(-1);
    }
    exit(0);
}
