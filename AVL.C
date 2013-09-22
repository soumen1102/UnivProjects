/* Create AVL Binary TREE */
/* AVL_TREE.C */

# include<stdio.h>
# include<malloc.h>
# include<conio.h>

# define F 0
# define T 1

struct NODE
{
	char Info;
	int Flag;
	struct  NODE *Left_Child;
	struct  NODE *Right_Child;
};

struct NODE *Binary_Tree (char , struct NODE *, int *);
void Output(struct NODE *, int );
struct  NODE *Balance_Right_Heavy(struct NODE *, int *);
struct NODE *Balance_Left_Heavy(struct NODE *, int *);
struct NODE *DELETE(struct NODE *, struct NODE *, int *);
struct NODE *Delete_Element(struct NODE *, char , int *);
void preorder(struct NODE *show,int x,int y,char b,int h);
void layout(int x1,int y1,int x2,int y2,int ccb,int cct);
int univflag;

/* Function to insert an element into tree */

struct NODE *  Binary_Tree (char Info, struct NODE *Parent, int *H)
{
	struct NODE *Node1;
	struct NODE *Node2;
	if(!Parent)
	{
		Parent = (struct NODE *) malloc(sizeof(struct NODE));
		Parent->Info = Info;
		Parent->Left_Child = NULL;
		Parent->Right_Child = NULL;
		Parent->Flag = 0;
		*H = T;
		return (Parent);
	}

	if(Info < Parent->Info)
	{
		Parent->Left_Child = Binary_Tree(Info, Parent->Left_Child, H);
		if(*H)
		/* Left branch has grown higher */
		{
			switch(Parent->Flag)
			{
			case 1: /* Right heavy */
				Parent->Flag = 0;
				*H = F;
				break;
			case 0: /* Balanced tree */
				Parent->Flag = -1;
				break;
			case -1: /* Left heavy */
				Node1 = Parent->Left_Child;
				if(Node1->Flag == -1)
				{
					//printf("\n Left to Left Rotation\n");
					Parent->Left_Child= Node1->Right_Child;
					Node1->Right_Child = Parent;
					Parent->Flag = 0;
					Parent = Node1;
				}
				else
				{
					//printf("\n Left to right rotation\n");
					Node2 = Node1->Right_Child;
					Node1->Right_Child = Node2->Left_Child;
					Node2->Left_Child = Node1;
					Parent->Left_Child = Node2->Right_Child;
					Node2->Right_Child = Parent;
					if(Node2->Flag == -1)
						Parent->Flag = 1;
					else
						Parent->Flag = 0;
					if(Node2->Flag == 1)
						Node1->Flag = -1;
					else
						Node1->Flag = 0;
					Parent = Node2;
				}

				Parent->Flag = 0;
				*H = F;
			}
		}
	}

	if(Info > Parent->Info)
	{
		Parent->Right_Child = Binary_Tree(Info, Parent->Right_Child, H);
		if(*H)
		/* Right branch has grown higher */
		{
			switch(Parent->Flag)
			{
			case -1: /* Left heavy */
				Parent->Flag = 0;
				*H = F;
				break;
			case 0: /* Balanced tree */
				Parent->Flag = 1;
				break;

			case 1: /* Right heavy */
				Node1 = Parent->Right_Child;
				if(Node1->Flag == 1)
				{
					printf("\n Right to Right Rotation\n");
					Parent->Right_Child= Node1->Left_Child;
					Node1->Left_Child = Parent;
					Parent->Flag = 0;
					Parent = Node1;
				}
				else
				{
					printf("\n Right to Left Rotation\n");
					Node2 = Node1->Left_Child;
					Node1->Left_Child = Node2->Right_Child;
					Node2->Right_Child = Node1;
					Parent->Right_Child = Node2->Left_Child;
					Node2->Left_Child = Parent;

					if(Node2->Flag == 1)
						Parent->Flag = -1;
					else
						Parent->Flag = 0;
					if(Node2->Flag == -1)
						Node1->Flag = 1;
					else
						Node1->Flag = 0;
					Parent = Node2;
				}

				Parent->Flag = 0;
				*H = F;
			}
		}
	}
	return(Parent);
}

/* Output function */

void Output(struct NODE *Tree,int Level)
{
	int i;
	if (Tree)
	{
		Output(Tree->Right_Child, Level+1);
		printf("\n");
		for (i = 0; i < Level; i++)
			printf("   ");
		printf("%c", Tree->Info);
		Output(Tree->Left_Child, Level+1);
	}
}

/* Balancing Right Heavy */

struct NODE * Balance_Right_Heavy(struct NODE *Parent, int *H)
{
	struct NODE *Node1, *Node2;

