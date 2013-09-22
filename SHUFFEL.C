#include<stdio.h>
#include<conio.h>
void main()
{
char *message,*p;
int i,x,c1,c=0,flag=0,dd=0;
	clrscr();
	     gotoxy(5,2);
	     printf(" left to right and right to left message scrolling ");
	     gotoxy(10,4);
	     textcolor(LIGHTGRAY);
	     cprintf(" TYPE THE MESSAGE : ");

	     message =malloc(200);
	     p=message;
	     while(( *message=getchar())!='\n')
	     {
		  message++;
		  c++;
		  if(c>79)
		  {
		  printf("more than I can handle I QUIT ");
		  getch();
		  exit();
		  }
	     }
		  *message=NULL;
		  sorry:
		  gotoxy(5,5);
		  cprintf("colors available");
		  printf("\n");
		  for(i=1;i<=15;i++)
		  {
		  textcolor(i);
		  cprintf(" COLOUR %d ",i);
		  printf("\n");
		  }
		  printf("enter the corresponding number : ");
		  scanf("%d",&i);
		  if(i>15 || i<1)
		  {
		  printf(" not valid number..try again ");
		  getch();
		  clrscr();
		  goto sorry;
		  }
		  printf(" select scrolling speed (1-FASTEST 10-SLOWEST) ");
		  scanf("%d",&dd);
		  if(dd>10 || dd<1)
		  dd=5;
		  clrscr();
		     c1=80-c;
		     c1=c1/2;
		     x=c1;
		     while(!kbhit())
			{
			     gotoxy(1,1);
			     textcolor(WHITE);
			     cprintf("hit any key to exit");
			     textcolor(i);
			     gotoxy(x,12);
			     cprintf("%s",p);

			     if(x+c==80 && flag==1)
			     {
			     flag=0;
			     }
			     if(x>1 && flag==0)
			     x--;
			     if(x==1 && flag==0)
			     {
			     flag=1;
			     x++;
			     }
			     if(x+c<80 && flag==1)
			     {
			     x++;
			     }
			     delay(dd*50);
			     clrscr();
			}
				system("cls");
			textcolor(LIGHTGRAY);
		      }

