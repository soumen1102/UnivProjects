main()
{
static int a[]={97,98,99,100,101,102,103,104};
int *pt=a+1;
printf("\n\n%u %d",pt,*pt);
ppt(++pt,pt--,pt,pt++,pt++);
}
ppt(int *a,int *b,int *c,int *d,int *e)
{
printf("\t %d %d %d %d %d",*a,*b,*c,*d,*e);
}