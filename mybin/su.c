#include <unistd.h>  
#include <stdio.h>  
#include <string.h>  
#include <pwd.h>  
#include <stdlib.h>  
#include <assert.h>  
#include <shadow.h>  
#include <sys/types.h>  
#include <termios.h>  
int main(int argc, char *argv[])  
{  
    char *s = "root";  
    if (argc == 2)  
    {  
        s = argv[1];  
    }
                                          
    struct passwd *p = getpwnam(s);
    if (p == NULL)  
    {  
        perror("username error");  
    }
    /*  
    struct spwd *sp = getspnam(s);  
    if(sp == NULL)  
    {  
        perror("userpasswd error");  
        exit(0);  
    }  
    printf("input passwd:");  
    fflush(stdout);
    */  

    pid_t pid = fork();
    assert( pid != -1);
    if(pid == 0)
    {
        setenv("HOME",p->pw_dir,1);
        setgid(p->pw_gid);
        setuid(p->pw_uid);

        execl(p->pw_shell,p->pw_shell,(char *)0);
        perror("su execl error");
        exit(0);
    }

    wait(NULL);
    exit(0);
}
