#include <stdio.h>
main()
{

struct mystruct
{
  int i;
  char ch;
}e;
FILE *pt ;
pt=fopen("a.c","a");
e.i=500;
e.ch='d';
fprintf(pt,"\n %d \t\t %c",e.i,e.ch);
fclose(pt);
}