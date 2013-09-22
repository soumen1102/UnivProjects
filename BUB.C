// to arrange the numbers in ascending order and descending order :1(a)(b)
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
void main()
{
  int n[90],i=0,j=0,k=0,temp,h,it;
  char an='Y',x;

	while(toupper(an)=='Y')
	{
	clrscr();
	gotoxy(5,5);
	textcolor(LIGHTGRAY);
	cprintf("enter the number :");
	textcolor(CYAN);
	cscanf("%d",&n[i]);
	i++;
	textcolor(LIGHTGRAY);
	gotoxy(5,7);
	cprintf("another number y/n...?  ");
	fflush(stdin);
	an=getchar();
	}
	fflush(stdin);
	textcolor(LIGHTGRAY);
	gotoxy(5,8);
	cprintf(" Arrange the numbers in ascending or descending order : A/D  ...?");
	scanf("%c",&x);
	it=x;

	    x=toupper(x);
	      if(x=='A'|| it==10)
		{
		textcolor(WHITE);
		if(it==10)
		cprintf(" By default Ascending ");
		textcolor(CYAN);

	     /* selection sort method */

		for(j=0;j<i;j++)
		 for(k=0;k<i-1;k++)
		  if(n[k] > n[k+1])
		   {
		    temp=n[k];
		    n[k]=n[k+1];
		    n[k+1]=temp;
		   }
		}
	      else
	      if(x=='D')
		{
		for(j=0;j<i;j++)
		 for(k=0;k<i;k++)
		  if(n[k] < n[k+1])
		  {
		   temp=n[k];
		   n[k]=n[k+1];
		   n[k+1]=temp;
		  }
		}
	      else
	       {
		printf("don'nt play games with me , re run the program");
		 exit();
	       }

	  gotoxy(5,10);
	  cprintf(" the numbers in the sorted order are :");
	   for(h=0;h<i;h++)
	    {
	      printf(" %d ",n[h]);
	    }
	    getch();
	    gotoxy(5,19);
	    cprintf(" press any key to exit... ");
	    while(!kbhit());
	    system("cls");
}


