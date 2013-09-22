#include<graphics.h>
void main()
{
int i[4],j[4],k[4],gd=DETECT,gm,u=3000;

initgraph(&gd,&gm,"");

setcolor(RED);
setbkcolor(15);

i[0]=320;
j[0]=160;
k[0]=480;
i[1]=50;
j[1]=210;
k[1]=210;
i[2]=320;
j[2]=250;
i[3]=240;
j[3]=250;
k[2]=400;
k[3]=250;

while(!kbhit())
{
setcolor(RED);
sound(u);
setlinestyle(SOLID_LINE,1,3);
setfillstyle(SOLID_FILL,LIGHTRED);
line(i[0],i[1],j[0],j[1]);
line(j[0],j[1],k[0],k[1]);
line(k[0],k[1],i[0],i[1]);
line(i[0],i[1],i[2],j[2]);
line(i[3],j[3],k[2],k[3]);
delay(100);
setcolor(0);
line(i[0],i[1],j[0],j[1]);
line(j[0],j[1],k[0],k[1]);
line(k[0],k[1],i[0],i[1]);

j[0]+=20;
k[0]-=20;
u=u+100;
setfillstyle(SOLID_FILL,WHITE);
if(k[0]<=160)
{
k[0]=480;
j[0]=160;
u=3000;
}
delay(5);
nosound();

}

getch();
closegraph();
restorecrtmode();

}

