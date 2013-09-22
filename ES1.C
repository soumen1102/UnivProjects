#include<stdio.h>
main()
{
     //  static float x=1,y=1,z=2;
       static int x1=3,y1=0,z1=0;
	//printf("\n%d %d %d ",x<<1,y>>1,~(x&y));
	  //x=y=z++*3;
	  y1=x1=10;
	  z1=x1<10;
	   printf("\n %d %d %d ",x1,y1,z1);
	    getch();
}


