#include<stdio.h>
#include<graphics.h>
void info(void)
{
int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	rectangle(20,20,630,470);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(15,15,BLUE);
	settextstyle(1,0,3);
	setcolor(LIGHTGREEN);
	outtextxy(30,30,"   Number Jumble ");
	setcolor(WHITE);
	setlinestyle(0,0,1);
	line(20,65,610,65);
	settextstyle(4,0,2);
	setcolor(EGA_LIGHTRED);
	outtextxy(10,70,"  The Puzzle is quite  simple  yet challenging . The aim is to ");
	outtextxy(10,90,"  arrange the numbers in order from 1 to 15 . Shift the blank ");
	outtextxy(10,110,"  with the help of arrow keys . Press the key corresponding ");
	outtextxy(10,130,"  to the direction you wish to shift the blank .  ");
	setcolor(CYAN);
	outtextxy(150,350," Double enter to EXIT the game");
		getchar();
		closegraph();
	restorecrtmode();
}