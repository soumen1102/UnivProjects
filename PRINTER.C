//to calculate the number of characters, lines,blank spaces and vowels in text.
#include<stdio.h>
#include<conio.h>
void main()
{
char c;
int nc=0,nl=1,nw=1,nv=0,d=0;
clrscr();
gotoxy(2,2);
textcolor(LIGHTRED);
cprintf(" terminate the text with CTRL+Z.. hit enter ");
gotoxy(1,5);
	while((c=getchar())!=EOF)
		{
			 if(c=='\n')
			{
			nl++;
			nc--;
			}
			if(toupper(c)=='A' || toupper(c)=='E' || toupper(c)=='I' || toupper(c)=='O' || toupper(c)=='U')
			  {
			  nv++;
			  }
				 if(c==' ' || c=='\t')
				{
				nw++;
				nc=nc+0;
				}
			else
			nc++;
			fprintf(stdprn,"%c",c);
		}
		textbackground(BLACK);
		textcolor(CYAN);
		gotoxy(15,20);
		cprintf(" the number of characters in the above input are: %d",nc);
		fprintf(stdprn,"\n\tthe number of characters in the above input are: %d",nc);
			textcolor(RED );
			gotoxy(15,21);
			cprintf(" the number of lines in the above input are : %d ",nl);
			fprintf(stdprn,"\n\t the number of lines in the above input are : %d ",nl);
		textcolor(MAGENTA);
		gotoxy(15,22);
		cprintf(" the number of words in the above input are : %d ",nw);
		fprintf(stdprn,"\n\t the number of words in the above input are : %d ",nw);
		textcolor(YELLOW);
		gotoxy(15,23);
		cprintf(" the number of vovels in the above input are : %d ",nv);
		fprintf(stdprn,"\n\t the number of vovels in the above input are : %d ",nv);
	 textcolor(WHITE);
	 fflush(stdin);
	 while(!kbhit());
}

