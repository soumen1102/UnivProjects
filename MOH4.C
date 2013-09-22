#include<conio.h>
#include<string.h>
#include<stdio.h>
void main(int argc,char *argv[])
{
FILE *fp;
char ch,file[20];
static int nl,nc,nw,nv;
if(argc<2)
{
clrscr();
printf("$ ");
scanf("%s",file);
fp=fopen(file,"rb+");
if(fp==NULL)
printf("cannot open the file......");
argv[1]=file;
}
if(argc>=2)
{
fp=fopen(argv[1],"rb+");
if(fp==NULL)
printf("cannot open the file......");
}
while((ch=(char )fgetc(fp))!=EOF)
	 {
			 if(ch=='\n')
			{
			nl++;
			nc--;
			}
			if(toupper(ch)=='A' || toupper(ch)=='E' || toupper(ch)=='I' || toupper(ch)=='O' || toupper(ch)=='U')
			  {
			  nv++;
			  }
				 if(ch==' ' || ch=='\t')
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
		cprintf(" the number of characters in the file %s are: %d",argv[1],nc);
			textcolor(RED );
			gotoxy(15,21);
			cprintf(" the number of lines in the file %s are : %d ",argv[1],nl);
		textcolor(MAGENTA);
		gotoxy(15,22);
		cprintf(" the number of words in the file %s are : %d ",argv[1],nw);
		textcolor(YELLOW);
		gotoxy(15,23);
		cprintf(" the number of vovels in the file %s are : %d ",argv[1],nv);
	 textcolor(WHITE);
	 fflush(stdin);
	 while(!kbhit());
}