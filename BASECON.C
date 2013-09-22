/*to calculate the equivalent of a decimal number in any BASE TILL 16*/
#include<conio.h>
#include<stdio.h>

int hex(int temp);
void main()
{
int num,i=0,temp,nbase;
char *bin;

 clrscr();
 gotoxy(30,3);
 textcolor(LIGHTGREEN);
 cprintf("BASE COVERSION TILL 16");
 textcolor(LIGHTGRAY);
 gotoxy(5,5);
  cprintf("enter the number  in BASE 10 : ");
  textcolor(CYAN);
  cscanf("%d",&num);
  gotoxy(5,6);
  textcolor(LIGHTGRAY);
  cprintf("enter the new base : ");
  textcolor(CYAN);
  cscanf("%d",&nbase);
  if(num<0)
  {
  gotoxy(5,7);
  textcolor(RED);
  cprintf("the number you entered is negative,the negative sign is being ignored");
  num=num*(-1);
  }
    while(num>0)
     {
	temp=num%nbase;
	   if(nbase==16 && temp>9)
	     temp=hex(temp);
	  *bin=temp;
	num=num/nbase;
	bin++;
	i++;
     }
     textcolor(LIGHTGRAY);
     gotoxy(5,11);
     cprintf("the equivalent of the number in BASE %d is: ",nbase);
     textcolor(CYAN);
     bin--;
    while(i>0)
     {
       if(*bin<65)
       cprintf("%d",*bin);
       if(*bin>=65)
       cprintf("%c",*bin);
       bin--;
       i--;
     }
     gotoxy(5,15);
     fflush(stdin);
     printf("press enter to exit....");
      getchar();
}
	     int hex(int temp)
	       {
		 if(temp==10)
		 return(65);
		 if(temp==11)
		 return(66);
		 if(temp==12)
		 return(67);
		 if(temp==13)
		 return(68);
		 if(temp==14)
		 return(69);
		 if(temp==15)
		 return(70);
	       }




