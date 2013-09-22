#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
FILE *even,*odd;
char c;
int i,ch,flag=0;
even=fopen("even.num","w");
odd=fopen("odd.num","w");
for(i=100;i<=200;i++)
{
if(i%2==0)
{
fflush(stdout);
fputc(i,even);
printf("%d",i);
delay(40);
}
else
fputc(i,odd);
}
fclose(even);
fclose(odd);
even=fopen("even.num","a+");
odd=fopen("odd.num","a+");
clrscr();
i=0;
rewind(even);
while(i<50)
{
ch=fgetc(even);
if(ch=='26' && flag==0)
{
printf(" 26 ");
flag=1;
i++;
continue;
}
printf(" %d ",ch);
i++;
}
printf("\n\n\n\a");
while((ch=fgetc(odd))!=EOF)
printf(" %d ",ch);
fclose(even);
fclose(odd);
getch();
}
