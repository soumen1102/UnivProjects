#include<stdio.h>
#include<conio.h>
void tellsav(void);
void tellcur(void);
void layout(int x1,int y1,int x2,int y2,int ccb,int cct);

void main()
{
  char options[10][40]={
			"SAVINGS ACCOUNT",
			"CURRENT ACCOUNT",
			"               ",
			"               ",
			"               "
		       };

  int key=0,y=7,opt=0;


	 layout(25,5,55,22,15,15);

	 gotoxy(26,7);
	 cprintf("%s",options[0]);

	 gotoxy(26,8);
	 cprintf("%s",options[1]);

	 gotoxy(26,9);
	 cprintf("%s",options[2]);

	 gotoxy(26,10);
	 cprintf("%s",options[3]);

	 gotoxy(26,11);
	 cprintf("%s",options[4]);

	 gotoxy(26,y);
	 textbackground(7);
	 cprintf("%s",options[opt]);


	 gotoxy(65,22);
	 textcolor(8);
	 textbackground(RED);
	 cprintf(" EXIT ");
	 textcolor(15);

      while(1)
      {
       key=getch();

       if(key==13)
       {
	 if(opt==0)
	 {
	  tellsav();
	 }
	 if(opt==1)
	 {
	 tellcur();
	 }
       }

       if(key==72)
	  {
	   gotoxy(26,y);
	   textbackground(BLACK);
	   cprintf("%s",options[opt]);
	   opt--;
	   y--;
	   if(opt<0)
	   {
	   opt=1;
	   y=8;
	   }
	   }

	  if(key==80)
	  {
	   gotoxy(26,y);
	   textbackground(BLACK);
	   cprintf("%s",options[opt]);
	   opt++;
	   y++;
	   if(opt>1)
	   {
	   opt=0;
	   y=7;
	   }
	   }

	   if(key==9)
	   {
	   gotoxy(26,y);
	   textbackground(BLACK);
	   cprintf("%s",options[opt]);
	   gotoxy(65,22);
	   textbackground(7);
	   cprintf(" EXIT ");
	   key=getch();
	   gotoxy(65,22);
	   textbackground(RED);
	   cprintf(" EXIT ");
	   if(key==13)
	    return(0);
	   }

	 gotoxy(26,y);
	 textbackground(7);
	 cprintf("%s",options[opt]);
      }
}


void layout(int x1,int y1,int x2,int y2,int ccb,int cct)
{
int i,j;
window(x1,y1,x2,y2);
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

void tellsav(void)
{
    int i,j;

   layout(3,4,77,24,15,15);

   for(i=4;i<77;i++)
     for(j=5;j<24;j++)
     {
      gotoxy(i,j);
      cprintf(" ");
     }
   layout(5,5,40,7,15,15);
   gotoxy(6,6);
   cprintf("SAVINGS ACCOUNT NO: ");
   getchar();
}

void tellcur(void)
{
    int i,j;

   layout(3,4,77,24,15,15);

   for(i=4;i<77;i++)
     for(j=5;j<24;j++)
     {
      gotoxy(i,j);
      cprintf(" ");
     }
   layout(5,5,40,7,15,15);
   gotoxy(6,6);
   cprintf("CURRENT ACCOUNT NO: ");
   getchar();
}
