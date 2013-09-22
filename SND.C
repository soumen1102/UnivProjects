#include<dos.h>
void asm1(void);
char *start;
union REGS i,o;
int x;
main()
{
int ch;
asm1();
ch=getch();

}
void asm1(void)
{
asm mov ah,0x0C;
asm mov al,0x50;
asm mov CX,0x22;
asm mov BX,0x24;
asm mov BH,0x22;
asm int 0x10;
getch();
/*asm mov dh,0x16;
asm mov dl,0x28;
asm int 0x10;
asm mov ah,0x02;
asm mov al,0x01;
asm mov ch,0x00;
asm mov cl,0x02;
asm mov dh,0x08;
asm mov dl,0x00;
i.x.bx=start;
asm int 0x13;*/
}
