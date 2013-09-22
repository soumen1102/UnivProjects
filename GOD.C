#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm,x,y,i=0,r;

initgraph(&gd,&gm,"");
while(!kbhit())
{
setcolor(i);
circle(100,100,60);
delay(0);
i++;
}
closegraph();
restorecrtmode();
}