LARGEST.C
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main()
{
        int n,c;
        int fd1;
        fd1=open("l2.txt",O_RDONLY);
        char buff[10];
        int i,max=0,k;
        read(fd1,buff,10);
        char *token = strtok(buff," ");
        while(token != NULL){
                k = atoi(token);
                if(k>max) max = k;
                token = strtok(NULL," ");
        }
        printf("Maximum number is:%d\n",max);
        close(fd1);
}
