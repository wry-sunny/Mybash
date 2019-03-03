#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>

int main()
{
   char* s = (char *)malloc(1024*1024*1024*2);
   assert(s != NULL);
    memset(s,0,1024*1024*1024*2);
    printf("over\n");
   exit(0);
}
