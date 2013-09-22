#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list{
char name[40];
long int phone;
struct list *next;
};

typedef struct list node;
char target[40];

void main()
{
node *origin;
node *disply;
node *insert;
node *remove;
node *previous;
node *ever;
node *add;
FILE *fp;
char choice;
int option,chk,flag=0,first;
long int size,curpos;
//fp=fopen("phone.rec","ab+");
origin=(node *)malloc(sizeof(node));
disply=origin;
insert=origin;
remove=origin;
size=sizeof(node);
if(fp==NULL)
{
printf("error cannot open the file ");
exit(0);
}
     while(2)
     {
     clrscr();
     printf("\n\t############ LINK LIST OPERATIONS MENU ############## ");
     printf("\n\n\t\t 1: CREATE ");
     printf("\n\t\t 2: DISPLAY ");
     printf("\n\t\t 3: INSERT ");
     printf("\n\t\t 4: REMOVE ");
     printf("\n\t\t 5: EXIT ");
     printf("\n");
     option=getch();
     switch(option)
     {
     case '1':
     {
     fp=fopen("phone.rec","wb+");
     origin=ever;
     while(1)
     {
     clrscr();
     printf("\n\t\t########## CREATING LINK LIST ##########");
     printf("\n\tenter the name: ");
     fflush(stdin);
     gets(origin->name);
     printf("\n\tenter the phone number: ");
     fflush(stdin);
     scanf("%ld",&origin->phone);
     printf("\n\tNAME : %s ",origin->name);
     printf("\n\tPHONE : %ld ",origin->phone);
     fwrite(origin,size,1,fp);
     printf("\n\n\t\tmore...y/n ");
     fflush(stdin);
     choice=getchar();
     if(toupper(choice)=='N')
     {
     origin->next=0;
     break;
     }
     origin->next=(node *)malloc(sizeof(node));
     origin=origin->next;
     }
     fclose(fp);
     break;
     }
     case '2':
     {
     fp=fopen("phone.rec","rb");
     disply=ever;
     while(1)
     {
     clrscr();
     fread(disply,size,1,fp);
     printf("\n\n\t ########## DISPLAYING LINKLIST ##########");
     printf("\n\tNAME : %s ",disply->name);
     printf("\n\tPHONE : %ld ",disply->phone);
     getch();
     if(disply->next==NULL)
     break;
     disply=disply->next;
     fflush(stdin);
     }
     fclose(fp);
     break;
     }
     case '3':
     {
     insert=ever;
     while(3)
     {
     clrscr();
     fp=fopen("phone.rec","ab+");
     fflush(stdin);
     printf(" \n\t\t ########## NODE INSERTION WINDOW ########## ");
     printf("\n\n the name of the person after which you wish to insert : ");
     gets(target);
     while(4)
     {
     //fread(insert,size,1,fp);
     curpos=ftell(fp);
     chk=strcmpi(insert->name,target);
     if(chk==0)
     {
     printf("\n\tmatch found.. ");
     add=(node *)malloc(sizeof(node));
     printf("\n\tenter the name : ");
     fflush(stdin);
     gets(add->name);
     printf("\n\tenter the phone number : ");
     scanf("%ld",&add->phone);
     printf("\n\tNAME : %s ",add->name);
     printf("\n\tPHONE : %ld ",add->phone);
     add->next=insert->next;
     insert->next=add;
     fseek(fp,curpos,SEEK_END);
     fwrite(insert,size,1,fp);
     getch();
     flag=1;
     }
     if(flag==1)
     break;
     //previous=insert;
     insert=insert->next;
     chk=strcmpi(insert->name,target);
     if(chk==0)
     continue;
     if(insert->next==NULL )
     {
     printf("\n\n\tmatch not found....");
     getch();
     break;
     }
     }
     printf(" \n\t want to insert another ");
     fflush(stdin);
     insert=ever;
     flag=0;
     choice=getchar();
     if(toupper(choice)=='N')
     break;
     }
     fclose(fp);
     break;
     }
     case '4':
     {
     remove=ever;
     previous=ever;
     first=0;
     while(3)
     {
     clrscr();
     fflush(stdin);
     printf(" \n\t\t ########## NODE  DELETION  WINDOW ########## ");
     printf(" Enter the name of the person whom you wish to delete : ");
     gets(target);
     while(4)
     {
     chk=strcmpi(remove->name,target);
     if(chk==0)
     {
     printf("\n\tmatch found.. ");
     if(first==0)
     {
     ever=remove->next;
     getch();
     flag=1;
     break;
     }
     if(flag==1)
     break;
     previous->next=remove->next;
     getch();
     flag=1;
     }
     if(flag==1)
     break;
     previous=remove;
     remove=remove->next;
     first=1;
     chk=strcmpi(remove->name,target);
     if(chk==0)
     continue;
     if(remove->next==NULL )
     {
     printf("\n\n\tmatch not found....");
     getch();
     break;
     }
     }
     printf(" \n\t want to remove another ");
     fflush(stdin);
     remove=ever;
     flag=0;
     choice=getchar();
     if(toupper(choice)=='N')
     break;
  }
  break;
}
     case '5':
     exit(0);
}
}
}

