#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <assert.h>
/*d_type：4表示为目录，8表示为文件

d_reclen：16表示子目录或文件，24表示非子目录

d_name：目录或文件的名称
*/
int main()
{
    DIR *dp = opendir(".");
    struct stat st;

    if(dp == NULL)
    {
        fprintf(stderr,"cannot open directory:%s\n",dp);
        return;
    }

    struct dirent *entry = NULL;
    while((entry = readdir(dp)))
    {
        if((entry->d_type == 4||entry->d_type == 8)&&entry->d_name[0]!='.')
        {
            stat(entry->d_name,&st);
            if(S_ISDIR(st.st_mode))
            {
            printf("\e[1;34m %s   \033[0m ",entry->d_name); 
            }
            else if(st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
            {
            printf("\e[1;32m %s   \033[0m ",entry->d_name); 
            }
            else
            {
                printf("%s  ",entry->d_name);
            }
        }
    }
    closedir(dp);
    printf("\n");
    exit(0);
}
