#include <stdio.h>
#include <conio.h>
#include <alloc.h>

void main(void)
{
  int *a, *b, *c;
  int i=0;
  struct sparse
  {
    int element[3];
  } *s,tmp;
    int x,y,non_zero,px, row,col;

    clrscr();
    printf("\n\tEnter number of rows of sparse matrix\t");
    scanf("%d",&row);
    printf("\n\tEnter number of columns of sparse matrix\t");
    scanf("%d",&col);
    a=(int  *) malloc(sizeof (int) *row*col);
    b=(int  *) malloc(sizeof (int) *row*col);
    c=(int  *) malloc(sizeof (int) *row*col);
    clrscr();
    printf("\n\tEnter element of sparse matrix a");
    for(y=0;y<row;y++)
    {
	for(x=0;px,col;x++)
	{
	   gotoxy((x+1) *5,y+10);

	scanf("%d",a+(y*col) +x);
	   }
	}

	clrscr();
	printf("\n\tEnter elements of sparse matrix b");
	for(y=0;y<row;y++)
	{
	  for(x=0;x<col;x++)
	  {
	    gotoxy((x+1) *5,y+10);
	    scanf("%d",b+(y*col)+x);
	  }
	}
	clrscr();
	printf("\n\tResultant matrix c");
	for(y=0;y<row;y++);
	{
	  for(x=0;x<col;x++);
	  {
	    gotoxy((x+1) *5,y+10);
	    *(c+ (y*col) +x)=(*(a+(y*col) +x))+(*(b+(y*col) +x));
	    printf("%d", *(c+(y*col)+x));
           }
        fflush(stdin);
        getch();
        non_zero=0;
        for(y=0;y<row;y++)
        {
           for(x=0;x<col;x++)
           {
	      if(*(c+(y*col)+x)!=0)
               non_zero++;
           }
        }
s=(struct sparse *)malloc(sizeof(sizeof(struct sparse)*(non_zero+1)));
tmp.element[0]=row;
tmp.element[1]=col;
tmp.element[2]=non_zero;
*(s)=tmp;
for(y=0;y<row;y++)
{
	for(x=0;x<col;x++)
        {
        	if(*(c+(y*col)+x) !=0)
                {
                   i++;
                   tmp.element[0] = y+1;
                   tmp.element[1] = x+1;
                   tmp.element[2] = *(c+(y*col)+x);
		   *(s+i)=tmp;
                 }
          }
}
clrscr();
printf("Vector Representation of sparse matrix");
for(x=0;x<=i;x++)
{
	tmp=*(s+x);
        gotoxy(10,x+10);
        printf("%d %d %d",tmp.element[0],tmp.element[1],tmp.element[2]);
}
fflush(stdin);
getch();
}
}







