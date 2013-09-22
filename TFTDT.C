#include<tellar.h>
#include<conio.h>
#include<stdio.h>
  struct entity{

  char name[50];
   long int accno;

	struct trans{
	char parti[40];
	long int amt[1][2];
	}tt;

   }et;

 void main()
 {
    FILE *tp,*pt;

    tp=fopen("temp.rec","a+");

 }