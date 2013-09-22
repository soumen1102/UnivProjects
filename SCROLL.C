#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<malloc.h>
void main()
{
char *arr;
char temp;
int i=0,t=0,p=1;
clrscr();
printf("enter the text you wish to scroll: ");
while((*arr=getchar())!='\n')
{
arr++;
t++;
}
*arr=NULL;
while(t>=1)
{
arr--;
t--;
}
//arr--;
while(!kbhit())
{
p=rand()%15;
textcolor(p);
gotoxy(20,12);
cprintf("%s",arr);
temp=arr[0];
i=0;
while(arr[i]!=NULL)
{
arr[i]=arr[i+1];
i++;
}
arr[i-1]=temp;
delay(200);
/*gotoxy(20,12);
cprintf("%s",*arr);*/
}
}