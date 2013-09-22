
#include <stdio.h>
#include <alloc.h>
#include <string.h>

int main(void)
{
   char *str;

   /* allocate memory for string */
   str = (char *) malloc(10);

   /* copy "Hello" into string */
   strcpy(str, "Hello");
   str+=2;
   strcpy(str,"namaskar");

   printf("String is %s\n  Address is %p\n", str, str);
   str = (char *) realloc(str, 20);
   printf("String is %s\n  New address is %p\n", str, str);

   /* free memory */
   free(str);

   return 0;
}