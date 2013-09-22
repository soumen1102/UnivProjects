/*to calculate the binary equivalent of a decimal number*/
#include<conio.h>

void main()
{
int num,*bin,i=0;

 clrscr();
 gotoxy(25,3);
 textcolor(LIGHTGREEN);
 cprintf("DECIMAL TO BINARY CONVERTER");
 textcolor(LIGHTGRAY);
 gotoxy(5,5);
  cprintf("enter the number : ");
  textcolor(CYAN);
  cscanf("%d",&num);
  if(num<0)
  {
  gotoxy(5,7);
  textcolor(RED);
  cprintf("the number you entered is negative,the negative sign is being ignored");
  num=num*(-1);
  }
    while(num>0)
     {
       *bin=num%2;
	num=num/2;
	bin++;
	i++;
     }
     textcolor(LIGHTGRAY);
     gotoxy(5,11);
     cprintf("the binary equivalent of the number is:");
     textcolor(CYAN);
     bin--;
    while(i>0)
     {
       cprintf(" %d ",*bin);
       bin--;
       i--;
     }
     gotoxy(5,15);
     printf("press any key to exit....");
     while(!kbhit());
}


