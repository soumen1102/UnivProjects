#include<stdio.h>
void main()
{
int i=10,*j;
float k=1.50,*l;
j=&i;
l=&k;
clrscr();
printf("the value of i = %d\n",*j);
printf("the address of i = %x\n",j);
printf("the value of k = %f\n",*l);
printf("the address of k = %x\n",l);
}