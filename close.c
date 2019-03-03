#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<fcntl.h>

int main()
{
    int fd = open("file.txt",O_WRONLY|O_CREAT,0600);

    //int newfd = dup(fd);
    int newfd = dup2(fd,1);
    printf("fd=%d,newfd=%d\n",fd,newfd);
    fflush(stdout);
    write(newfd,"hello",5);

    close(newfd);
    close(fd);

    /*
    close(1);

    int fd = open("file.txt",O_WRONLY|O_CREAT,0600);
    printf("fd=%d\n",fd);
    fflush(stdout);

    write(fd,"hello",5);
    printf("main over\n");
    fflush(stdout);

    close(fd);
*/
   exit(0);
}
