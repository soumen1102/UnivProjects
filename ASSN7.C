#include<conio.h>
#include<stdio.h>
void main()
{
int n1,n2,*n,temp,i=0,t1;
scanf("%d%d",&n1,&n2);
if(n1>n2)
{
t1=n1;
n1=n2;
}
else
t1=n2;
while(temp!=0)
{
*n=n1;
printf("%d",*n);
temp=t1%n1;
t1=n1;
n1=temp;
n++;
i++;
}
//while(i>0)
//{
printf(" %d ",*(n-1));
//n--;
//i--;
//}
while(!kbhit());
}