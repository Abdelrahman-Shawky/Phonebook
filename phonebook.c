#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct birthdate
{
    int day;
    int month;
    int year;
} birthdate;

typedef struct contact
{
    char *lastname;
    char *firstname;
    birthdate date;
    char *address;
    char *email;
    char *number;

} contact;

int count()
{
    int i=0;
    char ch;
    FILE *f1;
    f1=fopen("C:\\Users\\DiDo\\Desktop\\PHONEBOOK\\Phonebook.txt","r");
    if(f1==NULL)
    {
        printf("Error Reading File");
        return 0;
    }
    while((ch=fgetc(f1))!=EOF)
    {
        if(ch=='\n')
            i++;
    }
    fclose(f1);
    return i+1;
}

void load(contact *p)
{
    int i=0;
    FILE *f1;
    f1=fopen("C:\\Users\\DiDo\\Desktop\\PHONEBOOK\\Phonebook.txt","r");
    if(f1==NULL)
    {
        printf("Error Reading File");
        return 0;
    }
    while(!feof(f1))
    {
        (p+i)->lastname=malloc(50);
        (p+i)->firstname=malloc(50);
        (p+i)->address=malloc(50);
        (p+i)->email=malloc(50);
        (p+i)->number=malloc(50);
        fscanf(f1,"%[^,],%[^,],%d-%d-%d,%[^,],%[^,],%s\n",(p+i)->lastname,(p+i)->firstname,&((p+i)->date.day),&((p+i)->date.month),&((p+i)->date.year),(p+i)->address,(p+i)->email,(p+i)->number);
        i++;
    }
    fclose(f1);

}

void print(contact *p,int c)
{
    int i=0;
    printf("Entry\tFirstname\tLastname\tDate of Birth\tAddress\t\t\t\temail\t\t\tNumber\n");
    while(i<c+1)
    {
        if(strlen((p+i)->address)<24)
        {
            printf("%d\t",i+1);
            printf("%s\t\t",(p+i)->firstname);
            printf("%s\t\t",(p+i)->lastname);
            printf("%02d/%02d/%d\t",(p+i)->date.day,(p+i)->date.month,(p+i)->date.year);
            printf("%s\t\t",(p+i)->address);
            printf("%s\t",(p+i)->email);
            printf("%s\n",(p+i)->number);
        }
        else
        {
            printf("%d\t",i+1);
            printf("%s\t\t",(p+i)->firstname);
            printf("%s\t\t",(p+i)->lastname);
            printf("%02d/%02d/%d\t",(p+i)->date.day,(p+i)->date.month,(p+i)->date.year);
            printf("%s\t",(p+i)->address);
            printf("%s\t",(p+i)->email);
            printf("%s\n",(p+i)->number);
        }
        i++;
    }
}



void add(contact *p,int *c)
{
    //realloc(p,(c+2)*sizeof(contact));
    (p+*c)->lastname=malloc(50);
    (p+*c)->firstname=malloc(50);
    (p+*c)->address=malloc(50);
    (p+*c)->email=malloc(50);
    (p+*c)->number=malloc(50);
    printf("Enter Firstname: ");
    scanf("%s",(p+*c)->firstname);
    printf("Enter Lastname: ");
    scanf("%s",(p+*c)->lastname);
    printf("Enter Date of Birth: ");
    scanf("%d/%d/%d%*c",&((p+*c)->date.day),&((p+*c)->date.month),&((p+*c)->date.year));
    printf("Enter Address: ");
    gets((p+*c)->address);
    printf("Enter email: ");
    scanf("%s",(p+*c)->email);
    printf("Enter Number: ");
    scanf("%s",(p+*c)->number);
    (*c)++;
}

void save(contact *p,int x)
{
    FILE *f1;
    f1=fopen("C:\\Users\\DiDo\\Desktop\\PHONEBOOK\\Phonebook.txt","a");
    if(f1==NULL)
    {
        printf("Error Reading File");
        return 0;
    }

    fprintf(f1,"\n%s,",(p+x-1)->firstname);
    fprintf(f1,"%s,",(p+x-1)->lastname);
    fprintf(f1,"%d-%d-%d,",(p+x-1)->date.day,(p+x-1)->date.month,(p+x-1)->date.year);
    fprintf(f1,"%s,",(p+x-1)->address);
    fprintf(f1,"%s,",(p+x-1)->email);
    fprintf(f1,"%s",(p+x-1)->number);
    fclose(f1);
}

int countelements(int *a)
{
    int i=0;
    while(a[i]!=NULL)
        i++;
    return i;
}

