#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
int hh,mm,ss;
struct time t;
clrscr();
textcolor(YELLOW);
textbackground(LIGHTMAGENTA);
while(!kbhit())
{
 gettime(&t);
 gotoxy(35,13);
 delay(500);
 cprintf("%2d:%02d:%02d",t.ti_hour,t.ti_min,t.ti_sec);
 }
system("cls");

}
