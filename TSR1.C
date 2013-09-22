#include<dos.h>
#include<stdlib.h>
void interrupt our(void);
void interrupt new1(void);
void interrupt(*prev)();
void interrupt(*old)();
char far *mem= 0xb8000001L;
int j=1,flag=0;
main()
{
unsigned long int far *ptr;
ptr=(char far *)36;
old=getvect(0x08);
setvect(0x08,new1);
prev=*ptr;
*ptr=our;
keep(0,1000);
}
void interrupt our(void)
{
int i,jj=1;
static char *temp,ch='A';
char far *mem1=0xb8000000,*mem2;
if(flag==1)
{
for(i=0;i<=3999;i+=2)
{
*(mem)=jj++;
mem=mem+2;
if(jj==15)
jj=1;
}
randomize();
jj=rand() % 80;
mem1=(0xb8000000 + (2*jj));
*temp=ch++;
 for(i=0;i<24;i++)
 {
  mem1=mem1+160;
 *(mem1)=*temp;
  *(mem1)=' ';
 }
 *(mem1)=*temp;
}
  flag=0;
  (*prev)();
}

void interrupt new1(void)
{
j++;
if(j==19)
{
j=1;
flag=1;
}
(*old)();
}
