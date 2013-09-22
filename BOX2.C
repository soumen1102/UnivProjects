#include<stdio.h>
#include<conio.h>
void layout(int x1,int y1,int x2,int y2,int ccb,int cct);
void main()
{
clrscr();
layout(1,1,79,25,15,15);
layout(10,10,20,20,12,11);
layout(5,5,35,7,5,5);
layout(25,5,33,12,9,5);
layout(45,15,55,17,9,4);
gotoxy(6,6);
textcolor(WHITE);
getchar();
}
void layout(int x1,int y1,int x2,int y2,int ccb,int cct)
{
int i,j;
window(x1,y1,x2,y2);
textbackground(ccb);
for(i=x1;i<=x2;i++)
 for(j=y1;j<=y2;j++)
     {
     gotoxy(i,j);
     cprintf(" ");
     }
     textmode(3);
textcolor(cct);
gotoxy(x1,y1);
cprintf("%c",218);
gotoxy(x1,y2);
cprintf("%c",192);
gotoxy(x2,y1);
cprintf("%c",191);
gotoxy(x2,y2);
cprintf("%c",217);
for(i=x1+1;i<x2;i++)
{
gotoxy(i,y1);
cprintf("%c",196);
}
for(i=x1+1;i<x2;i++)
{
gotoxy(i,y2);
cprintf("%c",196);
}
for(i=y1+1;i<y2;i++)
{
gotoxy(x1,i);
cprintf("%c",179);
gotoxy(x2,i);
cprintf("%c",179);
}
}