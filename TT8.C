main()
{
int i,j;
system("cls");
for(i=1;i<=3;i++)
	for(j=1;j<=3;j++)
		{
		if(i+j<2)
		{
		printf("\n 1 i= %d , j= %d ",i,j);
		//continue;
		}
		else
		if(i+j<3)
		 {
		 printf("\n 2 i= %d , j= %d,continue ",i,j);
		 // continue;
		continue;
		   }
		   else
		   {
		   printf("\n3 i= %d,j=%d,break",i,j);
		   break;
		   }
		   printf("\n4 i=%d,j=%d",i,j);
		   }
		   }

