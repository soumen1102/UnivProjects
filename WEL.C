#include <graphics.h>
#include<dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


void draw_arrow(int x, int y);
int az=5;
int main(void)
{
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode,f=1,t=0;
   void *arrow;
   int x, y, maxx,maxy ;
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


   maxx = getmaxx();
   maxy = getmaxy();
   x = 0;
   y = getmaxy()/2;

  // setbkcolor(LIGHTGRAY);
   setcolor(YELLOW);

   /* draw the image to be grabbed */
   draw_arrow(x, y);

   /* calculate the size of the image */
   size = imagesize(x, y-az, x+(4*az), y+az);

   /* allocate memory to hold the image */
   arrow = malloc(size);
     /* grab the image */
   getimage(x, y-az, x+(4*az), y+az, arrow);

   /* repeat until a key is pressed */
  while(!kbhit())
  {	 /* erase old image */
	  putimage(x, y-az, arrow, XOR_PUT);

      x +=az;
      if (x >= maxx)
      {
	  x = 0;
      }

	  delay(100);
	  az++;
	  x++;
	  y++;
      /* plot new image */
      putimage(x, y-az, arrow, XOR_PUT);
       delay(100);


   }

   /* clean up */
   free(arrow);
   closegraph();
   return 0;
}

void draw_arrow(int x, int y)
{
   /* draw an arrow on the screen */
   moveto(x, y);
   linerel(4*az, 0);
   linerel(-2*az, -1*az);
   linerel(0, 2*az);
   linerel(2*az, -1*az);
}
