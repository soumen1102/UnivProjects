//to calculate  nCr
#include<conio.h>
#include<stdio.h>
#define GR textcolor(LIGHTGRAY);
#define CY textcolor(CYAN);
long double fact(int n);
void main()
{
 int n,r,c;
 long double nf,nrf,nr;
  while(1)
 {
 clrscr();
 gotoxy(5,5);
 GR;
 cprintf("enter the value of 'n' :");
 CY;
 fflush(stdin);
 cscanf("%d",&n);
 gotoxy(5,7);
 GR;
 cprintf("enter the value of 'r' :");
 CY;
 fflush(stdin);
 cscanf("%d",&r);
 if(n<0 || n<r || r<0 ||r==966)
{
gotoxy(5,6);
textcolor(RED);
cprintf("Invalid input ,please enter them properly.");
//printf(" %d %c",r,r);
n=0;
r=0;
}
 nf=fact(n);
 nr=fact(r);
 nrf=fact(n-r);
 gotoxy(5,9);
 cprintf(" the result is %.2Lf ",nf/(nr*nrf));
 fflush(stdin);
 gotoxy(5,15);
 printf("press any key and hit enter to continue or hit enter to QUIT ....");
 //getch();
 while(!kbhit());
 c=getchar();
 if(c==10)
 exit();
 else
 continue;

 }
 }
	long double fact(int n)
	{
	long double temp=1.0;
	while(n>0)
	{
	temp=temp*n;
	n--;
	}
	return(temp);
	}
