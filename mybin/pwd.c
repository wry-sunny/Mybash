#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    char buff[128]={0};

    getcwd(buff,128);
    printf("mypwd:%s\n",buff);

    exit(0);

}
