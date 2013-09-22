void main()
{
int f;
union
	 {
	  float i;
	  char ch[3];
	  } hey;
	  hey.i=256;
	  clrscr();
	  printf("\n%f",hey.i);
	  for(f=0;f<4;f++)
	  printf("\n%c",hey.ch[f]);

	  }