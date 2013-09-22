#include<stdio.h>
#include<string.h>
void main()
{
char names[100][20],temp[50],addr[100][40];
int ch=0,c,j=0,i=0,num=0;
clrscr();
printf("\n\tstart entering the names  ");
	while(1)
	{
	printf("\n\tenter the name: ");
	gets(names[i]);
	printf("\tenter the address: ");
	gets(addr[i]);
	printf("\t\t\t\t\tpress 1 to finish ");
	i++;
	fflush(stdin);
	ch=getch();
	if(ch=='1')
	break;
	}
	 for(c=0;c<i;c++)
	  for(j=c+1;j<i;j++)
	  {
	   num=strcmpi((names+c),(names+j));
	   if(num>0)
	   {
	   strcpy(temp,(names+c));
	   strcpy((names+c),(names+j));
	   strcpy((names+j),temp);
	   strcpy(temp,(addr+c));
	   strcpy((addr+c),(addr+j));
	   strcpy((addr+j),temp);
	   }
	  }
	  printf("\nThe names in sorted order are ");
	   for(c=0;c<i;c++)
	   {
	   printf("\n\t%s \t%s",*(names+c),*(addr+c));
	   }
	   getch();
}