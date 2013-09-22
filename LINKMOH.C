#define NULL 0
struct list_element{
	 char item[4];
	 struct list_element *next;
	 };

typedef struct list_element node;

void create(node *pt);
void display(node *pt);

void main()
{
node *start;
start=(node*)malloc(sizeof(node));
create(start);
printf("\n");
display(start);
}

void create(node *record)
{
printf("data item (type \'END\'when finished):");
scanf("%[^\n]",record->item);
if(strcmp(record->item,"END")==0)
record->next=NULL;
else
{record->next=(node*)malloc(sizeof(node));
create(record->next);}
}

void display(node *record)
{
if(record->next!=NULL)
{
printf("%s\n",record->item);
display(record->next);
}
return;
}

