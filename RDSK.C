#include<dos.h>
union REGS i,o;
int *buffer;
main()
{
   static int ah,al;
   ah=readdisk();
   al=readdisk();
   printf("%d ",al);
   getch();
}
readdisk()
{
  i.h.ah=0x02;
  i.h.al=0x01;
  i.x.cx=0x00;
  i.x.dx=0x00;
  i.h.dl=0x03;
  i.x.bx=buffer;
  int86(13,&i,&o);
  return(i.h.al);
}