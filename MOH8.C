#include<conio.h>
#include<string.h>
#include<stdio.h>
void main(int argc,char *argv[])
{
FILE *fp1,*fp2,*tp;
char ch,file1[20],file2[20];
static int nl,nc,nw,nv;
if(argc<3)
{
clrscr();
printf("$ ");
scanf("%s%s",file1,file2);
fp1=fopen(file1,"rb+");
fp2=fopen(file2,"rb+");
if(fp1==NULL || fp2==NULL)
{
printf("cannot open both or one of the file......");
exit(1);
}
argv[1]=file1;
argv[2]=file2;
}
if(argc>=2)
{
fp1=fopen(argv[1],"rb+");
fp2=fopen(argv[2],"rb+");
if(fp1==NULL || fp2==NULL)
printf("cannot open both or one of the file......");
exit(1);
}
tp=fopen("joined.txt","wb");
while((ch=getc(fp1))!=EOF)
fputc(ch,tp);
while((ch=getc(fp2))!=EOF)
fputc(ch,tp);
ch=EOF;
fputc(ch,tp);
fclose(fp1);
fclose(fp2);
fclose(tp);
system("edit joined.txt");
}