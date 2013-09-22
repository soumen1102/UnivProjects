#include<stdio.h>
#include<dos.h>
#include<conio.h>
//int getkey(void);
void main()
{
int ch;
clrscr();
//textbaxkground(BLUE);
//for(i=
textcolor(LIGHTGREEN);
cprintf("press function keys F1 - F10 and play the mini piano \a ");
while(1)
{
fflush(stdin);
ch=getch();
switch(ch)
{
case 59:
{
sound(140);
delay(40);
nosound();
break;
}
case 60:
{
sound(256);
delay(40);
nosound();
break;
}
case 61:
{
sound(270);
delay(40);
nosound();
break;
}
case 62:
{
sound(288);
delay(40);
nosound();
break;
}
case 63:
{
sound(300);
delay(40);
nosound();
break;
}
case 64:
{
sound(320);
delay(40);
nosound();
break;
}
case 65:
{
sound(337.5);
delay(40);
nosound();
break;
}
case 66:
{
sound(360);
delay(40);
nosound();
break;
}
case  67:
{
sound(384);
delay(40);
nosound();
break;
}
case  68:
{
sound(400);
delay(40);
nosound();
break;
}
case 13:
{
nosound();
exit();
}
default :
break;
}
}
}
/*int getkey(void)
		{
		    union REGS i,o;
		    while(!kbhit())
		    {
		    fflush(stdin);
		    i.h.ah=0;
		    int86(22,&i,&o);
		    return(o.h.ah);
		    }
		}
  */

