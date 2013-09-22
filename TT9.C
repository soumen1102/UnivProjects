#include<math.h>
int rec(int x,int y,int c);
main()
{
int x,y,c,sum;
printf("enter the value of a r and n:");
scanf(" %d %d %d",&x,&y,&c);
sum=rec(x,y,c);
printf("the sum is %d",sum);
}
int rec(int x,int y,int c)
{
static int sum=0;
int p,q;
c=c-1;
p=pow(y,c);
q=x*p;
sum=sum+q;
if(c>=1)
rec(x,y,c);
else
return(sum);
}
