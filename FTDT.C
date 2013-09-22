#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<tellar.h>
void layout(int x1,int y1,int x2,int y2,int ccb,int cct);
main()
{
    char options[10][40]={"ADMINISTRATOR         ",
			  "TELLAR                ",
			  "SAVINGS ACCOUNT       ",
			  "CURRENT ACCOUNT       ",
			  "DRAFTS AND DEPOSITS   "
			 };
    static int opt=2,y=9,key=0;
	clrscr();
	system("cls");
	 layout(1,1,79,24,15,15);

	      layout(1,1,79,3,15,15);
	      gotoxy(30,2);
	      cprintf("I C I C I    B A N K");

	      gotoxy(1,3);
	      cprintf("%c",195);

	      gotoxy(79,3);
	      cprintf("%c",180);

	 layout(25,5,55,22,15,15);

	 redraw:

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

	 if(key==72)
	  {
	   gotoxy(26,y);
	   textbackground(BLACK);
	   cprintf("%s",options[opt]);
	   opt--;
	   y--;
	   if(opt<0)
	   {
	   opt=4;
	   y=11;
	   }
	   }

	  if(key==80)
	  {
	   gotoxy(26,y);
	   textbackground(BLACK);
	   cprintf("%s",options[opt]);
	   opt++;
	   y++;
	   if(opt>4)
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
	   {
	    system("cls");
	    exit(1);
	   }
	   }

	 if(key==13)
	 {
	  if(opt==1)
	  {
	  tellar();
	  textbackground(0);
	  goto redraw;
	  }
	 }

	 gotoxy(26,y);
	 textbackground(7);
	 cprintf("%s",options[opt]);
       }

}
