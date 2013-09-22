//to calculate the number of characters, lines,blank spaces and vowels in text.
#include<stdio.h>
#include<conio.h>
void main()
{
char *str,*temp;
int nc=0,nl=1,nw=1,nv=0;
clrscr();
gotoxy(2,2);
str=(char *)malloc(1);
temp=str;
textcolor(LIGHTRED);
cprintf(" terminate the text with CTRL+Z.. hit enter ");
gotoxy(5,5);
	while((*str++=getchar())!=EOF);
	 str=temp;
	 while((*str++)!=EOF)
	 {
			 if(*str=='\n')
			{
			nl++;
			nc--;
			}
			if(toupper(*str)=='A' || toupper(*str)=='E' || toupper(*str)=='I' || toupper(*str)=='O' || toupper(*str)=='U')
			  {
			  nv++;
			  }
				 if(*str==' ' || *str=='\t')
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

