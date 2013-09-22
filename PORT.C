#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
void main()
{
//system("cls");
int x=200,y=200,gd=DETECT,gm;
initgraph(&gd,&gm,"");
putpixel(x,y,YELLOW);
putpixel(x+1,y-1,YELLOW);
putpixel(x-1,y-1,YELLOW);
putpixel(x,y-2,YELLOW);
putpixel(x+1,y-2,YELLOW);
putpixel(x+2,y-1,YELLOW);
putpixel(x+3,y,YELLOW);
putpixel(x+4,y+1,YELLOW);
putpixel(x+5,y+2,YELLOW);
x=200;
y=196;
putpixel(x,y,14);
putpixel(x,y-1,14);
putpixel(x,y-2,14);
putpixel(x,y-3,14);
putpixel(x+1,y-3,14);
putpixel(x+2,y-3,14);
putpixel(x-1,y-3,14);
putpixel(x-2,y-3,14);
putpixel(x-1,y,14);
putpixel(x-2,y-1,14);
putpixel(x-3,y,14);
putpixel(x-2,y+1,14);
putpixel(x,y+1,14);
putpixel(x,y+2,14);
putpixel(x+1,y-1,14);
putpixel(x+2,y,14);
putpixel(x+2,y+1,14);
//putpixel(x+5,y+2,YELLOW);


//putpixel(x+1,y-2,YELLOW);
getchar();
closegraph();
restorecrtmode();
}