/* to claculate H.C.F of two numbers */
#include<stdio.h>
void main()
{
int a,b,c,rem;
clrscr();
printf("\n\t\tEnter the first number : ");
scanf("%d",&a);
printf("\n\n\t\tEnter the second number : ");
scanf("%d",&b);
if(b>a)
{
c=b;
b=a;
a=c;
}
rem=b%a;
while(rem!=0)
{
  b=a;
  a=rem;
  rem=b%a;
}
printf("\n\n\t\tThe H.C.F is %d .",a);
getch();
}