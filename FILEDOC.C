
/*     Assignment Question no. 2 */






#include<stdio.h>
#include<string.h>
#include<alloc.h>




struct node
  {
    char a[10];
    int lineno[10];
    int index;
    struct node *link;
   };

void store(struct node *,char [20],int);
void display(struct node *);
void main(void)

{
  FILE *fp;
  char c[20];
  char b;
  int i,j,l=0;
  struct node *first,*x;
  clrscr();
  fp=fopen("abc.txt","r+");

  j=1;
  fscanf(fp,"%s",c);
  x=(struct node *)malloc(sizeof(struct node));
  strcpy(x->a,c);
  x->lineno[0]=j;
  x->index=0;
  x->link=NULL;
  first=x;
  fseek(fp,1,SEEK_CUR);

  while(!feof(fp))
    {
      fscanf(fp,"%s",c);
      b=fgetc(fp);
      if ((b=='\n')||(b==' '))
	{
	  store(first,c,j);
	  if (b==' ') l++;
	  if (b=='\n') j++;
	}
    }
   fclose(fp);
   display(first);

}

/* creation of node and storing the value in the link list */

void store(struct node *first,char c[20],int j)
{
 struct node *n,*ptr;
 int k;

 ptr=first;

 while((ptr->link!=NULL)&&(strcmpi(c,ptr->a)!=0))
    ptr=ptr->link;


 if ((ptr->link==NULL)&&(strcmpi(c,ptr->a)!=0))
    {
      n=(struct node *)malloc(sizeof(struct node));
      n->link=NULL;
      k=0;
      strcpy(n->a,c);
      n->lineno[k]=j;
      n->index=k;
      ptr->link=n;
      strcpy(c,"  ");
    }

  if ((strcmpi(c,ptr->a)==0))
   {
     (ptr->index)++;
     ptr->lineno[ptr->index]=j;
   }
 return;
}

/* display the actual list  */

void display(struct node *first)
{
 struct node *ptr;
 int i;

 ptr=first;
 while (ptr!=NULL)
  {
    printf("\n");
    for(i=0;i<strlen(ptr->a);i++)
      printf("%c",ptr->a[i]);
    printf(":");
    for(i=0;i<=ptr->index;i++)
      {
	printf("\n line no.%d ",ptr->lineno[i]);
      }
    printf("\n");
    ptr=ptr->link;
  }
}