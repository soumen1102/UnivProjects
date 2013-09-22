void main()
{
long double num,temp,hit1;
int x=70;
char hit;

clrscr();
hit=getch();
hit1=hit*1.0;
temp=hit1-48.0;
//printf("%",hit1);
num=temp;
gotoxy(x,5);
printf("%12.2Lf",num);
while((hit=getch())!='x')
{
 clrscr();
 hit1=hit*1.0;
 temp=hit1*1.0-48.0;
 num=num*10.0+temp;
 //x--;
 gotoxy(x,5);
 printf("%12.2Lf",num);
}
}