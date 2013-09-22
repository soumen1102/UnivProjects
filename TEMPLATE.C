#include<graphics.h>
#include<stdio.h>
#include<stdio.h>
void main()
{

 char text[40];
 int gd=DETECT,gm,c=0,x=40,i=0;
 while(i<20)
	{
	scanf("%c",&text[i]);
	i++;
	}
 initgraph(&gd,&gm,"");

	rectangle(10,10,630,470);
	       i=0;
	       while(text[i]!=NULL)
	       {
	       c++;
	       i++;
	       }

	       while(c!=0)
	       {
	       x--;
	       c--;
	       }
	       getch();
	       //textcolor(LIGHTGRAY);
	       gotoxy(x,13);
	       cputs(text);
	       while(!kbhit())
	       closegraph();
	       restorecrtmode();
 }