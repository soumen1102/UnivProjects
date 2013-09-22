#include<stdio.h>
#include<malloc.h>
void get(void);
struct test
{
char *name;
int *age;
};
struct test *tt;
void main()
{
tt->name=malloc(100);
tt->age=malloc(100);
get();
printf("\n %s %u",tt->name,tt->name);
printf("\n\t %d %u",*tt->age,tt->age);
getch();
}
void get(void)
{
scanf("%s",tt->name);
scanf("%d",tt->age);
}
