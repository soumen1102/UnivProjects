#include<stdio.h>
#include<conio.h>
#include<string.h>
#define NULL 0
struct class{
	     char name[40];
	     long int roll;
	     struct class *next;
	     };

typedef struct class node;

void create(node *record);
void display(node *record);

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
char u;
fflush(stdin);
printf("enter the name");
scanf("%[^\n]",record->name);
printf("enter the rollno");
fflush(stdin);
scanf("%ld",&record->roll);
fflush(stdin);
printf("want to enter more data");
printf("type y for yes & n for no");
fflush(stdin);
scanf("%c",&u);
if (u=='y')
{
record->next=(node*)malloc(sizeof(node));
create(record->next);}
else
record->next=NULL;
}

void display(node *record)
{
printf("%s",record->name);
printf("\n%ld",record->roll);
if(record->next!=NULL)
display(record->next);
}
