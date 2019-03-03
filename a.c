#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>

int main(int argc,char* argv[],char* envp[])
{
   char* s = NULL;
   int n = 0;
   
   pid_t pid = fork();
   assert(pid != -1);
  
   if(pid == 0)
   {
    s = "child";
    n = 4;
   }
   else
   {
    s = "parent";
    n = 7; 
   // int val = 0;
   // int id =  wait(&val);
   // printf("id=%d,val=%d\n",id,val);
   }
   int i = 0;
   for(;i < n;i++)
   {
    printf("s=%s\n",s);
    sleep(1);
   }
   exit(3);
}
