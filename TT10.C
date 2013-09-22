main()
{
int a[20],i=2,j=3;
a[2]=9;
a[3]=13;
a[i]=j+i++;

printf("\n%d %d",a[2],a[3]);
printf("\n%d %d",a[i],i);
}

