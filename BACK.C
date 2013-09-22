#include<stdio.h>
#include<dos.h>
#include<conio.h>
void clock(void);
void main()
{
int i,x=15,y=5,s;
char ch;
clrscr();
while(1)
{
s=kbhit();
if(s==0)
continue;
else
{
textcolor(WHITE);
textbackground(BLUE);
gotoxy(x,y);
ch=getche();
if(ch==EOF)
exit();
clock();
s=0;
x++;
if(x==79)
{
x=15;
y++;
}
}

}
}

void clock(void)
{
int hh,mm,ss;
struct time t;
clrscr();
textcolor(YELLOW);
textbackground(LIGHTMAGENTA);
//while(!kbhit())
//{
 gettime(&t);
 gotoxy(70,1);
 cprintf("%2d:%02d:%02d",t.ti_hour,t.ti_min,t.ti_sec);

// }
return(0);
}