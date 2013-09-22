#include<dos.h>
void main()
{
while(!kbhit())
{
sound(950000);
//delay(50);
nosound();
delay(1);
}
}