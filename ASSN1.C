// to arrange the numbers in ascending order and descending order :1(a)(b)
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
void main()
{
  int *n,*tp,i=0,j=0,k=0,temp,h,it;
  char an='Y',x;
  n=(int *)malloc(1);
  tp=n;
	while(toupper(an)=='Y')
	{
	clrscr();
	gotoxy(5,5);
	textcolor(LIGHTGRAY);
	cprintf("enter the number :");
	textcolor(CYAN);
	cscanf("%d",n);
	n++;
	i++;
	textcolor(LIGHTGRAY);
	gotoxy(5,7);
	cprintf("another number y/n...?  ");
	fflush(stdin);
	an=getchar();
	}
	fflush(stdin);
	n=tp;
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
		for(j=0;j<i;j++)
		 for(k=j+1;k<i;k++)
		  if(*(n+j)> *(n+k))
		   {
		    temp=*(n+j);
		    *(n+j)=*(n+k);
		    *(n+k)=temp;
		   }
		}
	      else
	      if(x=='D')
		{
		for(j=0;j<i;j++)
		 for(k=j+1;k<i;k++)
		   if(*(n+j)> *(n+k))
		   {
		    temp=*(n+j);
		    *(n+j)=*(n+k);
		    *(n+k)=temp;
		   }
		}
	      else
	       {
		printf("don'nt play games with me , re run the program");
		 exit();
	       }

	  gotoxy(5,10);
	  cprintf(" the numbers in the sorted order are :");
	  n=tp;
	   for(h=0;h<i;h++)
	    {
	      printf(" %d ",*(n+h));
	    }
	    getch();
	    gotoxy(5,19);
	    cprintf(" press any key to exit... ");
	    while(!kbhit());
	    system("cls");
}


