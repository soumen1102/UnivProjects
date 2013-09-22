#include<malloc.h>
void main()
{
char *s;
char *a,*t,*b;
int flag=0,ti;
s=malloc(200);
gets(s);
a=s;
t=s+strlen(s)-1;
b=t;
ti=strlen(s);
ti=ti/2;
while(ti!=0)
{
if(*a==*b)
{
b--;
a++;
ti--;
continue;
}
else
{
flag=1;
b--;
a++;
break;
}
}
if(flag==1)
printf(" %s ...... is not a pallindrome ",s);
else
printf(" %s ...... is a pallindrome ",s);
}


