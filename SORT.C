#include <stdio.h>
#include <math.h>
#include <conio.h>
void main()
{

int a[8],i,j,min=0,p=0,temp=0;
clrscr();
for(i=0;i<=7;++i)
{

printf("\nenter the %d no.",i);
scanf("%d",&a[i]);
}
for(i=0;i<=8;i++)
{
min=a[i];

for (j=i;j<=8;++j)
{
if(a[j]<min) {
	       min=a[j];
	       p=j;
	     }
}
temp=a[i];
a[i]=min;
a[p]=temp;
}
for(i=0;i<=7;++i)
printf("\nthe no=%d",a[i]);
}