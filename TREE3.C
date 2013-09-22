#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
	char balance;
};

typedef struct tree node;

void preorder(node *show,int x,int y,char b,int h);
void layout(int x1,int y1,int x2,int y2,int ccb,int cct);
void delete(node *root);
void rotate(node *root);
void insertavl(node *root,int *tall,int *value);
void insert();
int univflag;

void main()
{
	node *root,*temp1,*temp2;
	int temp,cht=0,mk,xx,yy,flag=0,tall=1,tem;
	char ch;
	char choice[10][10]={"DELETE",
			     "ROTATE",
			     "INSERT",
			     "EXIT"
			     };
	root=NULL;
       //	root->left=NULL;
       //	root->right=NULL;
       //	temp1=root;
	clrscr();
	system("cls");
	layout(2,1,78,25,15,15);
	gotoxy(10,4);
	textcolor(12);
	cprintf("AVL TREE ");
	gotoxy(30,7);
	textcolor(15);
	//cprintf("Enter the root element : ");
	fflush(stdin);
	scanf("%d",&tem);
	while(1)
	{
		gotoxy(30,9);
		printf("any more element : Y / N ");
		fflush(stdin);
		ch=toupper(getch());
		if(ch=='N')
		{
			root->left=NULL;
			root->right=NULL;
			break;
		}
		root=temp1;
		clrscr();
		layout(2,1,78,25,15,15);
		gotoxy(25,7);
		cprintf("enter the element : ");
		fflush(stdin);
		scanf("%d",&temp);
		insertavl(root,&tall,&tem);

	}
	clrscr();
	gotoxy(30,1);
	textcolor(LIGHTGRAY);
	cprintf("BINARY SEARCH TREE");
	preorder(temp1,25,5,' ',0);
    gotoxy(15,25);
    textcolor(YELLOW);
    textbackground(CYAN);
    cprintf("%s",choice[0]);
    gotoxy(25,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[1]);
    gotoxy(35,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[2]);
    gotoxy(45,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[3]);

	xx=15;
    while(2)
    {
		fflush(stdin);
		mk=getch();
		if(mk==9)
		{
			gotoxy(xx,25);
			textbackground(RED);
			cprintf("%s",choice[cht]);
			if(flag==0)
			{
				cht++;
				xx+=10;
				if(cht==3)
					flag=1;
				gotoxy(xx,25);
				textbackground(CYAN);
				textcolor(YELLOW);
				cprintf("%s",choice[cht]);
				continue;
			}
			if(flag==1)
			{
				cht--;
				xx-=10;
				if(cht==0)
					flag=0;
				gotoxy(xx,25);
				textbackground(CYAN);
				textcolor(YELLOW);
				cprintf("%s",choice[cht]);
				continue;
			}
		}
		if(mk==13)
		{
			  if(cht==0)
			  {
				  delete(temp1);
				  system("cls");
				  gotoxy(30,1);
				  textcolor(LIGHTGRAY);
				  textbackground(0);
				  cprintf("BINARY SEARCH TREE");
				  univflag=0;
				  preorder(temp1,25,5,' ',0);
				  gotoxy(15,25);
				  textcolor(YELLOW);
				  textbackground(RED);
				  cprintf("%s",choice[0]);
				  gotoxy(25,25);
				textcolor(YELLOW);
				textbackground(RED);
				cprintf("%s",choice[1]);
				gotoxy(35,25);
				textcolor(YELLOW);
				textbackground(RED);
				cprintf("%s",choice[2]);
				gotoxy(45,25);
				textcolor(YELLOW);
				textbackground(RED);
				cprintf("%s",choice[3]);

      continue;
      }
      if(cht==1)
      {
      clrscr();
      system("cls");
      rotate(temp1);
      gotoxy(30,1);
      textcolor(LIGHTGRAY);
      textbackground(0);
      univflag=0;
      cprintf("BINARY SEARCH TREE");
      preorder(temp1,25,5,' ',0);
    gotoxy(15,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[0]);
    gotoxy(25,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[1]);
    gotoxy(35,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[2]);
    gotoxy(45,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[3]);

      continue;
      }
      if(cht==2)
      {
      insert(temp1);
      gotoxy(30,1);
      textcolor(LIGHTGRAY);
      textbackground(0);
      univflag=0;
      cprintf("BINARY SEARCH TREE");
      preorder(temp1,25,5,' ',0);
    gotoxy(15,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[0]);
    gotoxy(25,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[1]);
    gotoxy(35,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[2]);
    gotoxy(45,25);
    textcolor(YELLOW);
    textbackground(RED);
    cprintf("%s",choice[3]);

      continue;
      }
      if(cht==3)
      exit(3);
     }
     }
}

