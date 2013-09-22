#include<graphics.h>
#include<dos.h>
#include<conio.h>
void main()
{
int x=0,y=0,r=0,i=3,j=0,gd=DETECT,gm;
char ch;

	initgraph(&gd,&gm,"");

	while(!kbhit())
	{

	x=rand() %600;
	y=rand() %400;
	i=rand() %15;
	r=rand() %100;
	j=rand() %10;
	//setbkcolor(i+2);
	setcolor(i);
	circle(x,y,r);
	setfillstyle(j,i+1);
	//circle(x,y,r);
	floodfill(x,y,i);
	delay(500);
	}
	closegraph();
	restorecrtmode();
}
