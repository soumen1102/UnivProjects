#include<stdio.h>
void main()
{
	int i=3;
	int *j;

	j = &i;
	printf("Address of i =%d\n",&i);
	printf("Address of i =%d\n",j);
	printf("Address of j =%d\n",&j);
	printf("Value of j = %d\n",j);
	printf("Value of i = %d\n",i);
	printf("Value of i = %d\n",*(&i));
	printf("Value of i = %d\n",*j);
 }