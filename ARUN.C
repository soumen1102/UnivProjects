/* problem 1 : solution*/
#include<stdio.h>
struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
};

typedef struct tree node;

void preorder(node *root,int *arr);
void postorder(node *root,int *arr);
void inorder(node *root,int *arr);

void main()
{
	node *root,*temp1,*temp2;
        static int i=0,arr1[100],arr2[100],arr3[100];
	char ch,t[3];
	root=(node *)malloc(sizeof(node));
	root->left=NULL;
	root->right=NULL;
	temp1=root;
	clrscr();
	gotoxy(10,4);
	textcolor(12);
	cprintf("BINARY SEARCH TREE ");
	gotoxy(30,7);
	textcolor(15);
	cprintf("Enter the root element : ");
	fflush(stdin);
	scanf("%d",&root->info);
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
	}
	again:
	clrscr();
	printf("\n\tenter the first mode of traversal: (I/P/O)");
	scanf("%c",&t[0]);
	fflush(stdin);
	printf("\n\tenter the second mode of traversal:(I/P/O)");
	scanf("%c",&t[1]);
	if(t[0]==t[1])
		goto again;
	for(i=0;i<2;i++)
		{
			switch(toupper(t[i]))
				{
					case'I':
					inorder(temp1,arr1);
					break;
					case'P':
					preorder(temp1,arr2);
					break;
					case'O':
					postorder(temp1,arr3);
					break;
				}
		}
       i=0;
       printf("\n INORDER");
       while(arr1[i]!=NULL)
		{
			printf(" %d ",arr1[i++]);
		}
       i=0;
       printf("\n PREORDER");
       while(arr2[i]!=NULL)
		{
			printf(" %d ",arr2[i++]);
		}
       i=0;
       printf("\n POSTORDER");
       while(arr3[i]!=NULL)
		{
			printf(" %d ",arr3[i++]);
		}
		i=0;
		if(arr1[i] && arr2[i])
		{
			while(arr1[i]!=NULL)
				{
					if(arr1[i]==arr2[i+1])
					   if(arr2[i]==arr1[i+1])
						{
							printf("\nordered pair is %d <-> %d \n",arr1[i],arr1[i+1]);
						}
					   i++;
				}
			getch();
			exit(1);
		}
		i=0;
		if(arr1[i] && arr3[i])
		{
			while(arr1[i]!=NULL)
				{
					if(arr1[i]==arr3[i+1])
					   if(arr3[i]==arr1[i+1])
						{
							printf("\nordered pair is %d <-> %d ",arr1[i],arr1[i+1]);
						}
					   i++;
				}
			getch();
			exit(1);
		}
		i=0;
		if(arr2[i] && arr3[i])
		{
			while(arr2[i]!=NULL)
				{
					if(arr2[i]==arr3[i+1])
					   if(arr3[i]==arr2[i+1])
						{
							printf("\nordered pair is %d <-> %d ",arr2[i],arr2[i+1]);
						}
					   i++;
				}
			getch();
			exit(1);
		}
     getch();
}


void inorder(node *root,int *arr)
{
static int i=0;
if(root)
  {
	inorder(root->left,arr);
	*(arr+i++)=root->info;
	inorder(root->right,arr);
  }
}

void preorder(node *root,int *arr)
{
static int i=0;
if(root)
  {
	*(arr+i++)=root->info;
	preorder(root->left,arr);
	preorder(root->right,arr);
  }
}

void postorder(node *root,int *arr)
{
static int i=0;
if(root)
  {
	postorder(root->left,arr);
	postorder(root->right,arr);
	*(arr+i++)=root->info;
  }
}
