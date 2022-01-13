FORK PROGRAMS

REVERSE.C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char str[20],a[20];
int k=0,i,pid,flag;
printf("Enter a string:");
scanf("%s",str);
pid=fork();
if(pid==0)
{
for(i=strlen(str)-1;i>=0;i--)
{
a[k]=str[i];
k++;
}
a[k]='\0';
printf("The reverse of given string is:%s\n",a);
}
else
{
wait();
}
}
PALINDROME.C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//char str[20],a[20];
int main()
{
char str[20],a[20];
int k=0,i,pid,flag;
printf("Enter a string:");
scanf("%s",str);
//strcpy(str,"heh");
pid=fork();
if(pid==0)
{
sleep(5);
for(i=strlen(str)-1;i>=0;i--)
{
a[k]=str[i];
k++;
}
a[k]='\0';
printf("%s",str);
printf("%s",a);
if(strcmp(a,str)==0)
{
flag=1;
}
else
{
flag=0;
}
if(flag==1)
{
printf("\nGIVEN STRING IS A PALINDROME\n");
}
else
{
printf("\nGIVEN STRING IS NOT A PALINDROME\n");
}
}
else
{
//printf("Enter a string:");
//scanf("%s",str);
//printf("%s",str);
wait();
}
}
SORT.C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int binarysearch(int a[],int n,int key)
{
int low=0,mid;
int high=n-1;
while(low<=high)
{
mid=(low+high)/2;
if(a[mid]==key)
{
return mid;
}
else if(a[mid]<key)
{
low=mid+1;
}
else
{
high=mid-1;
}
}
return -1;
}
void sort(int a[],int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
}
int main()
{
int n,i,key,pid;
printf("Enter array size:");
scanf("%d",&n);
int a[n];
printf("\nEnter array elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
pid=fork();
if(pid==0)
{
sort(a,n);
printf("\nAfter Sorting:");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
else
{
wait();
printf("Enter key element:");
scanf("%d",&key);
int res=binarysearch(a,n,key);
if(res==-1)
{
printf("NOT FOUND\n");
}
else
{
printf("FOUND AT INDEX %d\n",res);
}
}
}

FORK_PROG1.C
#include<stdio.h>
#include<sys/types.h>
int main()
{
        int id,childid;
        id=getpid();
        if(childid=fork()>0)
        {
                printf("\n I am in the parent process %d",id);
                printf("\n I am in the parent process %d",getpid());
                printf("\n I am in the parent process %d\n",getppid());
        }
        else
        {
                printf("\n I am in the child process %d",id);
                printf("\n I am in the child process %d",getpid());
                printf("\n I am in the child process %d\n",getppid());
        }
}

FORK_PROG2.C
#include<stdio.h>
#include<sys/types.h>
void main()
{
        int pid,f=1,n,sum=0,rem;
        printf("Enter a number:\n");
        scanf("%d",&n);
        pid=fork();
        printf("\n My pid now is %d",pid);
        if(pid==0)
        {
                printf("\n I am in child process");
                while(n>0)
                {
                        rem=n%10;
                        sum=sum+rem;
                        n=n/10;

                }
                printf("\nSum of digits is :%d\n",sum);
        }
        else
        {
                wait();
                printf("\n Now I am in the parent process");
                //printf("\n Sum of digits is:%d\n",sum);
        }
}
