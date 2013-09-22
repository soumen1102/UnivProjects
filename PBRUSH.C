#include<dos.h>
#include<graphics.h>
#include<stdio.h>
void myrectangle(void);
void mycircle(void);
void mydisc(void);
void myeraser(void);
union REGS i,o;

FILE *ptr;
main()
{
int gd=DETECT,gm,maxx,maxy,x,y,xp,yp,button,ch=0,i=1,opt=0,flag=0,j;
initgraph(&gd,&gm,"");
maxx=getmaxx();
maxy=getmaxy();

ptr=fopen("first.bmp","wb+");

setbkcolor(BLACK);
setlinestyle(SOLID_LINE,1,3);
rectangle(0,0,maxx,maxy);
rectangle(0,56,maxx-2,maxy-2);
setviewport(1,1,maxx-1,maxy-1,1);
/*gotoxy(10,1);
printf("1=CIRCLE");
gotoxy(20,1);
printf("2=LINE");*/
setcolor(LIGHTCYAN);
//settextstyle(4,0,2);
//outtextxy(20,0,"Elementary Slate Board");
rectangle(5,5,40,40);
circle(80,25,22);
ellipse(180,25,0,360,60,22);
line(270,15,340,40);
j=20;
while(j>0)
{
setlinestyle(SOLID_FILL,1,1);
circle(380,22,j);
j--;
}
setcolor(WHITE);
rectangle(430,5,450,40);
if(initmouse()==0)
{
 closegraph();
 restorecrtmode();
 printf("mouse driver not loaded");
 getch();
 exit(1);
}
restrictmouseptr(1,1,maxx-1,maxy-1);
getmousepos(&button,&x,&y);
xp=x;
yp=y;
showmouseptr();
while(!kbhit())
{
setcolor(CYAN);
setlinestyle(SOLID_LINE,1,3);
restrictmouseptr(1,1,maxx-1,maxy-1);
rectangle(5,5,40,40);
circle(80,25,22);
ellipse(180,25,0,360,60,22);
line(270,15,340,40);
j=20;
while(j>0)
{
setlinestyle(SOLID_FILL,1,1);
circle(380,22,j);
j--;
}

getmousepos(&button,&x,&y);
if((x>=5 && x<=40) && (y>=5 && y<=40))
{
setcolor(RED);
setlinestyle(SOLID_LINE,1,3);
rectangle(5,5,40,40);
delay(20);
myrectangle();
}
if((x>=60 && x<=100) && (y>=5 && y<=40))
{
setcolor(RED);
setlinestyle(SOLID_LINE,1,3);
circle(80,25,22);
delay(20);
mycircle();
}
if((x>=120 && x<=250) && (y>=5 && y<=40))
{
setcolor(i);
setlinestyle(SOLID_LINE,1,3);
ellipse(180,25,0,360,60,22);
delay(20);
myellipse();
}
if((x>=270 && x<=340) && (y>=5 && y<=40))
{
setcolor(i);
setlinestyle(SOLID_LINE,1,3);
line(270,15,340,40);
delay(20);
myline();
}
if((x>=380 && x<=420) && (y>=5 && y<=40))
{
setcolor(i);
j=20;
while(j>0)
{
setlinestyle(SOLID_FILL,1,1);
circle(380,22,j);
j--;
}
delay(20);
mydisc();
}

if((x>=430 && x<=450) && (y>=5 && y<=40))
{
myeraser();
delay(20);
}
fflush(stdin);
continue;
}
ch=getch();
if(ch==13)
{
closegraph();
restorecrtmode();
exit(1);
}
if(ch==1)
{
cleardevice();
main();
}
closegraph();
restorecrtmode();
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

void myrectangle(void)
{
int x,y,xp,yp,button,ch=0,i1=1,flag=0;
static int i=1;
setlinestyle(SOLID_LINE,1,3);
restrictmouseptr(1,57,639,479);
getmousepos(&button,&x,&y);
xp=x;
yp=y;
showmouseptr();
while(!kbhit())
{
setcolor(i);
setlinestyle(SOLID_LINE,1,3);
rectangle(5,5,40,40);
delay(20);
setlinestyle(SOLID_LINE,0,2);
xp=x;
yp=y;
getmousepos(&button,&x,&y);
while((button & 1)==1)
{
setcolor(i);
rectangle(xp,yp,x-2,y-2);
delay(20);
setcolor(BLACK);
rectangle(xp,yp,x-2,y-2);
getmousepos(&button,&x,&y);
flag=1;
}
if(flag==1)
{
setcolor(i);
rectangle(xp,yp,x-2,y-2);
flag=0;
}
gotoxy(65,2);
printf("X=%03d Y=%03d",x,y);

if(xp!=x && yp!=y)
{
setcolor(i1);
settextstyle(5,0,1);
outtextxy(380,440,"designed by:Soumen Mukherjee");
i1++;
if(i==15)
i=1;
}
}
ch=getch();
if(ch==13)
{
return(0);
}
if(ch==1)
{
cleardevice();
closegraph();
main();
}
if(ch==9)
{
i++;
if(i==15)
i=1;
ch=NULL;
myrectangle();
}
}
 void mycircle(void)
 {
 int x,y,xp,yp,button,ch=0,i1=1,flag=0;
 static int i=1;
 setbkcolor(BLACK);
 setlinestyle(SOLID_LINE,1,3);
 restrictmouseptr(1,57,639,479);
getmousepos(&button,&x,&y);
xp=x;
yp=y;
showmouseptr();
while(!kbhit())
{
setcolor(i);
setlinestyle(SOLID_LINE,1,3);
circle(80,25,22);
delay(20);
setlinestyle(SOLID_LINE,0,2);
xp=x;
yp=y;
getmousepos(&button,&x,&y);
while((button & 1)==1)
{
setcolor(i);
circle(xp,yp,x-xp);
delay(20);
setcolor(BLACK);
circle(xp,yp,x-xp);
getmousepos(&button,&x,&y);
flag=1;
}
if(flag==1)
{
setcolor(i);
circle(xp,yp,x-xp);
flag=0;
}
gotoxy(65,2);
printf("X=%03d Y=%03d",x,y);

if(xp!=x && yp!=y)
{
setcolor(i1);
settextstyle(5,0,1);
outtextxy(380,440,"designed by:Soumen Mukherjee");
i1++;
if(i1==15)
i1=1;
}
}
ch=getch();
if(ch==13)
{
return(0);
}
if(ch==1)
{
return(0);
}
if(ch==9)
{
i++;
ch=NULL;
mycircle();
}
}
myellipse()
{
int x,y,xp,yp,button,ch=0,i1=1,flag=0;
static int i=1;
setbkcolor(BLACK);
setlinestyle(SOLID_LINE,1,3);
setcolor(i);
ellipse(180,25,0,360,60,22);
delay(20);
setlinestyle(SOLID_LINE,1,3);
restrictmouseptr(1,57,639,479);
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
setcolor(i);
ellipse(xp,yp,0,360,x-xp,y-yp);
delay(20);
setcolor(BLACK);
ellipse(xp,yp,0,360,x-xp,y-yp);
getmousepos(&button,&x,&y);
flag=1;
}
if(flag==1)
{
setcolor(i);
ellipse(xp,yp,0,360,x-xp,y-yp);
flag=0;
}
gotoxy(65,2);
printf("X=%03d Y=%03d",x,y);

if(xp!=x && yp!=y)
{
setcolor(i1);
settextstyle(5,0,1);
outtextxy(380,440,"designed by:Soumen Mukherjee");
i1++;
if(i1==15)
i1=1;
}
}
ch=getch();
if(ch==13)
{
getimage(1,1,630,470,ptr);
}
if(ch==1)
{
cleardevice();
main();
}
if(ch==9)
{
i++;
ch=NULL;
myellipse();
}
}

