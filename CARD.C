#include<stdio.h>
#include<conio.h>
void main()
{
while(!kbhit())
{
sleep(4);
printf("\a");
}
}