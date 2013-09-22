#include <graphics.h>
#include<dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void main(void)
{
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode,f=1,t=0;
   int x, y, maxx,maxy,maxx1,maxy1,k=0 ;
   unsigned int size;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }


   maxx = getmaxx()/8;
   maxy = getmaxy()/8;
   maxx1=maxx+30;
   maxy1=maxy;
     /* draw the image to be grabbed */

   /* calculate the size of the image */
//   for(f=0;f<10;f++)
     f=0;
     while(!kbhit())
     {

     setcolor(CYAN);
     settextstyle(10,0,10);

     if(f==0)
     outtextxy(maxx1,maxy1,"0");
     if(f==1)
     outtextxy(maxx1,maxy1,"1");
     if(f==2)
     outtextxy(maxx1,maxy1,"2");
     if(f==3)
     outtextxy(maxx1,maxy1,"3");
     if(f==4)
     outtextxy(maxx1,maxy1,"4");
     if(f==5)
     outtextxy(maxx1,maxy1,"5");
     if(f==6)
     outtextxy(maxx1,maxy1,"6");
     if(f==7)
     outtextxy(maxx1,maxy1,"7");
     if(f==8)
     outtextxy(maxx1,maxy1,"8");
     if(f==9)
     outtextxy(maxx1,maxy1,"9");
     delay(1000);
     setcolor(BLACK);
     settextstyle(10,0,10);

     if(f==0)
     outtextxy(maxx1,maxy1,"0");
     if(f==1)
     outtextxy(maxx1,maxy1,"1");
     if(f==2)
     outtextxy(maxx1,maxy1,"2");
     if(f==3)
     outtextxy(maxx1,maxy1,"3");
     if(f==4)
     outtextxy(maxx1,maxy1,"4");
     if(f==5)
     outtextxy(maxx1,maxy1,"5");
     if(f==6)
     outtextxy(maxx1,maxy1,"6");
     if(f==7)
     outtextxy(maxx1,maxy1,"7");
     if(f==8)
     outtextxy(maxx1,maxy1,"8");
     if(f==9)
     outtextxy(maxx1,maxy1,"9");
     delay(1);
	  if(f<=10)
	  {
	  f++;
	  if(f==10)
	  {
	  k++;
	  f=0;
	  }
	  }

	  setcolor(CYAN);
     settextstyle(10,0,10);

     if(k==0)
     outtextxy(maxx,maxy,"0");
     if(k==1)
     outtextxy(maxx,maxy,"1");
     if(k==2)
     outtextxy(maxx,maxy,"2");
     if(k==3)
     outtextxy(maxx,maxy,"3");
     if(k==4)
     outtextxy(maxx,maxy,"4");
     if(k==5)
     outtextxy(maxx,maxy,"5");
     if(k==6)
     outtextxy(maxx,maxy,"6");
     if(k==7)
     outtextxy(maxx,maxy,"7");
     if(k==8)
     outtextxy(maxx,maxy,"8");
     if(k==9)
     outtextxy(maxx,maxy,"9");
     delay(1000);
     setcolor(BLACK);
     settextstyle(10,0,10);

     if(k==0)
     outtextxy(maxx,maxy,"0");
     if(k==1)
     outtextxy(maxx,maxy,"1");
     if(k==2)
     outtextxy(maxx,maxy,"2");
     if(k==3)
     outtextxy(maxx,maxy,"3");
     if(k==4)
     outtextxy(maxx,maxy,"4");
     if(k==5)
     outtextxy(maxx,maxy,"5");
     if(k==6)
     outtextxy(maxx,maxy,"6");
     if(k==7)
     outtextxy(maxx,maxy,"7");
     if(k==8)
     outtextxy(maxx,maxy,"8");
     if(k==9)
     outtextxy(maxx,maxy,"9");
     delay(1);
	     }

     while(!kbhit());

   closegraph();
   return 0;
}

