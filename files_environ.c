FILES PROGRAMS
PROG1.C
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
//#include<sys/types.h>
int main(int argc,char **argv)
{
        int fd1,fd2,n;
        char buff[20],buff2[50];
        fd1=open(argv[1],O_RDONLY);
         n=read(fd1,buff,20);
        fd2=open(argv[2],O_CREAT|O_RDWR,0777);
        write(fd2,buff,n);
        close(fd1);
        close(fd2);
        return 0;
}


PROG2.C
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
        int fd;
        struct stat fptr;
        if(stat("/home/it19121/oslab/d2.txt",&fptr)==0)
        {
                printf("File size is:%ld\n",fptr.st_size);
                printf("Device ID is:%ld\n",fptr.st_dev);
                printf("Inode Number is:%ld\n",fptr.st_ino);
                printf("Number of blocks is:%ld\n",fptr.st_blocks);
                printf("Block size is:%ld\n",fptr.st_blksize);
                printf("Mode is:%o\n",fptr.st_mode);
        }
}

ENVIRONMENT PROGRAMS
PROG3.C
#include<stdio.h>
int main(int argc,char *arv[])
{
        extern char **environ;
        int i;
        for(i=0;environ[i]!=(char *)0;i++)
        {
                printf("%s\n",environ[i]);
        }
        return 0;
}

PROG4EXECV.C
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char **argv)
{
printf("Before execv\n");
execv("/bin/date",argv);
printf("After execv\n");
}



PROG5EXECL.C
