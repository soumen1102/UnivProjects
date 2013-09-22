#include <stdio.h>
main()
{

struct mystruct
{
  int i;
  char ch;
}e;
FILE *pt ;
pt=fopen("a.c","w");
e.i=243;
e.ch='f';
fprintf(pt,"\n %d \t\t %c",e.i,e.ch);
fclose(pt);
}