#include<graphics.h>
void main()
{
int x1,x2,x3,y1,y2,y3,x11,x22,x33,y11,y22,y33,gd=DETECT,gm,u=1,j=5;
static int X11[200],X22[200],X33[200],Y11[200],Y22[200],Y33[200],k=0,tp;
static int l,m;
initgraph(&gd,&gm,"");

setcolor(RED);
setbkcolor(0);

x1=320;
y1=100;
x2=160;
y2=250;
x3=480;
y3=250;
x11=320;
y11=100;
x22=160;
y22=250;
x33=480;
y33=250;
sleep(1);

X11[0]=x22;
Y11[0]=y22;
X33[0]=x33;
Y33[0]=y33;
k++;
while(!kbhit())
{
while(u>0)
{
setcolor(15);

line(x1,y1,x2,y2);
sleep(1);
line(x2,y2,x3,y3);
sleep(1);
line(x3,y3,x1,y1);
sleep(1);

X11[k]=x1;
X22[k]=x2;
X33[k]=x3;

x1=(x11+x22)/2;
x2=(x22+x33)/2;
x3=(x11+x33)/2;
y1=(y11+y22)/2;
y2=(y22+y33)/2;
y3=(y11+y33)/2;

//x22=x1;
//x33=x3;


//y22=y1;
//y33=y1;

Y11[k]=y1;
Y22[k]=y2;
Y33[k]=y1;
k++;
}
x11=X11[l];
x22=X22[l];
x33=X33[l];
y11=Y11[l];
y22=Y22[l];
y33=Y33[l];
l++;
}
u=u*3;
}
}
getch();
closegraph();
restorecrtmode();
system("cls");
}

