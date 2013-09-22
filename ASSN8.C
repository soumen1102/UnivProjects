// to display sine curve on the screen
#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
int x=0,x1=40,y=1;
float z;
clrscr();
while(1)
{
textcolor(LIGHTRED);
z=sin(x);
z=z*5;
x1=x1+z;
gotoxy(x1,y);
cprintf(".");
textcolor(LIGHTGRAY);
gotoxy(40,y);
cprintf("|");
delay(300);
x1=40;
y++;
if(y==25)
exit();
x=x+7;
}
	getchar();
	system("cls");
}
