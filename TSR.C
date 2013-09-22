#include<dos.h>
#include<stdlib.h>
void interrupt our(void);
void interrupt(*prev)();
char far *mem= 0xb8000001L;

main()
{
unsigned long int far *ptr;
ptr=(char far *)36;
prev=*ptr;
*ptr=our;
our();
keep(0,500);
}
void interrupt our(void)
{
int i,j=1;
sound(5000);
delay(2);
for(i=0;i<=3999;i+=2)
{
*(mem)=j++;
mem=mem+2;
if(j==15)
j=1;
}
nosound();
(*prev)();
}
