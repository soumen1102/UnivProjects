#include<dos.h>
#include<graphics.h>
union REGS i,o;
main()
{
int gd=DETECT,gm,maxx,maxy,x,y,xp,yp,button,ch=0,i=1,opt=0;
initgraph(&gd,&gm,"");
maxx=getmaxx();
maxy=getmaxy();
setbkcolor(DARKGRAY);
setlinestyle(SOLID_LINE,1,3);
rectangle(0,56,maxx,maxy);
setviewport(1,1,maxx-1,maxy-1,1);
/*gotoxy(10,1);
printf("1=CIRCLE");
gotoxy(20,1);
printf("2=LINE");*/
setcolor(LIGHTCYAN);
settextstyle(5,0,3);
outtextxy(200,0,"Elementary Slate Board");

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
//hidemouseptr();
setcolor(RED);
setlinestyle(SOLID_LINE,0,2);
xp=x;
yp=y;
getmousepos(&button,&x,&y);
//gotoxy(5,3);
if((button & 1)==1)
while(1)
{
hidemouseptr();
putpixel(x-2,y-2,RED);
setcolor(RED);
line(xp-2,yp-2,x-2,y-2);
getmousepos(&button,&x,&y);
if((button & 1)==0)
{
showmouseptr();
break;
}
}
//gotoxy(20,3);
setcolor(CYAN);
if((button & 2)==2)
{
putpixel(x-2,y-2,CYAN);
line(xp-2,yp-2,x-2,y-2);

}
if((button & 4)==4)
{
putpixel(x-2,y-2,LIGHTGREEN);
setcolor(LIGHTGREEN);
line(xp-2,yp-2,x-2,y-2);

}
if((button & 3)==3)
{
putpixel(x-2,y-2,YELLOW);
setcolor(YELLOW);
line(xp-2,yp-2,x-2,y-2);
}
if((button & 5)==5)
{
putpixel(x-2,y-2,LIGHTRED);
setcolor(LIGHTRED);
line(xp-2,yp-2,x-2,y-2);
}
if((button & 6)==6)
{
putpixel(x-2,y-2,LIGHTMAGENTA);
setcolor(LIGHTMAGENTA);
line(xp-2,yp-2,x-2,y-2);
}

if((button & 7)==7)
{
putpixel(x-2,y-2,WHITE);
setcolor(WHITE);
line(xp-2,yp-2,x-2,y-2);
}

gotoxy(65,2);
printf("X=%03d Y=%03d",x,y);
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
hidemouseptr()
{
i.x.ax=0;
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



