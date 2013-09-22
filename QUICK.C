#include<stdio.h>
#include<conio.h>

void layout(int x1,int y1,int x2,int y2,int ccb,int cct);
void main()
{
static int arr[40],st,ed,n,i,up[40],lp1[40],tp,lp;
char ch;
clrscr();
layout(2,2,78,25,15,15);
	while(2)
	{
	gotoxy(25,4);
	textcolor(LIGHTRED);
	cprintf("Q U I C K  S O R T  O P E R A T I O N");
	gotoxy(35,7);
	textcolor(WHITE);
	cprintf("Enter the %d number :            ",n+1);
	gotoxy(57,7);
	scanf("%d",&arr[i]);
	i++;
	n++;
	gotoxy(25,11);
	cprintf("\n another number ");
	ch=getch();
	if(toupper(ch)=='N')
	{
	n--;
	break;
	}
	}

	clrscr();
tp=0;

if(n>1)
{
   tp++;
   lp1[1]=0;
   up[1]=n;
}
   while(tp!=0)
   {
     st=lp1[tp];
     ed=up[tp];
     tp--;
     lp=quicksort(arr,n,st,ed);
     if(st<lp-1)
     {
     tp++;
     lp1[tp]=st;
     up[tp]=lp-1;
     }
     if(ed>lp+1)
     {
     tp++;
     lp1[tp]=lp+1;
     up[tp]=ed;
     }
     }
      gotoxy(30,3);
      cprintf("sorting completed      \a");
      getch();
      system("cls");
}

	quicksort(int arr[40],int n,int st,int ed)
	    {
		int left , right ,lp,temp,i;
		left=st;
		right=ed;
		lp=st;
		layout(2,2,78,7,15,15);
		gotoxy(30,3);
		cprintf("Sorting in progress");
		gotoxy(5,5);

	   while(1)
	   {
		while( arr[lp]<=arr[right] && lp!=right )
		 {
		 right--;
		 gotoxy(5,5);
		 for(i=0;i<=n;i++)
		{
		 if(i==lp)
		 textbackground(CYAN);
		 else
		 textbackground(0);
		 cprintf("  %d  ",arr[i]);
		 delay(100);
		}
		 }

		if(lp==right)
		return(lp);

		if(arr[lp]>arr[right])
		{
		   temp=arr[lp];
		   arr[lp]=arr[right];
		   arr[right]=temp;
		   lp=right;
		 gotoxy(5,5);
		 for(i=0;i<=n;i++)
		{
		 if(i==lp)
		 textbackground(CYAN);
		 else
		 textbackground(0);
		 cprintf("  %d  ",arr[i]);
		 delay(100);
		}
		}

		while( arr[lp]>=arr[left] && lp!=left )
		 {
		  left++;
		  gotoxy(5,5);
		 for(i=0;i<=n;i++)
		{
		 if(i==lp)
		 textbackground(CYAN);
		 else
		 textbackground(0);
		 cprintf("  %d  ",arr[i]);
		 delay(100);
		}
		  }

		if(lp==left)
		return(lp);

		if(arr[lp]<arr[left])
		{
		   temp=arr[lp];
		   arr[lp]=arr[left];
		   arr[left]=temp;
		   lp=left;
		   gotoxy(5,5);
		 for(i=0;i<=n;i++)
		{
		 if(i==lp)
		 textbackground(CYAN);
		 else
		 textbackground(0);
		 cprintf("  %d  ",arr[i]);
		 delay(100);
		}
		}

	    }
	}

void layout(int x1,int y1,int x2,int y2,int ccb,int cct)
{
int i,j;
window(x1,y1,x2,y2);
textmode(3);
textcolor(cct);
gotoxy(x1,y1);
cprintf("%c",218);
gotoxy(x1,y2);
cprintf("%c",192);
gotoxy(x2,y1);
cprintf("%c",191);
gotoxy(x2,y2);
cprintf("%c",217);
for(i=x1+1;i<x2;i++)
{
gotoxy(i,y1);
cprintf("%c",196);
}
for(i=x1+1;i<x2;i++)
{
gotoxy(i,y2);
cprintf("%c",196);
}
for(i=y1+1;i<y2;i++)
{
gotoxy(x1,i);
cprintf("%c",179);
gotoxy(x2,i);
cprintf("%c",179);
}
}