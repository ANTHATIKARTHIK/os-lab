THREADS
PROG1.C
#include<stdio.h>
#include<pthread.h>
void *msg(int n)
{
printf("%d\n",n);
}
int main(int argc,char **argv)
{
pthread_t tid;
int n=5;
printf("Creating a thread\n");
pthread_create(&tid,NULL,(void *)msg,(void*)n);
printf("Created thread:%d\n",tid);
pthread_join(tid,NULL);
return 0;
}

PROG2.C
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int counter=0;
void *functionC()
{
pthread_mutex_lock(&mutex1);
counter++;
printf("Counter Value:%d\n",counter);
pthread_mutex_unlock(&mutex1);
}
int main()
{
pthread_t threadid[10];
int i,j;
for(i=0;i<10;i++)
{
pthread_create(&threadid[i],NULL,(void*)functionC,NULL);
}
for(j=0;j<10;j++)
{
pthread_join(threadid[j],NULL);
}
printf("countervalue final is:%d",counter);
}

PROG3.C
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *functionC();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t mutex1;
int counter = 0;
main()
{
 int rc1, rc2;
 pthread_t thread1, thread2;
 /* Create independent threads each of which will execute functionC */
 if( (rc1=pthread_create( &thread1, NULL, functionC, NULL)) )
 {
 printf("Thread creation failed: %d\n", rc1);
 }
 if( (rc2=pthread_create( &thread2, NULL, functionC, NULL)))
 {
 printf("Thread creation failed: %d\n", rc2);
 }
 pthread_join( thread1, NULL);
 pthread_join( thread2, NULL);
 exit(0);
}
void *functionC()
{
 pthread_mutex_lock( &mutex1 );
 counter++;
 printf("Counter value: %d\n",counter);
 pthread_mutex_unlock( &mutex1 );
}


PROG4.C
#include <stdio.h>
#include <pthread.h>
#define NTHREADS 10
void *thread_function(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;
main()
{
 pthread_t thread_id[NTHREADS];
 int i, j;
 for(i=0; i < NTHREADS; i++)
 {
 pthread_create( &thread_id[i], NULL, thread_function, NULL );
 }
 for(j=0; j < NTHREADS; j++)
 {
 pthread_join( thread_id[j], NULL);
 }

 printf("Final counter value: %d\n", counter);
}
void *thread_function(void *dummyPtr)
{
 printf("Thread number %ld\n", pthread_self());
 pthread_mutex_lock( &mutex1 );
 counter++;
 pthread_mutex_unlock( &mutex1 );
}

PROG5.C
#include <stdio.h>
#include <pthread.h>

void printMsg(char* msg) {
        printf("%s\n", msg);
}

int main(int argc, char** argv) {
        pthread_t thrdID;

        printf("creating a new thread\n");
        pthread_create(&thrdID, NULL, (void*)printMsg, argv[1]);
        printf("created thread %d\n", thrdID);
        pthread_join(thrdID, NULL);
        return 0;
}

