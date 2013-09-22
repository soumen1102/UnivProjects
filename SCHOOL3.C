#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
int getkey(void);
void info(void);
int pp(int sheet[4][4],int move);

struct{
char player[20];
int moves1;
}mm;


int pp(int sheet[4][4],int move)
{
  FILE *fp;
   int i,j,x,y=6,x1=7,y1=3,q,f=3000,true=0,rt,sheet1[4][4]={ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,NULL} ;
   long int recsize;
		textcolor(LIGHTRED);

	for(i=0;i<4;i++)
	 {
	  x=30;
		for(j=0;j<4;j++)
		{
		  gotoxy(x,y);
		  if(sheet[i][j]==NULL)
		  textcolor(BLACK);
		 else
		  textcolor(LIGHTRED);
		  cprintf(" %d ",sheet[i][j]);
		  if(sheet[i][j]==sheet1[i][j])
		  true++;
		  x=x+5;
		}

	     y=y+2;
	     if(true==16)
	       {
		 clrscr();
		 for(q=0;q<=15;q++)
		 {
		 gotoxy(10,13);
		 textcolor(q);
		 cprintf(" CONGRATULATIONS  YOU HAVE COMPLETED THE PUZZEL IN %d MOVES ",move);
		 sound(f);
		 delay(600);
		 nosound();
		 f=f+40;
		  }
		  clrscr();
		  fp=fopen("game.rec","ab+");
		   if ( fp==NULL )
		    {
		      fp=fopen("game.rec","ab+");

			if(fp==NULL)
			 {
			   gotoxy(12,12);
			   textcolor(LIGHTGRAY);
			   cprintf("cannot open file .. sorry ");
			   exit();
			 }
		    }
		     recsize =sizeof(mm);
		     clrscr();
		     rewind(fp);
		     gotoxy(5,2);
		     textcolor(LIGHTGRAY);
		     cprintf(" PLAYER ");
		     gotoxy(20,2);
		     cprintf(" MOVES ");
		      while(fread(&mm,recsize,1,fp)==1)
		      {
			gotoxy(x1,y1);
			textcolor(BLUE);
			cprintf(" %s ",mm.player);
			gotoxy(x1+15,y1);
			cprintf(" %d ",mm.moves1);
			x1=7;
			y1++;
			if(y1==24)
			{
			printf("\n\t\t more ........");
			y1=3;
			getch();
			}
		       }
		      fseek(fp,0,SEEK_END);
		      gotoxy(1,1);
		      textcolor(CYAN);
		      cprintf(" enter your name : ");
		      cscanf("%s",mm.player);
		      mm.moves1=move;
		      fwrite(&mm,recsize,1,fp);
		      fclose(fp);
		      rt=1;
		      clrscr();
		      return(rt);
		  }

		}
	  return(0);
 }

