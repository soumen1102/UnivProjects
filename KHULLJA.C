#include<stdio.h>
#include<conio.h>
void main()
{
FILE *fp;
char c,*file;
int i=0,flag=0;
printf("enter the name of the file : ");
scanf("%s",file);
fp=fopen(file,"rb");
clrscr();
      while((c=fgetc(fp))!=EOF)
      {
	printf("%c",c);
	if(c==';'&& flag==1)
	{
	getch();
	i++;
	if(i==25)
	flag=1;
	}
      }
	getch();
	fclose(fp);
}
