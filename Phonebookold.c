#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct birthdate{
    int day;
    int month;
    int year;
}birthdate;*/

typedef struct person{
    char *lastname;
    char *firstname;
   /* birthdate date;*/
    char *address;
    char *email;
    int *number;

}person;

void load(person *p){
    int i=0;
    FILE *f1;
    f1=fopen("C:\\Users\\DiDo\\Desktop\\test.txt","r");
    if(f1!=NULL){
        while(!feof(f1)){
                (p+i)->lastname=(char*)malloc(100);
            fscanf(f1,"%s",&((p+i)->lastname));
            i++;

        }
    }fclose(f1);
}

void print(person *p){
    printf("%s",(p)->lastname);
}

/*void test(person *p){
    p->lastname=(char*)malloc(100);
    strcpy(p->lastname,"ahmed");
    printf("%s",p->lastname);
    }*/


int main()
{
    person *people;
    people=malloc(1000);
    load(people);
    print(people);
    return 0;
}
