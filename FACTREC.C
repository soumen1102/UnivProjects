int facto(int x);

void main()
{
int *res,num;
scanf("%d",&num);
*res=facto(num);
printf("%d",*res);
}
int facto(int x)
{
static int fact=1;
if(x==1)
return(fact);
fact=x*facto(x-1);
}
