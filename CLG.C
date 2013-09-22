#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int h1=1,h2=8,m1=0,m2=0,s1=0,s2=0;//time : h1h2:m1m2:s1s2
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");

	setcolor(YELLOW);
	settextstyle(0,0,2);
	while(!kbhit())
	{
	outtextxy(35,12,"%d%d:%d%d:%d%d",h1,h2,m1,m2,s1,s2);
	delay(1000);
	s2++;
	if(s2==10)
	{
	s2=0;
	s1++;
	}
	if(s1==6)
	{
	s1=0;
	m2++;
	}
	if(m2==10)
	{
	m2=0;
	m1++;
	}
	if(m1==6)
	{
	m1=0;
	h2++;
	}
	if(h2==10)
	{
	h2=0;
	h1++;
	}
	if(h1==2 && h2==4)
	{
	h1=0;
	h2=0;
	}
	}
	closegraph();
	restorecrtmode();

}
