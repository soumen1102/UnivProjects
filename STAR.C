#include<graphics.h>
#include<dos.h>
void main()
{
int x,y,z,gd=DETECT,gm,i,j,k,l=0;

initgraph(&gd,&gm,"");
while(l<30000)
{
//for(i=0,j=480;i<=640,j>=0;i+=10,j-=10)
i=rand() %480;
j=rand() %640;
k=rand() %16;
{
setcolor(k);
circle(100+i,100+j,2);
setfillstyle(SOLID_FILL,k);
floodfill(100+i,100+j,k);
//delay(10);
/*setcolor(BLACK);
circle(100+i,100+j,2);
setfillstyle(SOLID_FILL,BLACK);
floodfill(100+i,100+j,BLACK);
//delay(3);*/
}

	     l++;
//cleardevice();
}
getch();
closegraph();
restorecrtmode();
}