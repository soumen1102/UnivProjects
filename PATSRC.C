#include<ctype.h>
void main()
{
char sr[1000],cha[20],*p;
printf("enter ");
gets(sr);
printf("\n\aenter the string");
gets(cha);
p=strpbrk(sr,cha);
puts(p);
}
