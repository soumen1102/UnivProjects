#include<stdio.h>
void main()
{
float mat1[10][10],mat2[10][10],mat3[10][10];
static int r,c,i,j;
clrscr();
printf("\n\n\n\tENTER THE NUMBER OF ROWS OF THE MATRIX : ");
scanf("%d",&r);
printf("\n\tENTER THE NUMBER OF COLOUMNS OF THE MATRIX : ");
scanf("%d",&c);
       printf("\n\tenter the elememts of the matrix : ");
      for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	  {
	    scanf("%f",&mat1[i][j]);
	  }
       printf("\n\tenter the elememts of the matrix : ");
       for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	  {
	    scanf("%f",&mat2[i][j]);
	  }

	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	  {
	    *(*(mat3 +i)+j)=*(*(mat1 +i)+j)+*(*(mat2 +i)+j);
	  }

	  printf("the sum of the matrices are :\n");
       for(i=0;i<r;i++)
	{
	  for(j=0;j<c;j++)
	  {
	    printf("%8.2f",mat1[i][j]);
	  }
	  printf("\n");
	}
     }
