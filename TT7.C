main()
{
char s[]="haveA";
char t[]="NiceDay";
char u[200];
char *ss=s,*tt=t,*uu=u;
while(*ss || *tt)
{
	while(*ss)
	{
	if((*uu++=*ss++)==' ')
	break;
	}
	while(*tt)
	{
	if((*uu++=*tt++)==' ')
	break;
	}
}
*uu='\0';
puts(u);
}