void search(contact *p,int cnt)
{
    char *searchfirstname;
    char *searchlastname;
    char *searchaddress;
    char *searchemail;
    char *searchnumber;
    char *day;
    char *month;
    char *year;
    searchfirstname=malloc(50);
    searchlastname=malloc(50);
    searchaddress=malloc(50);
    searchemail=malloc(50);
    searchnumber=malloc(50);
    day=malloc(10);
    month=malloc(10);
    year=malloc(10);
    printf("Enter Firstname: ");
    gets(searchfirstname);
    printf("Enter Lastname: ");
    gets(searchlastname);
    printf("Enter Address: ");
    gets(searchaddress);
    //removespaces(searchaddress);
    printf("Enter Email: ");
    gets(searchemail);
    printf("Enter Number: ");
    gets(searchnumber);
    printf("Enter Date of Birth\nDay: ");
    gets(day);
    printf("Month: ");
    gets(month);
    printf("Year: ");
    gets(year);
    int *a;
    a=malloc(20);
    int *b;
    b=malloc(20);
    int *c;
    c=malloc(20);
    int *d;
    d=malloc(20);
    int *e;
    e=malloc(20);
    int *f;
    f=malloc(20);
    int n=0;

    if(*searchfirstname!=NULL)
    {
        n=initialsearchfirstname(p,searchfirstname,a,cnt);
        printf("\n%d\n",n);
        n=secondarysearchlastname(p,searchlastname,a,b,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchaddress(p,searchaddress,b,c,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchemail(p,searchemail,c,d,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchnumber(p,searchnumber,d,e,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchdateofbirth(p,day,month,year,e,f,cnt,n);
        printf("\n%d\n",n);
        printsearch(p,f,n);
    }
    else if(*searchlastname!=NULL)
    {
        n=initialsearchlastname(p,searchlastname,a,cnt);
        printf("\n%d\n",n);
        n=secondarysearchaddress(p,searchaddress,a,b,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchemail(p,searchemail,b,c,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchnumber(p,searchnumber,c,d,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchdateofbirth(p,day,month,year,d,e,cnt,n);
        printf("\n%d\n",n);
        printsearch(p,e,n);
    }
    else if(*searchaddress!=NULL)
    {
        n=initialsearchaddress(p,searchaddress,a,cnt);
        printf("\n%d\n",n);
        n=secondarysearchemail(p,searchemail,a,b,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchnumber(p,searchnumber,b,c,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchdateofbirth(p,day,month,year,c,d,cnt,n);
        printf("\n%d\n",n);
        printsearch(p,d,n);
    }
    /* if(*searchlastname==NULL)
         printf("\nNULL\n");
         else printf("\nNot NULL\n");*/
    else if (*searchemail!=NULL)
    {
        n=initialsearchemail(p,searchemail,a,cnt);
        printf("\n%d\n",n);
        n=secondarysearchnumber(p,searchnumber,a,b,cnt,n);
        printf("\n%d\n",n);
        n=secondarysearchdateofbirth(p,day,month,year,b,c,cnt,n);
        printf("\n%d\n",n);
        printsearch(p,c,n);
    }
    else if(*searchnumber!=NULL)
    {
        n=initialsearchnumber(p,searchnumber,a,cnt);
        printf("\n%d\n",n);
        n=secondarysearchdateofbirth(p,day,month,year,a,b,cnt,n);
        printf("\n%d\n",n);
        printsearch(p,b,n);
    }
    else if(1)
    {
        n=initialsearchdateofbirth(p,day,month,year,a,cnt);
        printf("\n%d\n",n);
        printsearch(p,a,n);
    }
}

int initialsearchfirstname(contact *p,char *a,int *b,int count)
{
    int i,j=0;
    for(i=0; i<count; i++)
    {
        if(strcasecmp(a,(p+i)->firstname)==0)
        {
            b[j]=i;
            j++;
        }
    }
    return j;
}

int initialsearchlastname(contact *p,char *a,int *b,int count)
{
    int i,j=0;
    for(i=0; i<count; i++)
    {
        if(strcasecmp(a,(p+i)->lastname)==0)
        {
            b[j]=i;
            j++;
        }
    }
    return j;
}

int initialsearchaddress(contact *p,char *a,int *b,int count)
{
    int i,j=0;
    char *str;

    for(i=0; i<count; i++)
    {
        /* "removing spaces"
        str=malloc(50);
         strcpy(str,(p+i)->firstname));
         removespaces(str); */
        if(strcasecmp(a,(p+i)->address)==0)
        {
            b[j]=i;
            j++;
        }
    }
    return j;
}

int initialsearchemail(contact *p,char *a,int *b,int count)
{
    int i,j=0;
    for(i=0; i<count; i++)
    {
        if(strcasecmp(a,(p+i)->email)==0)
        {
            b[j]=i;
            j++;
        }
    }
    return j;
}

int initialsearchnumber(contact *p,char *a,int *b,int count)
{
    int i,j=0;
    for(i=0; i<count; i++)
    {
        if(strcasecmp(a,(p+i)->number)==0)
        {
            b[j]=i;
            j++;
        }
    }
    return j;
}

int initialsearchdateofbirth(contact *p,char *d,char *m,char *y,int *b,int count)
{
    if((*d!=NULL) || (*m!=NULL) ||  (*y!=NULL))
    {
        int i,day,month,year,j=0;
        day=(int)strtol(d,NULL,10);
        month=(int)strtol(m,NULL,10);
        year=(int)strtol(y,NULL,10);
        for(i=0; i<count; i++)
        {
            if(day!=0 && month!=0 && year!=0)
            {
                if(day==((p+i)->date.day) && month==((p+i)->date.month) && year==((p+i)->date.year))
                {
                    b[j]=i;
                    j++;
                }
            }
            else if(day!=0 && month!=0 && year==0)
            {
                if(day==((p+i)->date.day) && month==((p+i)->date.month))
                {
                    b[j]=i;
                    j++;
                }
            }
            else if(day!=0 && month==0 && year!=0)
            {
                if(day==((p+i)->date.day) && year==((p+i)->date.year))
                {
                    b[j]=i;
                    j++;
                }
            }
            else if(day!=0 && month==0 && year==0)
            {
                if(day==((p+i)->date.day) )
                {
                    b[j]=i;
                    j++;
                }
            }
            else if(day==0 && month!=0 && year!=0)
            {
                if(month==((p+i)->date.month) && year==((p+i)->date.year))
                {
                    b[j]=i;
                    j++;
                }
            }
            else if(day==0 && month!=0 && year==0)
            {
                if(month==(p+i)->date.month)
                {
                    b[j]=i;
                    j++;
                }
            }
            else if(day==0 && month==0 && year!=0)
            {
                if(year==((p+i)->date.year))
                {
                    b[j]=i;
                    j++;
                }
            }
        }
        return j;
    }
}

int secondarysearchlastname(contact *p,char *a,int *b,int *c,int count,int len)
{
    if((*a)!=NULL)
    {
        int k,q=0;
        for(int i=0; i<count; i++)
        {
            if(strcasecmp(a,(p+i)->lastname)==0)
            {
                for(k=0; k<len; k++)
                {
                    if(b[k]==i)
                    {
                        c[q]=i;
                        q++;
                    }
                }
            }
        }
        return q;
    }
    else
    {
        for(int k=0; k<len; k++)
        {
            c[k]=b[k];
        }
        return len;
    }

}

int secondarysearchaddress(contact *p,char *a,int *b,int *c,int count,int len)
{
    if((*a)!=NULL)
    {
        int k,q=0;
        for(int i=0; i<count; i++)
        {
            if(strcasecmp(a,(p+i)->address)==0)
            {
                for(k=0; k<len; k++)
                {
                    if(b[k]==i)
                    {
                        c[q]=i;
                        q++;
                    }
                }
            }
        }
        return q;
    }
    else
    {
        for(int k=0; k<len; k++)
        {
            c[k]=b[k];
        }
        return len;
    }

}

int secondarysearchemail(contact *p,char *a,int *b,int *c,int count,int len)
{
    if((*a)!=NULL)
    {
        int k,q=0;
        for(int i=0; i<count; i++)
        {
            if(strcasecmp(a,(p+i)->email)==0)
            {
                for(k=0; k<len; k++)
                {
                    if(b[k]==i)
                    {
                        c[q]=i;
                        q++;
                    }
                }
            }
        }
        return q;
    }
    else
    {
        for(int k=0; k<len; k++)
        {
            c[k]=b[k];
        }
        return len;
    }

}

int secondarysearchnumber(contact *p,char *a,int *b,int *c,int count,int len)
{
    if((*a)!=NULL)
    {
        int k,q=0;
        for(int i=0; i<count; i++)
        {
            if(strcasecmp(a,(p+i)->number)==0)
            {
                for(k=0; k<len; k++)
                {
                    if(b[k]==i)
                    {
                        c[q]=i;
                        q++;
                    }
                }
            }

        }
        return q;
    }
    else
    {
        for(int k=0; k<len; k++)
        {
            c[k]=b[k];
        }
        return len;
    }

}

int secondarysearchdateofbirth(contact *p,char *d,char *m,char *y,int *b,int *c,int count,int len)
{
    if((*d!=NULL) || (*m!=NULL) ||  (*y!=NULL))
    {
        int k,day,month,year,q=0;
        day=(int)strtol(d,NULL,10);
        month=(int)strtol(m,NULL,10);
        year=(int)strtol(y,NULL,10);
        for(int i=0; i<count; i++)
        {
            if(day!=0 && month!=0 && year!=0)
            {
                if(day==((p+i)->date.day) && month==((p+i)->date.month) && year==((p+i)->date.year))
                {
                    for(k=0; k<len; k++)
                    {
                        if(b[k]==i)
                        {
                            c[q]=i;
                            q++;
                        }
                    }
                }
            }
            else if(day!=0 && month!=0 && year==0)
            {
                if(day==((p+i)->date.day) && month==((p+i)->date.month))
                {
                    for(k=0; k<len; k++)
                    {
                        if(b[k]==i)
                        {
                            c[q]=i;
                            q++;
                        }
                    }
                }
            }
            else if(day!=0 && month==0 && year!=0)
            {
                if(day==((p+i)->date.day) && year==((p+i)->date.year))
                {
                    for(k=0; k<len; k++)
                    {
                        if(b[k]==i)
                        {
                            c[q]=i;
                            q++;
                        }
                    }
                }


            }
            else if(day!=0 && month==0 && year==0)
            {
                if(day==((p+i)->date.day) )
                {
                    for(k=0; k<len; k++)
                    {
                        if(b[k]==i)
                        {
                            c[q]=i;
                            q++;
                        }
                    }
                }


            }
            else if(day==0 && month!=0 && year!=0)
            {
                if(month==((p+i)->date.month) && year==((p+i)->date.year))
                {
                    for(k=0; k<len; k++)
                    {
                        if(b[k]==i)
                        {
                            c[q]=i;
                            q++;
                        }
                    }
                }


            }
            else if(day==0 && month!=0 && year==0)
            {
                if(month==(p+i)->date.month)
                {
                    for(k=0; k<len; k++)
                    {
                        if(b[k]==i)
                        {
                            c[q]=i;
                            q++;
                        }
                    }
                }


            }
            else if(day==0 && month==0 && year!=0)
            {
                if(year==((p+i)->date.year))
                {
                    for(k=0; k<len; k++)
                    {
                        if(b[k]==i)
                        {
                            c[q]=i;
                            q++;
                        }
                    }
                }


            }
        }
        return q;

    }
    else
    {
        for(int k=0; k<len; k++)
        {
            c[k]=b[k];
        }
        return len;
    }

}
/* "removing spaces"
void removespaces(char *str){
    int count=0;
    for (int i = 0; i < strlen(str); i++)
    if (str[i] != ' ')
        str[count++] = str[i];
}*/

void printsearch(contact *p,int *ln,int len)
{
    int q;
    printf("Entry\tFirstname\tLastname\tDate of Birth\tAddress\t\t\t\temail\t\t\tNumber\n");
    for(q=0; q<len; q++)
    {
        printf("%d\t",q+1);
        printf("%s\t\t",(p+*(ln+q))->firstname);
        printf("%s\t\t",(p+*(ln+q))->lastname);
        printf("%02d/%02d/%d\t",(p+*(ln+q))->date.day,(p+*(ln+q))->date.month,(p+*(ln+q))->date.year);
        printf("%s\t\t",(p+*(ln+q))->address);
        printf("%s\t",(p+*(ln+q))->email);
        printf("%s\n",(p+*(ln+q))->number);
    }


}

int main()
{
    int cnt,x;
    cnt=count();
    contact person;
    contact *Pperson;
    Pperson=&person;
    Pperson=malloc(20*sizeof(contact));
    load(Pperson);
    printf("Choose Action:\n1.Add Contact\n2.Search\n3.Print\n");
    scanf("%d%*c",&x);
    switch(x){
    case 1: add(Pperson,&cnt);
            print(Pperson,cnt);
        break;
    case 2: search(Pperson,cnt);
        break;
    case 3: print(Pperson,cnt);
    default: break;
    }
    //add(Pperson,&cnt);
    //save(Pperson,cnt);
    //search(Pperson,cnt);
    //print(Pperson,cnt);
    free(Pperson);

    return 0;
}
