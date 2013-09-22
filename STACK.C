#include<stdio.h>
#include<conio.h>
void layout(int x1,int y1,int x2,int y2,int ccb,int cct);
void main()
{
 int arr[200],bot=200,c=0,i=7,y=21,cc=0;
 char ch;
 while(1)
 {
   clrscr();
   layout(2,2,78,23,8,15);
   gotoxy(25,3);
   cprintf("S T A C K  O P E R A T I O N S");
   textcolor(LIGHTGRAY);
   gotoxy(30,5);
   cprintf("INSERT ELEMENT");
   textcolor(RED);
   gotoxy(30,5);
   cprintf("I");
   textcolor(LIGHTGRAY);
   gotoxy(30,7);
   cprintf("DELETE ELEMENT");
   textcolor(RED);
   gotoxy(30,7);
   cprintf("D");
   gotoxy(30,9);
   textcolor(LIGHTGRAY);
   cprintf("QUIT");
   textcolor(RED);
   gotoxy(30,9);
   cprintf("Q");
   gotoxy(40,20);
   ch=getch();
   clrscr();
   switch(toupper(ch))
   {
     case 81:
     case 113:
     exit(1);
     case 105:
     case 73:
     {
      y=21;
      i=5;
      cc--;
      while(cc>=0)
      {
      textcolor(15);
      gotoxy(i,y--);
      delay(35);
      cprintf("%d",arr[bot+cc]);
      if(y==3)
      {
      y=21;
      i+=8;
      }
      cc--;
      }
      y++;
      while(2)
      {
      layout(2,2,78,23,8,15);
      gotoxy(25,4);
      cprintf("I N S E R T   E L E M E N T S");
      layout(22,7,55,12,8,15);
      gotoxy(25,8);
      if(bot==164)
      {
      cprintf("O V E R F L O W");
      getch();
      break;
      }
      cprintf("PUSH: ");
      fflush(stdin);
      textcolor(RED);
      cprintf("                 ");
      gotoxy(32,8);
      scanf("%d",&arr[--bot]);
      c++;
      cc=c;
      gotoxy(25,9);
      textcolor(15);
      cprintf("INSERT ANOTHER TAB TO END");
      gotoxy(i,y--);
      if(y==3)
      {
      y=21;
      i+=8;
      }
      gotoxy(i-2,y);
      cprintf("%c",26);
      gotoxy(i,y);
      cprintf("%d",arr[bot]);
      gotoxy(50,9);
      ch=getch();
      if(ch==9)
      break;
      else
      {
      textcolor(0);
      gotoxy(i-2,y);
      cprintf("%c",26);
      gotoxy(25,9);
      cprintf("INSERT ANOTHER TAB TO END");
      textcolor(15);
      gotoxy(20,8);
      cprintf("                                               ");
      continue;
      }
      }
     }
     break;
   case 68:
   case 100:
     {
      clrscr();
      y=21;
      i=5;
      cc--;
      while(cc>=0)
      {
      textcolor(15);
      gotoxy(i,y--);
      delay(35);
      cprintf("%d",arr[bot+cc]);
      if(y==3)
      {
      y=21;
      i+=8;
      }
      cc--;
      }
      y++;
      while(2)
      {
      layout(2,2,78,23,8,15);
      gotoxy(25,4);
      cprintf("D E L E T E   E L E M E N T S");
      layout(20,7,55,12,8,15);
      gotoxy(25,8);
      if(bot==200 && ch==13)
      {
      cprintf("U N D E R F L O W");
      getch();
      break;
      }
      cprintf("POP ");
      textbackground(CYAN);
      cprintf("YES");
      fflush(stdin);
      textbackground(0);
      gotoxy(25,9);
      cprintf("HIT TAB TO END");
      ch=getch();
      if(ch==13 && bot<200)
      {
      bot++;
      c--;
      cc=c;
      textcolor(0);
      gotoxy(i-2,y++);
      cprintf("         ");
      textcolor(15);
      if(y==22)
      {
      y=4;
      i=5;
      }
      gotoxy(i-2,y);
      cprintf("%c",26);
      continue;
      }
      if(ch==9)
      break;
     }
     }
   }
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