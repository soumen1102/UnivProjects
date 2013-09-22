#include<malloc.h>
#include<stdio.h>
main()
{
char *s;
int i=0;
s=malloc(200);
gets(s);
while(*s!=0)
{
if(*s==' ' && *(s+1)==' ')
*(s+1)=*(s+2);
s++;
i++;
}
while(i>0)
{
s--;
i--;
}
printf("%s",s);
}

