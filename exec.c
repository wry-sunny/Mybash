#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<assert.h>

int main(int argc,char* argv[],char*envp[])
{
    printf("exec pid = %d\n",getpid());

    pid_t pid = fork();
    assert(pid != -1);
/*
    if(pid == 0)
    {
        char* myargv[] = {"b","hello","abc","123",(char*)0};
        char* myenvp[] = {"MYSTR=hello",,"VAL=100",(char*)0};
     // execl("./b","b","hello","abc","123",(char*)0);
        execve("./b",myargv,myenvp);
        perror("execl error");
    }
    */
/*
    if(pid == 0)
    {
        execl("/bin/ps","-f",(char*)0);
        perror("execl error");
        exit(0);
    }

    wait(NULL);
    printf("main error\n");
*/
    
   // execl("/bin/ps","ps","-ef",(char*)0);

    execlp("ps","ps","-f",(char*)0);
   
   // execlp("/bin/ps","ps","-f",(char*)0,envp);
   
  //  char* myargv[] = {"ps","-f",(char*)0};
  
   // execv("/bin/ps",myargv);
  
   // execvp("ps",myargv);
   
    execve("/bin/ps",myargv,envp);

    if(errno = ENOENT)
    {
        perror("execl error");
    }
    
    /*
    char * ls_argv[] = {"main", "-a", NULL};
    if(fork() == 0)
    {
       // if(execv("/bin/ls", ls_argv) < 0)
        if(execv("/home/ws/cy1706/jiaobeng/main", ls_argv) < 0)
        {
            perror("execl error");
        }
    }
    */
   exit(0);
}
