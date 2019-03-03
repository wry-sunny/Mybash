#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include<pwd.h>
#include<sys/types.h>
#define PATH "/home/ws/cy1706/jiaoben/mybin/"
#define MAX 10
void printf_sys_info()
{
    char buff[128] = {0};
    int my_uid = getuid();
    struct passwd *my_info;
    my_info = getpwuid(my_uid);

    char hostname[128] = {0};
    gethostname(hostname,128);

    char cur_dir[128] = {0};
    getcwd(cur_dir,128);

    char *last_name = "/";
    char *s = strtok(cur_dir,"/");
    while(s != NULL)
    {
        last_name = s;
        s = strtok(NULL,"/");   
    }
    char *user = "$";
    if( my_uid == 0)
    {
        user = "#";
    }
    printf("[%s@ %s %s]%s",my_info->pw_name,hostname,last_name,user);
    fflush(stdout);
}
int main(int argc,char *argv[],char*envp[])
{
    while(1)
    {
        char buff[128]={0};
        printf_sys_info();
        fgets(buff,128,stdin);
        buff[strlen(buff)-1]=0;
        char *myargv[MAX] = {0};
        char *s = strtok(buff," ");
        if(s == NULL)
        {
            continue;
        }
        myargv[0] = s;
        int i = 1;

        while((s = strtok(NULL," ")) != NULL)
        {
            myargv[i++] = s;
        }

        if(strncmp(myargv[0],"exit",4)==0)
        {
            break;
        }

        else if(strncmp(myargv[0],"cd",2)==0)
        {
            chdir(myargv[1]);
            continue;
        }
        pid_t pid = fork();
        assert(pid != -1);
        if(pid == 0)
        {
            char path[256] = {0};
            if(strncmp(myargv[0],"./",2) && strncmp(myargv[0],"/",1))
            {
                strcpy(path,PATH);
            }
            strcat(path,myargv[0]);
            execv(path,myargv);
            perror("exec error");
            exit(0);
        }
        wait(NULL);

    }
    exit(0);
}
