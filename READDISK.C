#include<dos.h>
union REGS i,o;
int *buffer;
main()
{
   static int ah,al;
   ah=readdisk();
   al=readdisk();
   printf(" %x %x ",ah,al);
   getch();
}
readdisk()
{
  i.h.ah=0x02;
  i.h.al=0x01;
  i.x.cx=0x00;
  i.x.dx=0x00;
  i.x.bx=buffer;
  int86(13,&i,&o);
}