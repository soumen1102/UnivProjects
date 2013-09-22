//digital clock using system time
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
void main()
{
int hh,x=2,mm,ss,y=12,flag=0;
struct time t;
system("cls");
clrscr();
textcolor(YELLOW);
//textbackground(LIGHTMAGENTA);
//x=rand() % 65;
//y=rand() % 25;

while(!kbhit())
{
 //x=rand() % 65;
 //y=rand() % 25;
 gettime(&t);
 gotoxy(x,y);
 cprintf("%2d:%02d:%02d",t.ti_hour,t.ti_min,t.ti_sec);
 delay(30);
 //clrscr();
 //y=sqrt(sqrt(x*x-25));
 if(x<72 && flag==0)
 {
 x++;
 }
 if(x==72)
 flag=1;
 if(flag==1 && x>2)
 {
 x--;
 }
 if(x==2)
 flag=0;


 /*x++;
 y++;
 if(x==75)
 {
 x--;
 y++;
 if(y==25)
 y--;
 }
 if(y==25)
 {
 y--;
 x++;
 if(x==75)
 x--;
 }
 */
 }
 getch();
system("cls");

}
