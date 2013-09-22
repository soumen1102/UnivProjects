void fib(int c);
void main()
{
int c,i=1,j=1;
scanf("%d",&c);
if (c==1 || c==2)
{
printf(" %d %d ",i,j);
exit();
}
else
{
printf(" %d %d ",i,j);
fib(c-2);
}
}
void fib(c)
{
int t;
static int i=1,j=1;
if(c==0)
exit();
t=i;
i=i+j;
j=t;
printf("%d ",i);
fib(c-1);
}

