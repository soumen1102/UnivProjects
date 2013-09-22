#include<stdio.h>

void main()
{
int ch=0;
fflush(stdin);
system("cls");
clrscr();
while(1)
{
fflush(stdin);
ch=getche();
printf("\t%d",ch);
if(ch==13)
break;
continue;
}
}