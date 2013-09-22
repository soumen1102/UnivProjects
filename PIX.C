#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdio.h>
void main()
{
int gd=DETECT,gm,x1=0,y;
int  x=2,y1=2,r=9;
double t=0;
initgraph(&gd,&gm,"");
while(!kbhit())
{
y=y1;
//r=r*r;
//y=y*y;
//t=r-y;
x=sqrt((r*r)-(y*y));
//x1=x;
//putpixel(x,y,RED);
delay(30);
y1++;
}
getchar();
closegraph();
restorecrtmode();
}