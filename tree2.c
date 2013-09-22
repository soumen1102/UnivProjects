/*binary threaded tree application */

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct tree{
	int info;
	struct tree *left;
	struct tree *right;
	int thread;
	   };

typedef struct tree node;

void inorder(node *,int ct);

void main()
{
node *root,*temp,*prev1,*temp2;
int tem,ct=0;
char more;

root=(node *)malloc(sizeof(node));
clrscr();
gotoxy(5,5);
cprintf("Enter the root element : ");
scanf("%d",&root->info);
root->left=NULL;
root->right=NULL;
root->thread=1;
temp=root;
prev1=root;
while(1)
	{
	    clrscr();
	    gotoxy(5,5);
	    ct++;
	    cprintf("Enter the element: ");
	    scanf("%d",&tem);

	    while(root!=NULL && prev1->thread==0)
		 {
		  if(tem>=root->info)
			{
			prev1=root;
			root=root->right;
			}
		 else if(tem<root->info)
			{
			prev1=root;
			root=root->left;
			}
		  }

	    root=(node *)malloc(sizeof(node));

	    if(prev1->info>tem)
		{
			root->info=tem;
			prev1->left=root;
			root->right=prev1;
			root->left=NULL;
			root->thread=1;
		}
	    else if(prev1->info<=tem)
		{
			temp2=prev1->right;
			prev1->thread=0;
			root->info=tem;
			root->left=NULL;
			prev1->right=root;
			root->thread=1;
			root->right=temp2;
		}

	    gotoxy(5,7);
	    cprintf("any other element Y/N ");
	    fflush(stdin);
	    more=getch();
	    if(toupper(more)=='N')
		{
			break;
		}

	    root=temp;
	    }
	    inorder(temp,ct);
	    getch();
}

void inorder(node *start,int ct)
{
node *p,*q;
p=start;
q=start;
do
   {
	q=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->left;
	}

	if(q!=NULL)
	{
		printf("\n%d %d",q->info,q->thread);
		ct--;
		p=q->right;
		while(q->thread && p!=NULL)
		{
			printf("\n%d %d",p->info,p->thread);
			ct--;
			q=p;
			p=p->right;
		}
	 }
    }while(q!=NULL);
}