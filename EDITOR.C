#include<stdio.h>
#include<conio.h>
#include<dos.h>


void type(char *st,int *ct,int *y);
void layout(void);
void layout1(int x1,int y1,int x2,int y2,int ccb,int cct);


int input();
void save(void);

void main()
{
char ch1;
int cho,i,j,opt;
FILE *usr;
usr=fopen("temp.txt","w");
layout();
cho=input();
switch(cho)
{
case 1:
{
  opt=file();
  switch(opt)
	{
		case 3:
		save();
		default:
		save();
	}
   break;                // '''''''''''''
}
default:
break;
}
clrscr();
clrscr();
system("cls");
system("cls");
}
int input()
{
int choice1,y=1,ct=2,i=0;
char choice,prev,*start,*ss,*buf,c;
FILE *temp;
temp=fopen("temp.txt","wb+");
start=(char *)malloc(1);
ss=start;
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
  gotoxy(10,24);
  textcolor(LIGHTRED);
  textbackground(CYAN);
  cprintf("%2d:%2d",y-1,ct-1);
  gotoxy(ct,y);
  textbackground(RED);
  textcolor(WHITE);
  choice=getch();
  prev=choice;
  choice1=choice;
  ct++;
  if(choice1==8)
  {
  if(ct==3 &&y==2)
  {
  y--;
  if(y==1)
  y=2;
  gotoxy(2,y);
  continue;
  }
  if(ct==3 &&y>2)
  {
  y--;
  gotoxy(80,y);
  }
  textbackground(LIGHTGRAY);
  printf("\b");
  cprintf(" ");
  printf("\b");
  textcolor(WHITE);
  ct-=2;
  if(ct==1)
  ct=79;
  start--;
  continue;
  }
  if(choice1==9 && ct<75)
  {
   ct+=4;
   for(i=0;i<=4;i++)
   {
   *start=' ';
   start++;
   }
   gotoxy(ct,y);
   continue;
  }
  if(choice1==9 && ct>=75)
  choice=' ';
  if(choice!=NULL && choice1!=27)
  {
  cprintf("%c",choice);
  *start=choice;
  start++;
  }
  if(choice==NULL)
  getch();
  if(choice1==13 || ct==80)
  {
  gotoxy(2,y++);
  ct=2;
  for(i=0;i<80-ct;i++)
  {
  *start=' ';
  start++;
  }
  }
  }
 *start=EOF;
  break;
}
while(*ss!=EOF)
{
fputc(*ss,temp);
ss++;
}
fclose(temp);
return(1);
}
void layout(void)
{
int i;
window(1,1,80,25);
textbackground(LIGHTGRAY);
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
 int file()
 {
 int i,ch,flag=0,x=10;
 char menu[10][20]={
		     "New",
		     "Save",
		     "Save As",
		     "EXIT"
		   };
 textcolor(RED);
 textbackground(LIGHTGRAY);
 for(i=1;i<80;i++)
 {
 gotoxy(i,25);
 cprintf(" ");
 }
 gotoxy(5,25);
 cprintf("New");
 gotoxy(15,25);
 cprintf("Save");
 gotoxy(25,25);
 cprintf("Save As");
 gotoxy(35,25);
 cprintf("EXIT");
 x=25;
 flag=2;
  gotoxy(x,25);
  textbackground(CYAN);
  cprintf("%s",menu[flag++]);
 while(1)
 {
  fflush(stdin);
    ch=getch();

   if(ch==77)
   {

   gotoxy(x,25);
   textbackground(LIGHTGRAY);
   cprintf("%s",menu[flag-1]);
   if(flag==4)
   flag=0;

   if(flag==0)
   {
   gotoxy(5,25);
   textbackground(CYAN);
   cprintf("%s",menu[flag++]);
   x=5;
   continue;
   }

   if(flag==1)
   {
   gotoxy(15,25);
   textbackground(CYAN);
   cprintf("%s",menu[flag++]);
   x=15;
   continue;
   }

   if(flag==2)
   {
   gotoxy(25,25);
   textbackground(CYAN);
   cprintf("%s",menu[flag++]);
   x=25;
   continue;
   }

   if(flag==3)
   {
   gotoxy(35,25);
   textbackground(CYAN);
   cprintf("%s",menu[flag++]);
   x=35;
   continue;
   }


   }
  if(ch==27)
  return(-1);
  if(ch==13)
  return(flag);

 }
 }

	void save(void)
	{
		FILE *ptr1,*ptr2;
		char *name,ch;
		char c;
		ptr1=fopen("temp.txt","rb");

		rewind(ptr1);
		if(ptr1==NULL)
		{
		sound(400);
		delay(200);
		}
		nosound();
		layout1(20,5,60,15,0,15);
		gotoxy(22,6);
		textcolor(LIGHTGRAY);
		cprintf("SAVE FILE AS : ");
		gets(name);
		ptr2=fopen(name,"rb");
		if(ptr2!=NULL)
			{
				gotoxy(25,7);
				textcolor(15);
				cprintf("OVERWRITE FILE %s : Y/N",name);
				ch=getch();
				if(toupper(ch)=='N')
				return(0);
			}
		fclose(ptr2);
		fflush(stdout);
		ptr2=fopen(name,"wb");

		while((c=fgetc(ptr1))!=EOF)
				{
					fputc(c,ptr2);
				}
				gotoxy(27,9);
				cprintf("FILE SAVED SUCESSFULLY");
		getch();
		fclose(ptr1);
		fclose(ptr2);
		system("del temp.txt");
		return(0);
	}

void layout1(int x1,int y1,int x2,int y2,int ccb,int cct)
{
int i,j;
window(x1,y1,x2,y2);
textmode(3);
textbackground(ccb);
textcolor(cct);
for(i=y1;i<=y2;i++)
  for(j=x1;j<x2;j++)
  {
    gotoxy(j,i);
    cprintf(" ");
  }
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

	void type(char *st,int *ct,int *y)
	{
		int i=2,j=2;
		while(*st!=EOF)
			{
				textcolor(15);
				textbackground(LIGHTGREEN);
				gotoxy(i++,j);
				cprintf("%c",*(st++));
				if(i==79)
				{
					j++;
					i=2;
				}
			}

		ct=i;
		y=j;
		gotoxy(10,24);
		textcolor(BLACK);
		cprintf("%2d:%2d",y-1,ct-1);
	}