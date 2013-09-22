main()
{
int ch;
while(1)
{
ch=getch();
printf("%d %c\n",ch,ch);
if(ch==27)
exit(2);
}
}
