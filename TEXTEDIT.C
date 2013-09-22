#include<stdio.h>
#include<conio.h>
#include<dos.h>
int getkey(void);
void layout(void);
void main()
{
char ch1;
int cho,i,j;
FILE *usr;
layout();
input();
clrscr();
clrscr();
system("cls");
system("cls");
}
int input(char *start)
{
int choice1,y=2,ct=0;
char choice,prev;
FILE *temp;
temp=fopen("temp.txt","ab+");
if(temp==NULL)
{
printf("FATAL ERROR CANNOT OPEN THE FILE....contact your programe vendor");
clrscr();
system("cls");
exit(2);
}
gotoxy(2,2);
y++;
while(1)
{

  while(choice1!=27)
  {
  fflush(stdin);
  textbackground(GREEN);
  textcolor(WHITE);
  choice=getch();
  prev=choice;
  choice1=choice;
  ct++;
  if(choice1==8)
  {
  textbackground(GREEN);
  printf("\b");
  cprintf(" ");
  printf("\b");
  textcolor(WHITE);
  ct--;
  rewind(temp);

    fputc(NULL,temp);
  continue;
  }
  if(choice!=NULL && choice1!=27)
  {
  cprintf("%c",choice);
  putc(choice,temp);
  }
  if(choice==NULL)
  getch();
  if(choice1==13 || ct==76)
  {
  gotoxy(2,y++);
  ct=0;
  }
  }
  break;
}
putc(EOF,temp);
close(temp);
return(0);
}
void layout(void)
{
int i;
window(1,1,80,25);
textbackground(LIGHTGREEN);
textcolor(BLACK);
gotoxy(1,1);
cprintf(".");
clrscr();
window(1,1,80,25);
gotoxy(1,2);
printf("%c",201);
gotoxy(1,25);
printf("%c",200);
gotoxy(80,2);
printf("%c",187);
gotoxy(80,25);
printf("%c",188);
for(i=2;i<80;i++)
{
gotoxy(i,1);
printf("%c",205);
}
for(i=2;i<80;i++)
{
gotoxy(i,24);
printf("%c",205);
}
for(i=2;i<24;i++)
{
gotoxy(1,i);
printf("%c",186);
gotoxy(80,i);
printf("%c",186);
}
textbackground(LIGHTGRAY);
for(i=2;i<80;i++)
{
gotoxy(i,25);
cprintf(" ");
}
textcolor(RED);
gotoxy(3,25);
cprintf("FILE");
}
/*int getkey(void)
		{
		    union REGS i,o;
		    while(kbhit())
		    {
		    i.h.ah=0;
		    int86(22,&i,&o);
		    return(o.h.ah);
		    }*/


