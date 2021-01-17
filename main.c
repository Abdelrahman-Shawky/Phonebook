#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "phonebookfinal.h"

int main()
{
    int cnt;
    cnt=count();
    contact person;
    contact *Pperson;
    Pperson=&person;
    Pperson=malloc(50*sizeof(contact));
    load(Pperson);
    menu(Pperson,&cnt);
    return 0;
}
