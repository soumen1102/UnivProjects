#include<stdio.h>
#include<conio.h>
void layout(int x1,int y1,int x2,int y2,int ccb,int cct);
void main()
{
delay(100);
clrscr();
layout(1,1,79,25,2,3);
delay(1000);
layout(10,10,20,20,4,12);
layout(5,5,35,7,5,6);
gotoxy(6,6);
textcolor(WHITE);
getchar();
}
void layout(int x1,int y1,int x2,int y2,int ccb,int cct)
{
int i,j;
window(x1,y1,x2,y2);
/*textbackground(ccb);
for(i=x1;i<=x2;i++)
 for(j=y1;j<=y2;j++)
     {
     gotoxy(i,j);
     cprintf(" ");
     }*/
textmode(3);
textcolor(cct);
gotoxy(x1,y1);
cprintf("%c",201);
gotoxy(x1,y2);
cprintf("%c",200);
gotoxy(x2,y1);
cprintf("%c",187);
gotoxy(x2,y2);
cprintf("%c",188);
for(i=x1+1;i<x2;i++)
{
gotoxy(i,y1);
cprintf("%c",205);
}
for(i=x1+1;i<x2;i++)
{
gotoxy(i,y2);
cprintf("%c",205);
}
for(i=y1+1;i<y2;i++)
{
gotoxy(x1,i);
cprintf("%c",186);
gotoxy(x2,i);
cprintf("%c",186);
}
}