SHARED MEMORY
SERVER.C
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
char c;
int shmid,i;
key_t key;
char *shm,*s;
key=5700;
shmid=shmget(key,27,IPC_CREAT|0666);
shm=shmat(shmid,NULL,0);
printf("Message from client is:%s\n",shm);
sleep(1);
char *str="In Ibrahimbagh";
printf("Message sent to client\n");
strcpy(shm,str);
exit(0);
}
CLIENT.C
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
char c;
int shmid;
key_t key;
char *shm,*s;
key=5700;
shmid=shmget(key,27,IPC_CREAT|0666);
shm=shmat(shmid,NULL,0);
char *buff="where is vasavi college?";
strcpy(shm,buff);
printf("Message sent to server\n");
sleep(5);
printf("Reply is:%s\n",shm);
}

