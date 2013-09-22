#include <stdio.h>

int (dd)(void);
int main(void)
{
   int d=9;

   char dddd[]={"have a nice day"};
   clrscr();
   puts("you fool");
   d=dd();
   printf("%d",d);
   printf("%s",dddd);

   /*
   printf("Input a character:");
   read a character from the
   standard input stream
   ch = fgetc(stdin);
   printf("The character input was: '%d'\n", ch);
   return 0;  */
}

int (dd)(void)
{
return(45);
}