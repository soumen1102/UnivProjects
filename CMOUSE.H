/********************************************************
*	Software	: GWPat v1.0				  *
*	Author      : N.V.Venkatarayalu			  *
*	FileName	: CMOUSE.H					  *
*	File Content: Mouse Interface Functions		  *
********************************************************/

#include<dos.h>
int DetectMouse(void);
void InitMouse(void);
void ShowMouse(void);
void HideMouse(void);
void WhereMouse(int*,int*);
int ButtClicked(void);
int  ButtReleased(void);
void NewCursor(void);


int DetectMouse(void){
	union REGS in,out;
	in.x.ax=0;
	int86(0x33,&in,&out);
	if(out.x.ax==0)
		return(0);
	else
		return(1);
 }

void InitMouse(void)
{
	union REGS in,out;
	in.x.ax=33;
	int86(0x33,&in,&out);
	return;
}

void HideMouse(void)
{
	union REGS in,out;
	in.x.ax=2;
	int86(0x33,&in,&out);
	return;
}

void ShowMouse(void)
{
	union REGS in,out;
	in.x.ax=1;
	int86(0x33,&in,&out);
	return;
}

void WhereMouse(int *x,int *y)
{
	union REGS in,out;
	in.x.ax=3;
	int86(0x33,&in,&out);
	*x=(int)out.x.cx;
	*y=(int)out.x.dx;
	return;
}

int ButtClicked(void){
	union REGS imouse,omouse;
	int mc,mr;
	imouse.x.ax = 3;
	int86(0x33,&imouse,&omouse);
	mc=omouse.x.bx;
	return(mc);
}
int ButtReleased(void){
	int br;
	br=ButtClicked();
	do{}while(ButtClicked()!=0);
	return br;
}

void NewCursor(void){
	static int pontr[]={
	0x0003, 0x0007, 0x000f, 0x001f, 
	0x003f, 0x007f, 0x00ff, 0x01ff, 
	0x03ff, 0x07ff, 0x0fff, 0x1fff, 
	0x3fff, 0x7fff, 0xffff, 0xffff, 

	0x0000, 0x7ff0, 0x7fe0, 0x7fc0, 
	0x7f80, 0x7f00, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000
	};

	union REGS regs;
	struct SREGS sregs;
	regs.x.ax=9;
	regs.x.bx=0;
	regs.x.cx=13;
	regs.x.dx=(int)pontr;
	segread(&sregs);
	sregs.es=sregs.ds;
	int86x(0x33,&regs,&regs,&sregs);
	return;
}
