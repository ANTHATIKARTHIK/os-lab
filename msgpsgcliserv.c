MESSAGE PASSING
MESG1.H
#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<sys/msg.h>

#define MKEY1 4164L
#define MKEY2 4266L
#define PERMS 0666
typedef struct
{
        long mtype;
        char mdata[50];
}
mesg;

MSGPASSING_CLIENT.C
#include<stdlib.h>
#include "mesg1.h"
mesg msg1,msg2;
main()
{
        int mq_id1,mq_id2;
        int n;
        if((mq_id1=msgget(MKEY1,PERMS|IPC_CREAT))<0)
        {
                printf("Client:error creating queue");
                exit(1);
        }
        if((mq_id2=msgget(MKEY2,PERMS|IPC_CREAT))<0)
 {
 printf("Client:error creating queue");
              exit(1);
 }
        msg1.mtype=10L;
        n=read(0,msg1.mdata,50);
        msg1.mdata[n]='\0';
        msgsnd(mq_id1,&msg1,50,0);
        msgrcv(mq_id2,&msg2,50,10L,0);
        write(1,msg2.mdata,50);
  }

MSGPASSING_SERVER.C
#include<stdlib.h>
#include "mesg1.h"
mesg msg;
main()
{
int mq_id1,mq_id2;
int n;
if( ( mq_id1=msgget(MKEY1,IPC_CREAT|0666) ) < 0)
{
                printf("Server:error openenig queue");
                exit(1);
}
msgrcv(mq_id1,&msg,50,10L,0);
if((mq_id2=msgget(MKEY2,IPC_CREAT|0666))<0)
{
                printf("sender:error creating queue");
                exit(1);
        }
          msgsnd(mq_id2,&msg,50,0);
}

