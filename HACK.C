#include<stdio.h>
#include<dos.h>
void main()
{
FILE *fp;
char ch;
system("a:");
fp=fopen("jba.rtf","r+");
while(!kbhit())
{
ch=getc(fp);
printf("%c \t%d  %s\n",ch,ch,ch*ch);
delay(50);
}
fclose(fp);
}
