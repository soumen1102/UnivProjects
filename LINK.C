#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list{
char name[40];
long int phone;
struct list *next;
};

typedef struct list node;

void main()
{
node *origin;
node *disply;
char choice;
origin=(node *)malloc(sizeof(node));
disply=origin;
     clrscr();
     while(1)
     {
     printf("\n\tenter the name ");
     fflush(stdin);
     gets(origin->name);
     printf("\n\tenter the phone number ");
     fflush(stdin);
     scanf("%ld",&origin->phone);
     printf("\n\tNAME : %s ",origin->name);
     printf("\n\tPHONE : %ld ",origin->phone);
     printf("\n\n\t\tmore...y/n");
     fflush(stdin);
     choice=getchar();
     if(toupper(choice)=='N')
     {
     origin->next=0;
     break;
     }
     origin->next=(node *)malloc(sizeof(node));
     origin=origin->next;
     clrscr();
     }
     getch();
     while(1)
     {
     clrscr();
     printf("\n\tNAME : %s ",disply->name);
     printf("\n\tPHONE : %ld ",disply->phone);
     getch();
     if(disply->next==NULL)
     exit(0);
     disply=disply->next;
     fflush(stdin);
     }
}