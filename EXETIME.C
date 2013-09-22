//digital clock using system time
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
long int hh,mm,ss,y=13;
struct time t;
clrscr();
textcolor(YELLOW);
textbackground(LIGHTMAGENTA);

 gettime(&t);
 gotoxy(35,12);
 cprintf("%2d:%02d:%02d::%02d",t.ti_hour,t.ti_min,t.ti_sec,t.ti_hund);
 for (hh=0;hh<1000000;hh++);
 printf("the difference is the time taken to count 10000000 instruction");
 gettime(&t);
 gotoxy(35,13);
 cprintf("%2d:%02d:%02d::%02d",t.ti_hour,t.ti_min,t.ti_sec,t.ti_hund);


 getch();
system("cls");

}
