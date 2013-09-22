#include<stdio.h>
#include<malloc.h>
void get(void);
struct test
{
char *name;
int age;
};
struct test tt;
void main()
{
tt.name=malloc(200);
get();
printf(" %c %d",*tt.name,tt.age);
getch();
}
void get(void)
{
scanf("%s",*tt.name);
scanf("%d",&tt.age);
}
