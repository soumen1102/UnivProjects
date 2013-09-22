#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm,x,y,h,i,j,x1,k=0;

	initgraph(&gd,&gm,"");
		x=getmaxx();
		y=getmaxy();
		h=getmaxy();
	     for(j=5;j<=50;j=j+5)
	     {
	     for(i=10,x1=10;i<=100;i=i+10,x1+=10)
	     {
	     for(h=15;h<=150;h+=35)
	     {
	     setcolor(k);

	     delay(25);
	     sound((k*j)/3);
	    circle((x+j)/3,(y+j)/15,x1);
	     circle((x+j)/15,(y+j)/3,x1);
	     circle((x+j)/3,(y+j)/15,x1);
	     circle((x+j)/3,
	     (y+j)/3
	     ,x1);
	    delay(10);
	    nosound();
	    }
	    }
	    k+=20;
		}
	    delay(200);
	    getch();
	    nosound();

     closegraph();
     restorecrtmode();
 }