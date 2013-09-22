#define EXCHANGE(x,y) x=x+y;y=x-y;x=x-y
void main()
{
int x,y;
scanf("%d %d",&x,&y);;;;;;
EXCHANGE(x,y);
printf("\n\n%d\t%d",x,y);
}