#include<stdio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm,x,y,flag=0;
initgraph(&gd,&gm,"");
x=getmaxx();
x=x/2;
y=66;
setcolor(EGA_RED);
setbkcolor(BLACK);
    while(!kbhit())
    {
	setcolor(RED);
	circle(x,y,55);
	setfillstyle(2,YELLOW);
	circle(x,y,55);
	floodfill(x,y,YELLOW);
    /*delay(2);
    setcolor(EGA_BLACK);
    circle(x,y,5);
    setfillstyle(SOLID_FILL,BLACK);
	floodfill(x,y,BLACK);
    if(y<477 && flag==0)
    y++;
    if(y==477)
    {
    flag=1;
    sound(4000);
    delay(10);
    nosound();
    }
    if(y>6 && flag==1)
    y--;
    if(y==6)
    {
    flag=0;
    sound(4000);
    delay(10);
    nosound();
    }
    */
    }
    getch();
    closegraph();
    restorecrtmode();
    }