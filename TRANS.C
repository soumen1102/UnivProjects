void main()
{
static int arr[3][3]={1,2,3,4,5,6,7,8,9},i,j,temp;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
printf(" %d ",arr[i][j]);
printf("\n");
}
printf("\n\t TRANSPOSE \n");
for(i=0;i<2;i++)
for(j=2;j>0;j--)
if(i!=j)
{
temp=arr[i][j];
arr[i][j]=arr[j][i];
arr[j][i]=temp;
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
printf(" %d ",arr[i][j]);
printf("\n");
}
}