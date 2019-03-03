#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<assert.h>

int main()
{
    int fd = open("passwd",O_RDONLY);
    int fp = open("newpasswd",O_WRONLY|O_CREAT,0600);
    assert(fp != -1);
    char buff[128] = { 0 };
    int n = read(fd,buff,127);
     
    while(n>0)
    {
        write(fp,buff,n);
        n = read(fd,buff,127);
    }
    
    close(fp);
    close(fd);

    /*
    int fd = open("file.txt",O_RDONLY);
    char buff[128] = {0};

    int n = read(fd,buff,127);
    printf("n=%d,buff=%s\n",n,buff);
    close(fd);


   int fd = open("./file.txt",O_WRONLY|O_CREAT,0600);
   assert(fd != -1);

   write(fd,"hello world",11);

   printf("fd=%d\n",fd);

   close(fd);
   */

   exit(0);
}
