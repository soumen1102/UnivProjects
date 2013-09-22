#include<stdio.h>
void testing(void);
char sh;
 void main()
{
	
	 printf("the old grey fox jumped over the lazy dog\n\n");
	 getch();
	 testing();
}


		void testing(void)
		{
             while((sh=getch())!='x')
                 printf("*");
					return(0);
		}