void preorder(node *show,int x,int y,char b,int h)
{
 static int k,nodes,leaves;
 int x1,x2;
 if(univflag==0)
 {
 k=0;
 nodes=0;
 leaves=0;
 univflag=1;
 }
 x1=x+k++;
 x2=y++;
 if(show!=NULL)
 {
 delay(300);
 gotoxy(x1,x2);
 textcolor(15);
 textbackground(RED);
 cprintf(" %d ",show->info);
 nodes++;
 gotoxy(5,23);
 cprintf("NODES : %2d",nodes);
 gotoxy(x1+h,x2-1);
 textcolor(YELLOW);
 textbackground(0);
 cprintf("%c",b);
 preorder(show->left,x=x-5,++y,'/',2);
 preorder(show->right,x+=10,y++,'\\',-1);
 }
 if(show->left==NULL && show->right==NULL)
 {
 leaves++;
 textcolor(15);
 textbackground(RED);
 gotoxy(5,24);
 cprintf("LEAVES: %2d",leaves);
 }
}

void layout(int x1,int y1,int x2,int y2,int ccb,int cct)
{
int i,j;
window(x1,y1,x2,y2);
textmode(3);
textcolor(cct);
gotoxy(x1,y1);
cprintf("%c",218);
gotoxy(x1,y2);
cprintf("%c",192);
gotoxy(x2,y1);
cprintf("%c",191);
gotoxy(x2,y2);
cprintf("%c",217);
for(i=x1+1;i<x2;i++)
{
gotoxy(i,y1);
cprintf("%c",196);
}
for(i=x1+1;i<x2;i++)
{
gotoxy(i,y2);
cprintf("%c",196);
}
for(i=y1+1;i<y2;i++)
{
gotoxy(x1,i);
cprintf("%c",179);
gotoxy(x2,i);
cprintf("%c",179);
}
}
void delete(node *root)
{
	int del;
	node *prev,*temp2,*temp1;
	clrscr();
	system("cls");
	printf("Enter the element you wish to delete: ");
	scanf("%d",&del);

	while(root!=NULL)
	{
		if(del>root->info)
		  {
			prev=root;
			root=root->right;
		  }
		else if(del<root->info)
		  {
			prev=root;
			root=root->left;
		  }
		else
		break;
	}
	 if(prev->info<del)
	 {
		if(root->right==NULL && root->left==NULL)
		{
			prev->right=root->right;
		}
		else
		{
			if(root->right!=NULL)
			{
				temp1=root->left;
				prev->right=root->right;
				root=root->right;
				while(root!=NULL)
					{
					temp2=root;
					root=root->left;
					}
				temp2->left=temp1;
			}
		}
	  }
	  if(prev->info>del)
	  {
		if(root->left==NULL && root->right==NULL)
		{
			prev->left=root->left;
		}
		else
		{
			if(root->left!=NULL)
			{
				temp1=root->right;
				prev->left=root->left;
				root=root->left;
				while(root!=NULL)
					{
					temp2=root;
					root=root->right;
					}
				temp2->right=temp1;
			}
		}
	  }
	  return(0);
    }




void rotate(node *root)
{
  node *temp;
   if(root!=NULL)
   {
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    rotate(root->left);
    rotate(root->right);
   }
}

void insert(node *root)
{
int temp;
clrscr();
system("cls");

layout(2,1,78,25,15,15);
gotoxy(25,7);
cprintf("enter the element : ");
fflush(stdin);
scanf("%d",&temp);
while(2)
{
if(temp>=root->info)
{
 if(root->right==NULL)
 {
  root->right=(node *)malloc(sizeof(node));
  root=root->right;
  root->info=temp;
  root->left=NULL;
  root->right=NULL;
  break;
 }
 root=root->right;
}
if(temp<root->info)
{
 if(root->left==NULL)
 {
  root->left=(node *)malloc(sizeof(node));
  root=root->left;
  root->info=temp;
  root->left=NULL;
  root->right=NULL;
  break;
 }
 root=root->left;
}
}
clrscr();
system("cls");
}

void insertavl(node *root,int *tall,int *value)
{
node *prev;

	if(root->left==NULL && root->right==NULL)
	{
		if(root->info<*value)
		{
			root->left=(node *)malloc(sizeof(node));
			root=root->left;
			root->info=*value;
			root->left=NULL;
			root->right=NULL;
			root->balance='E';
			*tall=1;
			return(0);
	}
	else if(root->info>value)
		{
			insertavl(root->left,&tall,&value);

			if(*tall)
				{
					if(root->balance=='E')
						{
							root->balance='L';
							*tall=1;
						}
					if(root->balance=='R')
						{
							root->balance='E';
							*tall=0;
						}

				}
			*tall=0;
		}
	else if(root->info<=value)
		{
			insertavl(root->right,&tall,&value);
			if(*tall)
				{
					if(root->balance=='L')
						{
							root->balance='E';
							*tall=1;
						}
					if(root->balance=='E')
						{
							root->balance='R';
							*tall=0;
						}
				}
			*tall=0;
		}
}
