#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>

int main(int argc,char* argv[],char* envp[])
{
   int i = 0;
   for(;i < 2;i++)
   {
    pid_t pid = fork();
    printf("A");
   
   }
   exit(0);
}
