#include<stdio.h>
void main()
{
int i=0,j=0,k=0,l=0,m=0,j1=0;
char word[50],temp,temp1;
printf("tyype in the word or the grrroup  of letters:");
while((word[i]=getchar())!='\n')
i++;
clrscr();
printf("%s",&word[0]);
getch();
//exit();
k=i;
	for(;k>0;k--)
	  {
	    temp1=word[i];
	   for(j=0;j<=i-1;j++)
	      for(l=j+1;l<=i-1;l++)
	      {
	      printf("\n%s",&word[0]);
	      temp=word[l];
	      for(m=l;m<=i-1;m++)
		{
		word[m]=word[m+1];
		}
		word[i]=temp;
		getch();
	      }
	      for(j1=0;j1<i-1;j1++)
	      {
	       word[j1+1]=word[j1];
	      }
	      word[0]=temp1;
	      }
	     }