	switch(Parent->Flag)
	{
	case -1:
		Parent->Flag = 0;
		break;

	case 0:
		Parent->Flag = 1;
		*H= F;
		break;

	case 1: /* Rebalance */
		Node1 = Parent->Right_Child;
		if(Node1->Flag >= 0)
		{
			printf("\n Right to Right Rotation\n");
			Parent->Right_Child= Node1->Left_Child;
			Node1->Left_Child = Parent;
			if(Node1->Flag == 0)
			{
				Parent->Flag = 1;
				Node1->Flag = -1;
				*H = F;
			}
			else
			{
				Parent->Flag = Node1->Flag = 0;
			}
			Parent = Node1;
		}
		else
		{
			printf("\n Right to Left Rotation\n");
			Node2 = Node1->Left_Child;
			Node1->Left_Child = Node2->Right_Child;
			Node2->Right_Child = Node1;
			Parent->Right_Child = Node2->Left_Child;
			Node2->Left_Child = Parent;

			if(Node2->Flag == 1)
				Parent->Flag = -1;
			else
				Parent->Flag = 0;
			if(Node2->Flag == -1)
				Node1->Flag = 1;
			else
				Node1->Flag = 0;
			Parent = Node2;
			Node2->Flag = 0;
		}
	}
	return(Parent);
}

/* Balancing Left Heavy */

struct NODE * Balance_Left_Heavy(struct NODE *Parent, int *H)
{
	struct NODE *Node1, *Node2;

	switch(Parent->Flag)
	{
	case 1:
		Parent->Flag = 0;
		break;

	case 0:
		Parent->Flag = -1;
		*H= F;
		break;

	case -1: /*  Rebalance */
		Node1 = Parent->Left_Child;
		if(Node1->Flag <= 0)
		{
			printf("\n Left to Left Rotation\n");
			Parent->Left_Child= Node1->Right_Child;
			Node1->Right_Child = Parent;
			if(Node1->Flag == 0)
			{
				Parent->Flag = -1;
				Node1->Flag = 1;
				*H = F;
			}
			else
			{
				Parent->Flag = Node1->Flag = 0;
			}
			Parent = Node1;
		}
		else
		{
			printf("\n Left to Right Rotation\n");
			Node2 = Node1->Right_Child;
			Node1->Right_Child = Node2->Left_Child;
			Node2->Left_Child = Node1;
			Parent->Left_Child = Node2->Right_Child;
			Node2->Right_Child = Parent;

			if(Node2->Flag == -1)
				Parent->Flag = 1;
			else
				Parent->Flag = 0;

			if(Node2->Flag == 1)
				Node1->Flag = -1;
			else
				Node1->Flag = 0;
			Parent = Node2;
			Node2->Flag = 0;
		}
	}
	return(Parent);
}

/* Replace the node at which key is found with last right key of a left child */

struct NODE * DELETE(struct NODE *R, struct NODE *Temp, int *H)
{
	struct NODE *Dnode = R;
	if( R->Right_Child != NULL)
	{
		R->Right_Child = DELETE(R->Right_Child, Temp, H);
		if(*H)
			R = Balance_Left_Heavy(R, H);
	}
	else
	{
		Dnode = R;
		Temp->Info = R->Info;
		R = R->Left_Child;
		free(Dnode);
		*H = T;
	}
	return(R);
}

typedef struct NODE node;
void main()
{
	struct NODE *root,*temp1,*temp2;
	int temp,cht=0,mk,xx,yy,flag=0,h;
	char ch,info;
	char choice[10][10]={"DELETE",
			     "ROTATE",
			     "INSERT",
			     "EXIT"
			     };
	//root=(struct NODE *)malloc(sizeof(node));
	//root->left=NULL;
	//root->right=NULL;
	temp1=NULL;
	//temp2=root;
	clrscr();
	system("cls");
	layout(2,1,78,25,15,15);
	gotoxy(10,4);
	textcolor(12);
	cprintf("AVL TREE ");
	gotoxy(30,7);
	textcolor(15);
	cprintf("Enter the root element : ");
	fflush(stdin);
	scanf("%c",&info);
	temp1=Binary_Tree(info,temp1,&h);
	printf("%u",temp1);
	temp1->Left_Child=NULL;
	temp1->Right_Child=NULL;
	temp2=temp1;
	while(1)
	{
		layout(2,1,78,25,15,15);
		gotoxy(30,7);
		cprintf("enter the element : ");
		scanf("%c",&info);
		temp1=Binary_Tree(info,temp1,&h);
		gotoxy(30,9);
		printf("any more element : Y / N ");
		fflush(stdin);
		ch=toupper(getch());
		if(ch=='N')
		{
			break;
		}
		clrscr();
	}
     clrscr();
     layout(2,1,78,25,15,15);
     gotoxy(10,4);
     textcolor(12);
     cprintf("AVL TREE ");
     preorder(temp1,25,5,' ',0);
     getch();

}


void preorder(struct NODE *show,int x,int y,char b,int h)
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
 if(show->Info!=NULL)
 cprintf(" %c ",show->Info);
 nodes++;
 gotoxy(5,23);
 cprintf("NODES : %2d",nodes);
 gotoxy(x1+h,x2-1);
 textcolor(YELLOW);
 textbackground(0);
 cprintf("%c",b);
 preorder(show->Left_Child,x=x-5,++y,'/',2);
 preorder(show->Right_Child,x+=10,y++,'\\',-1);
 }
 if(show->Left_Child==NULL && show->Right_Child==NULL)
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
