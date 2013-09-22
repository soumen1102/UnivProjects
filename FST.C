#include<dos.h>
#include<stdlib.h>
main()
{
int i,j=1;
char *temp,ch='A';
char far *mem1=0xb8000000,*mem;
*mem=0xb8000000;
while(!kbhit())
{
randomize();
j=rand() % 80;
mem1=(0xb8000000 + (2*j));
*temp=ch++;
 for(i=0;i<24;i++)
 {
  mem1=mem1+160;
 *(mem1)=*temp;
  delay(100);
  *(mem1)=' ';
 }
 *(mem1)=*temp;
 }
 getch();
}