myline()
{
int x,y,xp,yp,button,ch=0,i1=1,opt=0;
static int i=1;
setlinestyle(SOLID_LINE,1,3);
restrictmouseptr(1,57,639,479);
getmousepos(&button,&x,&y);
xp=x;
yp=y;
showmouseptr();
while(!kbhit())
{
setcolor(i);
setcolor(i);
setlinestyle(SOLID_LINE,1,3);
line(270,15,340,40);
setlinestyle(SOLID_LINE,0,2);
xp=x;
yp=y;
getmousepos(&button,&x,&y);
//gotoxy(5,3);
if((button & 1)==1)
{
putpixel(x-2,y-2,i);
setcolor(i);
line(xp-2,yp-2,x-2,y-2);
}

if((button & 2)==2)
{
putpixel(x-2,y-2,CYAN);
setcolor(CYAN);
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
setcolor(i1);
settextstyle(5,0,1);
outtextxy(380,440,"designed by:Soumen Mukherjee");
i1++;
if(i1==15)
i1=1;
}
}
ch=getch();
if(ch==13)
{
return(0);
}
if(ch==1)
{
cleardevice();
main();
}
if(ch==9)
{
i++;
ch=NULL;
myline();
}
}
void mydisc(void)
{
int x,y,xp,yp,button,ch=0,i1=1,opt=0,j;
static int i=1;
setbkcolor(BLACK);
setcolor(i);
j=20;
while(j>0)
{
setlinestyle(SOLID_FILL,1,1);
circle(380,22,j);
j--;
}
setlinestyle(SOLID_LINE,1,3);
getmousepos(&button,&x,&y);
xp=x;
yp=y;
showmouseptr();
while(!kbhit())
{
setcolor(i);
setlinestyle(SOLID_LINE,0,2);
restrictmouseptr(1,57,639,479);
xp=x;
yp=y;
getmousepos(&button,&x,&y);
while((button & 1)==1)
{
getmousepos(&button,&x,&y);
circle(xp,yp,x-xp);
}
gotoxy(65,2);
printf("X=%03d Y=%03d",x,y);

if(xp!=x && yp!=y)
{
setcolor(i1);
settextstyle(5,0,1);
outtextxy(380,440,"designed by:Soumen Mukherjee");
i1++;
if(i1==15)
i1=1;
}
}
fflush(stdin);
ch=getch();
if(ch==13)
{
return(0);
}
if(ch==1)
{
cleardevice();
main();
}
if(ch==9)
{
i++;
ch=NULL;
mydisc();
}
}
void myeraser(void)
{
int x,y,x1,y1,button;
restrictmouseptr(1,57,639,479);
while(!kbhit())
{
getmousepos(&button,&x,&y);

while((button & 1)==1)
{
setcolor(WHITE);
setlinestyle(DOTTED_LINE,1,1);
rectangle(x-11,y-21,x+11,y+21);
setcolor(BLACK);
for(y1=y-20;y1<y+20;y1++)
 for(x1=x-10;x1<x+10;x1++)
  putpixel(x1,y1,BLACK);
  rectangle(x-11,y-21,x+11,y+21);
  getmousepos(&button,&x,&y);
}
}
fflush(stdin);
getch();
return(0);
}

hidemouseptr()
{
i.x.ax=0;
int86(0x33,&i,&o);
}
