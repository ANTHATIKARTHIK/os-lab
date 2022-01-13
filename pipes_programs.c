PIPES PROGRAMS
PROG1.C
#include<stdio.h>
#include<stdlib.h>
main()
{
        int pipeid1[2],pipeid2[2],childid;
/* pipeid1 – Server*/
/* pipeid2 – Client*/

        if((pipe(pipeid1)<0)||pipe(pipeid2)<0)
        {
                printf(" Error in creating pipes ");
                exit(1);
        }

        if((childid=fork())>0) /* Create the client process using fork()*/
        {
                close(pipeid1[0]); /* Close write of Server*/
                close(pipeid2[1]); /* close read of Client*/
                client(pipeid2[0],pipeid1[1]);
                close(pipeid1[1]); /* Close read of Server*/
                close(pipeid2[0]); /* close write of Client*/

        }
        else
        {
                close(pipeid1[1]); /* Close write of Server*/
                close(pipeid2[0]); /* Close write of Server*/
                server(pipeid1[0],pipeid2[1]);
                close(pipeid1[0]); /* Close write of Server*/
close(pipeid2[1]); /* Close write of Server*/

        }
}
client(int readid, int writeid)
{
        char buff1[50],buff2[50];
        int n;
        n=read(0,buff1,50);
        write(writeid,buff1,n);
        read(readid,buff2,n);
        write(1, buff2,n);
}
server(int readid, int writeid)
{
        char buff3[50];
        int n;
        n=read(readid,buff3,50);
        write(writeid,buff3,n);
}


PROG2.C
#include<stdio.h>
#include<stdlib.h>
main()
{
int p1[2],p2[2],n,pid;
char buf1[100],buf2[100];
pipe(p1);
pipe(p2);
printf("\n readfds=%d %d\n",p1[0],p2[0]);
printf("\n writefds=%d %d\n",p1[1],p2[1]);
pid=fork();
if(pid==0)
{
close(p1[0]);
printf("\n CHILD PROCESS SENDING DATA\n");
write(p1[1],"where is Vasavi Engg College",100);
close(p2[1]);
read(p2[0],buf1,100);
printf(" reply from parent:%s\n",buf1);
sleep(2);
}
else
{
close(p1[1]);
printf("\n parent process receiving data\n");
n=read(p1[0],buf2,sizeof(buf2));
printf("\n data received from child through pipe:%s\n",buf2);
sleep(3);
close(p2[0]);
write(p2[1]," in Ibrahimbagh,Hyd",25);
printf("\n reply send\n");
}


PIPES_PALINDROME.C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag;
int main()
{
int pipefd1[2],pipefd2[2];
pipe(pipefd1);
pipe(pipefd2);
int pid;
pid=fork();
if(pid>0)
{
close(pipefd1[0]);
close(pipefd2[1]);
client(pipefd2[0],pipefd1[1]);
close(pipefd1[1]);
close(pipefd2[0]);
}
else
{
close(pipefd1[1]);
close(pipefd2[0]);
server(pipefd1[0],pipefd2[1]);
close(pipefd1[0]);
close(pipefd2[1]);
}
}
client(int readid,int writeid)
{
        char buff[10];
        int n,f;
        write(1,"Enter a string:",16);
        n=read(0,buff,10);
        write(writeid,buff,n);
        //sleep(1);
        read(readid,&f,2);
        if(f==1)
        {
        printf("\nPALINDROME");
        }
        else
        {
        printf("\nNOT A PALINDROME");
        }
}
server(int readid,int writeid)
{
        char str[10],a[10];
        int n;
        int i,k=0;
        read(readid,str,20);
        for(i=strlen(str)-2;i>=0;i--)
        {
        a[k]=str[i];
        k++;
        }
        a[k]='\n';
        printf("%s",str);
        printf("%s\n",a);
        if(strcmp(a,str)==0)
        {
        flag=1;
        }
        else
        {
        flag=0;
        }
        printf("Flag value is %d\n",flag);
        write(writeid,&flag,2);
}

