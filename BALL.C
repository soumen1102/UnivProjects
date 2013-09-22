#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm,x,y,x1,y1,ff,yy,flag=0,flag2=0,ch;
initgraph(&gd,&gm,"");
x1=getmaxx();
y1=getmaxy();
x=630/2;
y=6;
x1=2;
setcolor(WHITE);
setbkcolor(BLACK);

    while(1)
    {
	setcolor(YELLOW);
	rectangle(2,2,638,478);
	setcolor(WHITE);
	settextstyle(4,0,2);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(getmaxx()/2,getmaxy()/2,"Designed by : Soumen mukherjee");
	setcolor(WHITE);
	circle(x,y,5);
		circle(x,y,4);
		setcolor(LIGHTRED);
		  circle(x,y,3);
		   circle(x,y,2);
		     delay(25);
	    setcolor(BLACK);
    circle(x,y,5);
	circle(x,y,4);
	  circle(x,y,3);
	    circle(x,y,2);


	if((y<476 && flag==0) || y<0 )
    y+=x1;
    if(y==476 || y>476)
    {
    flag=1;
    sound(4500);
    delay(5);
    nosound();
    }
    if((y>6 && flag==1) || y>476)
    y-=x1;
    if(y==6 || y<6)
    {
    flag=0;
    sound(4500);
    delay(5);
    nosound();
    }
    if(flag2==1)
    {
    x+=x1;
    if(x>630)
    {
    x=629;
    flag2=2;
    sound(4500);
    delay(5);
    nosound();
    }

    }
    if(flag2==2)
    {
    x-=x1;
    if(x<5)
    {
    x=6;
    flag2=1;
    sound(4500);
    delay(5);
    nosound();
    }
    }
    if(kbhit())
    {
    ch=getch();
    if(ch==13)
    break;
    if(ch==77)
    {
    x+=5;
    if(x>630)
    x=629;
    flag2=1;
    }
    if(ch==75)
    {
    x-=5;
    if(x==5)
    x=6;
    flag2=2;
     }
    if(ch==72)
    {
    x1+=2;
    if(x1==60)
    x1=58;
    }
    if(ch==80)
    {
    x1-=2;
    if(x1==0)
    x1=2;
    }
    }
	}
     closegraph();
	 restorecrtmode();
    }
