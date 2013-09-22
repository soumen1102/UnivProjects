#include<conio.h>
void main()

{
int x,y;
clrscr();
while(!kbhit())
{

x=rand() % 70;
y=rand() % 23;
textbackground(BLACK);
gotoxy(x,y);
textcolor(YELLOW);
cprintf("*");
delay(100);
textcolor(BLACK);
gotoxy(x,y);
cprintf("*");
}
}