void main()
{
int sheet[4][4]={ 1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,NULL},x,y=6,ch,xx,yy,posx,posy,i,j,temp,move=0,ex=0;
clrscr();
	for(i=0;i<=27;i++)
	  for(j=0;j<=80;j++)
	  {
	   gotoxy(j,i);
	   textbackground(RED);
	   cprintf("%c",176);
	  }
	   gotoxy(15,8);
	   textcolor(YELLOW);
	   cprintf(" NUMBER JUMBLE ");
	   gotoxy(15,10);
	   cprintf("developed by : SOUMEN MUKHERJEE ");
	   gotoxy(15,11);
	   cprintf(" MCA Ist semester ,M.E.R.I. (Indraprastha Univ.)");
	   gotoxy(15,12);
	   textcolor(WHITE);
	   cprintf(" e-mail: soumen@soumenmukherjee.com ");
	   getch();
	   info();
	   clrscr();
	for(i=0;i<=25;i++)
	  for(j=0;j<=80;j++)
	  {
	   gotoxy(j,i);
	   textbackground(BLACK);
	   cprintf(" ");
	  }
	  gotoxy(15,1);
	  textcolor(LIGHTGRAY);
	  cprintf(" ######   NUMBER JUMBLE by Soumen Mukherjee #####");
   textcolor(LIGHTRED);

	for(i=0;i<4;i++)
	 {
	  x=30;
		for(j=0;j<4;j++)
		{
		  gotoxy(x,y);
		  if(sheet[i][j]==NULL)
		   textcolor(BLACK);
		  else
		   textcolor(LIGHTRED);
		  cprintf(" %d ",sheet[i][j]);
		  x=x+5;
		}

	     y=y+2;
	  }

	  gotoxy(10,24);
	  textcolor(LIGHTGRAY);
	  cprintf(" Use Arrow Keys to Shift The Number %c %c %c %c ",24,25,26,27);
	  posx=4;
	  posy=4;
	  xx=3;
	  yy=3;
	  while(ch!=28)
	  {

	  again :
	  gotoxy(1,1);
	  ch=getkey();
	  move=move+1;
	  if(ch==80)
	  {
	     if(posx==1)
	     {
	       gotoxy(20,20);
	       textcolor(YELLOW);
	       cprintf(" move not possible......       ");
	       textcolor(RED);
	       sound(3000);
	       delay(500);
	       nosound();
	       move--;
	       goto again;
	     }
		gotoxy(20,20);
		textcolor(YELLOW);
		cprintf("NUMBER OF MOVES MADE :%d",move);
		temp=sheet[xx][yy];
		sheet[xx][yy]=sheet[xx-1][yy];
		sheet[xx-1][yy]=temp;
		posx=posx-1;
		xx=xx-1;
		gotoxy(20,20);
		ex=pp(sheet,move);
		 if(ex==1)
		 exit();
	  }
	  if(ch==72)
	  {
	     if(posx==4)
	     {
	       gotoxy(20,20);
	       textcolor(YELLOW);
	       cprintf(" move not possible......       ");
	       textcolor(RED);
	       sound(3000);
	       delay(500);
	       nosound();
	       move--;
	       goto again;
	     }
		gotoxy(20,20);
		textcolor(YELLOW);
		cprintf("NUMBER OF MOVES MADE :%d",move);
		temp=sheet[xx][yy];
		sheet[xx][yy]=sheet[xx+1][yy];
		sheet[xx+1][yy]=temp;
		posx=posx+1;
		xx=xx+1;
		ex=pp(sheet,move);
		if(ex==1)
		exit();
	  }
	  if(ch==77)
	  {
	     if(posy==1)
	     {
	       gotoxy(20,20);
	       textcolor(YELLOW);
	       cprintf(" move not possible......       ");
	       textcolor(RED);
	       sound(3000);
	       delay(500);
	       nosound();
	       move--;
	       goto again;
	     }
		gotoxy(20,20);
		textcolor(YELLOW);
		cprintf("NUMBER OF MOVES MADE :%d",move);
		temp=sheet[xx][yy];
		sheet[xx][yy]=sheet[xx][yy-1];
		sheet[xx][yy-1]=temp;
		posy=posy-1;
		yy=yy-1;
		ex=pp(sheet,move);
		if(ex==1)
		exit();
	       }
	  if(ch==75)
	  {
	     if(posy==4)
	     {
	       gotoxy(20,20);
	       textcolor(YELLOW);
	       cprintf(" move not possible......       ");
	       textcolor(RED);
	       sound(3000);
	       delay(500);
	       nosound();
	       move--;
	       goto again;
	     }
		gotoxy(20,20);
		textcolor(YELLOW);
		cprintf("NUMBER OF MOVES MADE :%d",move);
		temp=sheet[xx][yy];
		sheet[xx][yy]=sheet[xx][yy+1];
		sheet[xx][yy+1]=temp;
		posy=posy+1;
		yy=yy+1;
		ex=pp(sheet,move);
		if(ex==1)
		exit();
	  }
      }
		getch();

	  system("cls");

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

	  void info(void)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	rectangle(20,20,630,470);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(15,15,BLACK);
	settextstyle(4,0,4);
	setcolor(LIGHTGREEN);
	outtextxy(30,30,"   Number Jumble ");
	setcolor(WHITE);
	setlinestyle(0,0,1);
	line(20,65,630,65);
	settextstyle(6,0,3);
	setcolor(EGA_RED);
	outtextxy(10,70,"  The Puzzle is quite  simple  yet challenging . The aim is to ");
	outtextxy(10,110,"  arrange the numbers in order from 1 to 15 . Move the blank");
	outtextxy(10,150,"  with the help of arrow keys . Press the key corresponding ");
	outtextxy(10,190,"  to the direction you wish to shift the blank .  ");
	setcolor(CYAN);
	outtextxy(120,350," Double enter to EXIT the game,press any key..");
		getch();
		closegraph();
	restorecrtmode();
}