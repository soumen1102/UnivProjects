#include<dos.h>
#include<graphics.h>
union REGS i,o;
main()
{
int gd=DETECT,gm,maxx,maxy,x,y,xp,yp,button,ch=0,i=1,flag=0;
initgraph(&gd,&gm,"");
maxx=getmaxx();
maxy=getmaxy();
setbkcolor(BLACK);
setlinestyle(SOLID_LINE,1,3);
rectangle(0,56,maxx,maxy);
setviewport(1,1,maxx-1,maxy-1,1);
/*gotoxy(10,1);
printf("1=CIRCLE");
gotoxy(20,1);
printf("2=LINE");*/
setcolor(LIGHTCYAN);
settextstyle(5,0,3);
outtextxy(200,0,"CATCH ME IF YOU CAN");

if(initmouse()==0)
{
 closegraph();
 restorecrtmode();
 printf("mouse driver not loaded");
 getch();
 exit(1);
}
restrictmouseptr(1,57,maxx-1,maxy-1);
getmousepos(&button,&x,&y);
xp=x;
yp=y;
showmouseptr();
while(!kbhit())
{
setcolor(i);
setlinestyle(SOLID_LINE,0,2);
xp=x;
yp=y;
getmousepos(&button,&x,&y);
while((button & 1)==1)
{
setcolor(RED);
rectangle(xp,yp,x,y);
delay(20);
setcolor(BLACK);
rectangle(xp,yp,x,y);
getmousepos(&button,&x,&y);
flag=1;
}
if(flag==1)
{
setcolor(RED);
rectangle(xp,yp,x,y);
flag=0;
}
if(xp!=x && yp!=y)
{
setcolor(i);
settextstyle(5,0,1);
outtextxy(380,440,"designed by:Soumen Mukherjee");
i++;
if(i==15)
i=1;
}
}
ch=getch();
if(ch==13)
{
closegraph();
restorecrtmode();
exit(1);
}
if(ch==1)
cleardevice();
main();
}


//initialize mouse
initmouse()
{
i.x.ax=0;
int86(0x33,&i,&o);
return(o.x.ax);
}
showmouseptr()
{
i.x.ax=1;
int86(0x33,&i,&o);
}
restrictmouseptr(int x1,int y1,int x2,int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0x33,&i,&o);
i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0x33,&i,&o);
}
getmousepos(int *button,int *x,int *y)
{
i.x.ax=3;
int86(0x33,&i,&o);
*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}



