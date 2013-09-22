#include<conio.h>
#include<dos.h>
#include<stdio.h>
void seg(int x,int y,int i);
int getkey(void);
void main()
{
int s1=0,s2=0,m1=0,m2=0,h1=0,h2=0,x=22,k=0,sm=0,t;
char *n="DIGITAL CLOCK : ENTER THE CURRENT TIME";

   clrscr();
   gotoxy(x,2);
   textcolor(LIGHTGREEN);
      while(*n!=NULL)
	{
	  cprintf("%c",*n);
	   n++;
	   x++;
	   sound(950);
	   delay(50);
	   nosound();
	 }

	    gotoxy(50,23);
		textcolor(LIGHTGRAY);
		cprintf("use arrow keys to set time");
		  while(1)
		    {
			gotoxy(35,5);
			cprintf("%d",h1);
			gotoxy(36,5);
			cprintf("%d",h2);
			gotoxy(37,5);
			cprintf(":%d",m1);
			gotoxy(39,5);
			cprintf("%d",m2);
			gotoxy(35,5);

			      k=getkey();

				if(k==28)
				break;

			if(k==72)
			  {
			     gotoxy(35,5);
			     textcolor(GREEN);
			     cprintf("%d",h1);
			     h1++;
			     if(h1==3)
			     h1=0;
			  }

	 textcolor(LIGHTGREEN);

			if(k==80)
			  {
			     gotoxy(35,5);
			     textcolor(GREEN);
			     cprintf("%d",h1);
			     h1--;
			     if(h1<0)
			     h1=2;
			  }
	 textcolor(LIGHTGREEN);

			 if(k==77)
			   {
			     sm=1;
				while(1)
				   {
				      gotoxy(36,5);
				      textcolor(GREEN);
				      cprintf("%d",h2);
				      gotoxy(36,5);

					k=getkey();
					  if(k==72)
					    {
					      h2++;
					      if(h2==10)
					      h2=0;
					      if(h1==2 && h2>=4)
					      h2=0;
					    }

					  if(k==80)
					    {
					      h2--;
					      if(h2<0)
					      h2=9;
					      if(h1==2 && h2==9)
					      h2=3;
					   }

					  if(k==77)
					  break;
				  }

			 if(k==77 && sm==1)
			   {
			       while(1)
				  {
					  sm=2;
					  gotoxy(38,5);
					  cprintf("%d",m1);
					  gotoxy(38,5);

					    k=getkey();

					      if(k==72)
						{
						 m1++;
						 if(m1==6)
						 m1=0;
						}
					      if(k==80)
						{
						 m1--;
						 if(m1<0)
						 m1=5;
						}
					      if(k==77)
					      break;
				  }
			 if(k==77 && sm==2)
			    {
				while(1)
				   {
					      gotoxy(39,5);
					      textcolor(GREEN);
					      cprintf("%d",m2);
					      gotoxy(39,5);

					      k=getkey();
					      if(k==72)
						{
						 m2++;
						 if(m2==10)
						 m2=0;
						}
					      if(k==80)
						{
						 m2--;
						    if(m2<0)
						    m2=9;
						}
					      if(k==77)
					      break;
				   }
			   }
		   }

  textcolor(LIGHTGREEN);
	}
  }
  /*corrrecting for variaable mismatch ,the programme being written on
   different days. */
	t=h1;
	  h1=h2;
	    h2=t;
	t=m1;
	  m1=m2;
	    m2=t;

  clrscr();
 /* initial display of time set by user */

 seg(30,12,h2);//higher order hour
 seg(33,12,h1);//lower order hour
 seg(37,12,m2);//higer order min
 seg(40,12,m1);//lower order min
 seg(44,12,s2);//higher order second
 seg(47,12,s1);//lower order second

    /* continue as long as there is no key hit */

	while(!kbhit())

	  {
sound(600);
gotoxy(36,12);
textcolor(WHITE);
cprintf("_");
delay(2);
nosound();
gotoxy(36,12);
sleep(1);
textcolor(BLACK);
cprintf("_");
//delay(500);
gotoxy(36,12);
textcolor(WHITE);
cprintf("_");
delay(2);
s1++;
if(s1==10)
{
s1=0;
s2++;
seg(44,12,s2);
seg(47,12,s1);
}
if(s2==6)
{
s2=0;
m1++;
seg(44,12,s2);
seg(47,12,s1);
seg(40,12,m1);
}
if(m1==10)
{
m1=0;
m2++;
seg(44,12,s2);
seg(47,12,s1);
seg(40,12,m1);
seg(37,12,m2);
}
if(m2==6)
{
m2=0;
h1++;
if(h2==2 && h1==4)
{
h2=0;
h1=0;
}
seg(44,12,s2);
seg(47,12,s1);
seg(40,12,m1);
seg(37,12,m2);
seg(33,12,h1);
seg(30,12,h2);
}
if(h1==10)
{
h1=0;
h2++;
seg(44,12,s2);
seg(47,12,s1);
seg(40,12,m1);
seg(37,12,m2);
seg(33,12,h1);
seg(30,12,h2);
}
seg(47,12,s1);
}
}
void seg(int x,int y,int i)
{

/*array declaration for all the digits*/

int num[11][7]={	  {1,0,1,1,1,1,1},
			  {0,0,0,1,0,0,1},
			  {0,1,1,1,1,1,0},
			  {0,1,1,1,0,1,1},
			  {1,1,0,1,0,0,1},
			  {1,1,1,0,0,1,1},
			  {1,1,1,0,1,1,1},
			  {0,0,1,1,0,0,1},
			  {1,1,1,1,1,1,1},
			  {1,1,1,1,0,1,1},
			  {1,1,1,1,1,1,1}
		};

/* symbols to be displayed */

char v='|',h='_';
/*deleting the previous symbol*/

textcolor(BLACK);
gotoxy(x,y);
if(num[10][0]==1)
cprintf("%c",v);
gotoxy(x+1,y);
if(num[10][1]==1)
cprintf("%c",h);
gotoxy(x+1,y-1);
if(num[10][2]==1)
cprintf("%c",h);
gotoxy(x+2,y);
if(num[10][3]==1)
cprintf("%c",v);
gotoxy(x,y+1);
if(num[10][4]==1)
cprintf("%c",v);
gotoxy(x+1,y+1);
if(num[10][5]==1)
cprintf("%c",h);
gotoxy(x+2,y+1);
if(num[10][6]==1)
cprintf("%c",v);
/* disolaing the present symbol*/

textcolor(LIGHTMAGENTA);
gotoxy(x,y);
if(num[i][0]==1)
cprintf("%c",v);
gotoxy(x+1,y);
if(num[i][1]==1)
cprintf("%c",h);
gotoxy(x+1,y-1);
if(num[i][2]==1)
cprintf("%c",h);
gotoxy(x+2,y);
if(num[i][3]==1)
cprintf("%c",v);
gotoxy(x,y+1);
if(num[i][4]==1)
cprintf("%c",v);
gotoxy(x+1,y+1);
if(num[i][5]==1)
cprintf("%c",h);
gotoxy(x+2,y+1);
if(num[i][6]==1)
cprintf("%c",v);

}
/* returns the scan code of the hit key */

int getkey(void)
		{
		    union REGS i,o;
		    while(!kbhit())
		    {
		    i.h.ah=0;
		    int86(22,&i,&o);
		    return(o.h.ah);
		    }
		}
