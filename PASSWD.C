#include <conio.h>

int main(void)
{
   char *password;
   clrscr();
   password = getpass("Input a password:");
   cprintf("The password is: %s\r\n", password);
   return 0;
}

