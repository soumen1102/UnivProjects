#include<stdio.h>
#include<conio.h>
#include<dos.h>
int getkey(void);
void main()
{
int h1=0,h2=0,m1=0,m2=0,s1=0,s2=0,x=22,k=0;//time : h1h2:m1m2:s1s2
char *n="DIGITAL_CLOCK_:_ENTER_THE_CURRENT_TIME";
clrscr();
gotoxy(x,2);
textcolor(LIGHTGREEN);
while(*n!=NULL)
{
       if(*n=='_')
       *n=' ';
	cprintf("%c",*n);
	n++;
	x++;
	sound(250);
	delay(75);
	nosound();
}

  while(1)
  {
  gotoxy(35,5);
  cprintf("%d",h1);
  gotoxy(36,5);
  cprintf("%d",h2);
  gotoxy(37,5);
  cprintf(":%d",m1);
  gotoxy(39,5);
  cprintf("%d",m2);
  gotoxy(35,5);
  k=getkey();
  if(k==28)
  break;
  if(k==77)
  {
  gotoxy(36,5);
  textcolor(BLINK);
  cprintf("%d",h2);
  }
  }
textcolor(YELLOW);
clrscr();
	while(!kbhit())
	{
	gotoxy(35,12);
	cprintf("%d%d:%d%d:%d%d",h1,h2,m1,m2,s1,s2);
	delay(1000);
	s2++;
	if(s2==10)
	{
	s2=0;
	s1++;
	}
	if(s1==6)
	{
	s1=0;
	m2++;
	}
	if(m2==10)
	{
	m2=0;
	m1++;
	}
	if(m1==6)
	{
	m1=0;
	h2++;
	}
	if(h2==10)
	{
	h2=0;
	h1++;
	}
	if(h1==2 && h2==4)
	{
	h1=0;
	h2=0;
	}
	}
}
		int getkey(void)
		{
		    union REGS i,o;
		    while(!kbhit())
		    {
		    i.h.ah=0;
		    int86(22,&i,&o);
		    return(o.h.ah);
		    }
		}
