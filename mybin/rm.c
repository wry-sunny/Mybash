#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
/*
void error_quit(const char *msg)
{
    perror(msg);
    exit(-1);
}


void change_path(const char *path)
{
    printf("Leave %s Successed . . .\n",getcwd(NULL,0));


    if(chdir(path)==-1)
        error_quit("chdir");


    printf("Entry %s Successed . . .\n",getcwd(NULL,0));
}


void rm_dir(const char *path)
{
    DIR *dir;
    struct dirent *dirp;
    struct stat buf;
    char *p=getcwd(NULL,0);


    if((dir=opendir(path))==NULL)
        error_quit("OpenDir");


    change_path(path);


    while(dirp=readdir(dir))
    {
        if((strcmp(dirp->d_name,".")==0) || (strcmp(dirp->d_name,"..")==0))
            continue;


        if(stat(dirp->d_name,&buf)==-1)
            error_quit("stat");


        if(S_ISDIR(buf.st_mode))
        {
            rm_dir(dirp->d_name);
        if(rmdir(dirp->d_name)==-1)
                error_quit("rmdir");
            printf("rm %s Successed . . .\n",dirp->d_name);
            continue;
        }


        if(remove(dirp->d_name)==-1)
            error_quit("remove");


        printf("rm %s Successed . . .\n",dirp->d_name);
    }


    closedir(dir);
    change_path(p);


    if(rmdir(path)==-1)
        error_quit("rmdir");


    printf("rm %s Successed . . .\n",path);
}

*/

int main(int argc,char *argv[])
{
    if(argc == 2)
    {
        if(unlink(argv[1]) != 0)
        {
            perror("unlink");
            exit(-1);
        }
    }
    else
    {
           //rm_dir(argv[1]);
    }

    exit(0);
}
