#include<dos.h>
main()

{
char *arr="rhombus";
int i,j=0;
system("cls");
while(j<6)
{
for (i=0;i<=7;i++)
{
printf("%s",*arr);
arr++;
}
printf("\n");
j++;
}
}