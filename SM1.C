#include<stdio.h>
#include<conio.h>
#define CAV toupper(c)
void main()
{
char c;
int nc=0,nl=1,nw=1,nv=0;
clrscr();
gotoxy(2,2);
textcolor(LIGHTRED);
cprintf(" terminate the text with CTRL+Z.. hit enter ");
gotoxy(5,5);
	while((c=getchar())!=EOF)
		{
			 if(c=='\n' || c=='.')
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
		}
		textbackground(BLACK);
		textcolor(CYAN);
		gotoxy(15,20);
		cprintf(" the number of characters in the above input are: %d",nc);
			textcolor(RED );
			gotoxy(15,21);
			cprintf(" the number of lines in the above input are : %d ",nl);
		textcolor(MAGENTA);
		gotoxy(15,22);
		cprintf(" the number of words in the above input are : %d ",nw);
		textcolor(YELLOW);
		gotoxy(15,23);
		cprintf(" the number of vovels in the above input are : %d ",nv);
	 textcolor(WHITE);
	 fflush(stdin);
	 while(!kbhit());
}

