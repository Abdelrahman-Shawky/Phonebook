#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "phonebookfinal.h"


int count()
{
    int i=0;
    char ch;
    FILE *f1;
    f1=fopen("Phonebook.txt","r");
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
    f1=fopen("Phonebook.txt","r");
    if(f1==NULL)
    {
        printf("Error Reading File");
        exit(0);
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
    printf("Entry\tFirstname\tLastname\tDate of Birth\tAddress\t\t\t\tEmail\t\t\tNumber\n");
    while(i<c)
    {
        printf("%d\t",i+1);
        if(strlen((p+i)->firstname)<8)
            printf("%s\t\t",(p+i)->firstname);
        else
            printf("%s\t",(p+i)->firstname);
        if (strlen((p+i)->lastname)<8)
            printf("%s\t\t",(p+i)->lastname);
        else
            printf("%s\t",(p+i)->lastname);
        printf("%02d/%02d/%d\t",(p+i)->date.day,(p+i)->date.month,(p+i)->date.year);
        if(strlen((p+i)->address)<16)
            printf("%s\t\t\t",(p+i)->address);
        else if(strlen((p+i)->address)<24)
            printf("%s\t\t",(p+i)->address);
        else
            printf("%s\t",(p+i)->address);
        if (strlen((p+i)->email)<16)
            printf("%s\t\t",(p+i)->email);
        else
            printf("%s\t",(p+i)->email);
        printf("%s\n",(p+i)->number);
        i++;
    }
}

void add(contact *p,int *c)
{
    //realloc(p,(c+2)*sizeof(contact));
    int i,j,flag,flag1,flag2,k=0,flag3,flag4,flag5,flag6,at1;
    char *at;
    char *alphabet;
    alphabet=malloc(100);
    alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *address;
    address=malloc(100);
    address="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.# ";
    char *number;
    number=malloc(11);
    number="0123456789";
    char *domain;
    domain=malloc(100);
    domain="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.";
    (p+*c)->lastname=malloc(50);
    (p+*c)->firstname=malloc(50);
    (p+*c)->address=malloc(50);
    (p+*c)->email=malloc(50);
    (p+*c)->number=malloc(50);
    char *day;
    char *month;
    char *year;
    day=malloc(5);
    month=malloc(5);
    year=malloc(5);

    printf("Enter Firstname: ");
    do
    {
        gets((p+*c)->firstname);
        for(j=0; j<strlen((p+*c)->firstname); j++)
        {
            flag=0;
            for(i=0; i<52; i++)
            {
                if(((p+*c)->firstname)[j]==alphabet[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Firstname: ");
                break;
            }
        }
        if(*((p+*c)->firstname)=='\0')
            printf("No Input Found\nEnter Firstname: ");
    }
    while(*((p+*c)->firstname)=='\0' || flag==0);

    printf("Enter Lastname: ");
    do
    {
        gets((p+*c)->lastname);
        for(j=0; j<strlen((p+*c)->lastname); j++)
        {
            flag=0;
            for(i=0; i<52; i++)
            {
                if(((p+*c)->lastname)[j]==alphabet[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Lastname: ");
                break;
            }
        }
        if(*((p+*c)->lastname)=='\0')
            printf("No Input Found\nEnter Lastname: ");
    }
    while(*((p+*c)->lastname)=='\0' || flag==0);

    printf("Enter Date of Birth:\n");
    printf("Enter Day: ");
    do
    {
        gets(day);
        for(j=0; j<strlen(day); j++)
        {
            flag=0;
            for(i=0; i<10; i++)
            {
                if(day[j]==number[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Day: ");
                break;
            }
        }
        if(*day=='\0')
            printf("No Input Found\nEnter Day:  ");
        else if(((int)strtol(day,NULL,10)>31 || (int)strtol(day,NULL,10)<1) && flag==1)
        {
            printf("Invalid Input\nEnter Day:  ");
            flag=0;
        }
    }
    while(*day=='\0' || flag==0);
    (p+*c)->date.day=(int)strtol(day,NULL,10);

    printf("Enter Month: ");
    do
    {
        gets(month);
        for(j=0; j<strlen(month); j++)
        {
            flag=0;
            for(i=0; i<10; i++)
            {
                if(month[j]==number[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Month: ");
                break;
            }
        }
        if(*month=='\0')
            printf("No Input Found\nEnter Month:  ");
        else if(((int)strtol(month,NULL,10)>12 || (int)strtol(month,NULL,10)<1) && flag==1)
        {
            printf("Invalid Input\nEnter Month:  ");
            flag=0;
        }
    }
    while(*month=='\0' || flag==0);
    (p+*c)->date.month=(int)strtol(month,NULL,10);

    printf("Enter Year: ");
    do
    {
        gets(year);
        for(j=0; j<strlen(year); j++)
        {
            flag=0;
            for(i=0; i<10; i++)
            {
                if(year[j]==number[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Year: ");
                break;
            }
        }
        if(*year=='\0')
            printf("No Input Found\nEnter Year:  ");
        else if(((int)strtol(year,NULL,10)>2019 || (int)strtol(year,NULL,10)<1000) && flag==1)
        {
            printf("Invalid Input\nEnter Year:  ");
            flag=0;
        }
    }
    while(*year=='\0' || flag==0);
    (p+*c)->date.year=(int)strtol(year,NULL,10);

    printf("Enter Address: ");
    do
    {
        gets((p+*c)->address);
        for(j=0; j<strlen((p+*c)->address); j++)
        {
            flag=0;
            for(i=0; i<65; i++)
            {
                if(((p+*c)->address)[j]==address[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Address: ");
                break;
            }
        }
        if(*((p+*c)->address)=='\0')
            printf("No Input Found\nEnter Address: ");
    }
    while(*((p+*c)->address)=='\0' || flag==0);

    printf("Enter Email: ");

    do
    {
        gets((p+*c)->email);
        if(*((p+*c)->email)!='\0')
        {
            flag1=0;
            flag2=0;
            flag=1;
            flag3=1;
            flag4=1;
            flag5=0;
            flag6=1;
            k=0;
            if(((p+*c)->email)[0]=='.')
                flag3=0;
            for(j=0; j<strlen((p+*c)->email); j++)
            {
                if(((p+*c)->email)[j]==' ')
                    flag=0;
                if(((p+*c)->email)[j]=='@')
                {
                    flag1=1;
                    k++;
                }
                if(((p+*c)->email)[j]=='.')
                    flag2=1;

            }
            if(k==1)
            {
                at = strchr((p+*c)->email, '@');
                at1=(int)(at-((p+*c)->email));
                if(((p+*c)->email)[at1-1]=='.')
                    flag4=0;

                for(j=at1+1; j<strlen((p+*c)->email); j++)
                {
                    flag5=0;
                    for(i=0; i<64; i++)
                    {
                        if(((p+*c)->email)[j]==domain[i])
                            flag5=1;
                    }
                    if(flag5==0)
                        break;
                }
                if((((p+*c)->email)[at1+1]=='-') || (((p+*c)->email)[at1+1]=='.'))
                    flag6=0;
            }
            if(flag1==0 || flag2==0 || flag==0 || k!=1 || flag3==0 || flag4==0 || flag5==0 || flag6==0)
            {
                flag=0;
                printf("Invalid Input\nEnter Email: ");
            }
        }
        else
            printf("No Input Found\nEnter Email: ");
    }
    while(*((p+*c)->email)=='\0' || flag==0);

    printf("Enter Number: ");
    do
    {
        flag=0;
        gets((p+*c)->number);
        for(j=0; j<strlen((p+*c)->number); j++)
        {
            flag=0;
            for(i=0; i<10; i++)
            {
                if(((p+*c)->number)[j]==number[i])
                    flag=1;
            }
            if(flag==0)
            {
                break;
            }
        }
        if(flag==1)
        {
            if(strlen((p+*c)->number)<7)
            {
                printf("Invalid Input\nEnter Number: ");
                flag=0;
            }
        }
        else if(flag==0 && *((p+*c)->number)!='\0')
            printf("Invalid Input\nEnter Number: ");
        else if(*((p+*c)->number)=='\0')
            printf("No Input Found\nEnter Number: ");
    }
    while(*((p+*c)->number)=='\0' || flag==0);
    (*c)++;
    free(alphabet);
    free(address);
    free(domain);
    free(number);
    free(day);
    free(month);
    free(year);
}

void save(contact *p,int count)
{
    int i;
    FILE *f1;
    f1=fopen("Phonebook.txt","w");
    if(f1==NULL)
    {
        printf("Error Reading File");
        exit(0);
    }

    for(i=0; i<count; i++)
    {
        fprintf(f1,"%s,",(p+i)->lastname);
        fprintf(f1,"%s,",(p+i)->firstname);
        fprintf(f1,"%d-%d-%d,",(p+i)->date.day,(p+i)->date.month,(p+i)->date.year);
        fprintf(f1,"%s,",(p+i)->address);
        fprintf(f1,"%s,",(p+i)->email);
        if(i==count-1)
            fprintf(f1,"%s",(p+i)->number);
        else
            fprintf(f1,"%s\n",(p+i)->number);
    }
    fclose(f1);
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
    for(i=0; i<count; i++)
    {
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
            b[j]=i-1;
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
    if((*d!='\0') || (*m!='\0') ||  (*y!='\0'))
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
    return 0;
}

int secondarysearchlastname(contact *p,char *a,int *b,int *c,int count,int len)
{
    if((*a)!='\0')
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
    if((*a)!='\0')
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
    if((*a)!='\0')
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
    if((*a)!='\0')
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
    if((*d!='\0') || (*m!='\0') ||  (*y!='\0'))
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

void printsearch(contact *p,int *ln,int len,int count)
{
    int q;
    if(len)
    {
        printf("Entry\tFirstname\tLastname\tDate of Birth\tAddress\t\t\t\tEmail\t\t\tNumber\n");
        for(q=0; q<len; q++)
        {
            printf("%d\t",q+1);
            if(strlen((p+*(ln+q))->firstname)<8)
                printf("%s\t\t",(p+*(ln+q))->firstname);
            else
                printf("%s\t",(p+*(ln+q))->firstname);
            if (strlen((p+*(ln+q))->lastname)<8)
                printf("%s\t\t",(p+*(ln+q))->lastname);
            else
                printf("%s\t",(p+*(ln+q))->lastname);
            printf("%02d/%02d/%d\t",(p+*(ln+q))->date.day,(p+*(ln+q))->date.month,(p+*(ln+q))->date.year);
            if (strlen((p+*(ln+q))->address)<16)
                printf("%s\t\t\t",(p+*(ln+q))->address);
            else if(strlen((p+*(ln+q))->address)<24)
                printf("%s\t\t",(p+*(ln+q))->address);
            else
                printf("%s\t",(p+*(ln+q))->address);
            if(strlen((p+*(ln+q))->email)<16)
                printf("%s\t\t",(p+*(ln+q))->email);
            else
                printf("%s\t",(p+*(ln+q))->email);
            printf("%s\n",(p+*(ln+q))->number);
        }
        printf("%d Entries out of %d\n",q,count);
    }
    else
        printf("No matches found\n\n");
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

    if(*searchfirstname!='\0')
    {
        n=initialsearchfirstname(p,searchfirstname,a,cnt);
        n=secondarysearchlastname(p,searchlastname,a,b,cnt,n);
        n=secondarysearchaddress(p,searchaddress,b,c,cnt,n);
        n=secondarysearchemail(p,searchemail,c,d,cnt,n);
        n=secondarysearchnumber(p,searchnumber,d,e,cnt,n);
        n=secondarysearchdateofbirth(p,day,month,year,e,f,cnt,n);
        printsearch(p,f,n,cnt);
    }
    else if(*searchlastname!='\0')
    {
        n=initialsearchlastname(p,searchlastname,a,cnt);
        n=secondarysearchaddress(p,searchaddress,a,b,cnt,n);
        n=secondarysearchemail(p,searchemail,b,c,cnt,n);
        n=secondarysearchnumber(p,searchnumber,c,d,cnt,n);
        n=secondarysearchdateofbirth(p,day,month,year,d,e,cnt,n);
        printsearch(p,e,n,cnt);
    }
    else if(*searchaddress!='\0')
    {
        n=initialsearchaddress(p,searchaddress,a,cnt);
        n=secondarysearchemail(p,searchemail,a,b,cnt,n);
        n=secondarysearchnumber(p,searchnumber,b,c,cnt,n);
        n=secondarysearchdateofbirth(p,day,month,year,c,d,cnt,n);
        printsearch(p,d,n,cnt);
    }
    else if (*searchemail!='\0')
    {
        n=initialsearchemail(p,searchemail,a,cnt);
        n=secondarysearchnumber(p,searchnumber,a,b,cnt,n);
        n=secondarysearchdateofbirth(p,day,month,year,b,c,cnt,n);
        printsearch(p,c,n,cnt);
    }
    else if(*searchnumber!='\0')
    {
        n=initialsearchnumber(p,searchnumber,a,cnt);
        n=secondarysearchdateofbirth(p,day,month,year,a,b,cnt,n);
        printsearch(p,b,n,cnt);
    }
    else if(*day!='\0' || *month!='\0' || *year!='\0')
    {
        n=initialsearchdateofbirth(p,day,month,year,a,cnt);
        printsearch(p,a,n,cnt);
    }
    else
        print(p,cnt);
    free(searchfirstname);
    free(searchlastname);
    free(searchemail);
    free(searchnumber);
    free(searchaddress);
    free(day);
    free(month);
    free(year);
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
}

void swap(contact *p,int i)
{
    temp a;
    temp *Pa;
    Pa=&a;
    Pa->lastname=malloc(50);
    Pa->firstname=malloc(50);
    Pa->address=malloc(50);
    Pa->email=malloc(50);
    Pa->number=malloc(50);

    Pa->firstname=(p+i)->firstname;
    Pa->lastname=(p+i)->lastname;
    Pa->address=(p+i)->address;
    Pa->email=(p+i)->email;
    Pa->number=(p+i)->number;
    Pa->date.year=(p+i)->date.year;
    Pa->date.month=(p+i)->date.month;
    Pa->date.day=(p+i)->date.day;

    (p+i)->firstname=(p+i+1)->firstname;
    (p+i)->lastname=(p+i+1)->lastname;
    (p+i)->address=(p+i+1)->address;
    (p+i)->email=(p+i+1)->email;
    (p+i)->number=(p+i+1)->number;
    (p+i)->date.year=(p+i+1)->date.year;
    (p+i)->date.month=(p+i+1)->date.month;
    (p+i)->date.day=(p+i+1)->date.day;

    (p+i+1)->firstname=Pa->firstname;
    (p+i+1)->lastname=Pa->lastname;
    (p+i+1)->address=Pa->address;
    (p+i+1)->email=Pa->email;
    (p+i+1)->number=Pa->number;
    (p+i+1)->date.year=Pa->date.year;
    (p+i+1)->date.month=Pa->date.month;
    (p+i+1)->date.day=Pa->date.day;
    free(Pa);
}

void sortbyfirstname(contact *p,int count,int x)
{
    int j,n,i,sorted;
    switch (x)
    {
    case 1:
        for(i=0; i<count-1; i++)
        {
            sorted=0;
            for(j=0; j<count-i-1; j++)
            {
                n=strcasecmp((p+j)->firstname,(p+j+1)->firstname);
                if (n>0)
                {
                    swap(p,j);
                    sorted=1;
                }
            }
            if (sorted==0)
                break;
        }
        print(p,count);
        break;
    case 2:
        for(i=0; i<count-1; i++)
        {
            sorted=0;
            for(j=0; j<count-i-1; j++)
            {
                n=strcasecmp((p+j)->firstname,(p+j+1)->firstname);
                if (n<0)
                {
                    swap(p,j);
                    sorted=1;
                }
            }
            if (sorted==0)
                break;
        }
        print(p,count);
        break;
    }
}

void sortbylastname(contact *p,int count,int x)
{
    int j,n,i,sorted;
    switch(x)
    {
    case 1:
        for(i=0; i<count-1; i++)
        {
            sorted=0;
            for(j=0; j<count-i-1; j++)
            {
                n=strcasecmp((p+j)->lastname,(p+j+1)->lastname);
                if (n>0)
                {
                    swap(p,j);
                    sorted=1;
                }
            }
            if (sorted==0)
                break;
        }
        print(p,count);
        break;
    case 2:
        for(i=0; i<count-1; i++)
        {
            sorted=0;
            for(j=0; j<count-i-1; j++)
            {
                n=strcasecmp((p+j)->lastname,(p+j+1)->lastname);
                if (n<0)
                {
                    swap(p,j);
                    sorted=1;
                }
            }
            if (sorted==0)
                break;
        }
        print(p,count);
        break;
    }
}

void sortbydate(contact *p,int count,int x)
{
    int i,j,sorted;
    switch(x)
    {
    case 2:
        for(i=0; i<count-1; i++)
        {
            sorted=0;
            for(j=0; j<count-i-1; j++)
            {
                if((p+j)->date.year>(p+j+1)->date.year)
                {
                    swap(p,j);
                    sorted=1;
                }
                if ((p+j)->date.year==(p+j+1)->date.year && (p+j)->date.month>(p+j+1)->date.month)
                {
                    swap(p,j);
                    sorted=1;
                }
                if((p+j)->date.year==(p+j+1)->date.year && (p+j)->date.month==(p+j+1)->date.month && (p+j)->date.day>(p+j+1)->date.day)
                {
                    swap(p,j);
                    sorted=1;
                }
            }
            if(sorted==0)
                break;
        }
        print(p,count);
        break;
    case 1:
        for(i=0; i<count-1; i++)
        {
            sorted=0;
            for(j=0; j<count-i-1; j++)
            {
                if((p+j)->date.year<(p+j+1)->date.year)
                {
                    swap(p,j);
                    sorted=1;
                }
                if ((p+j)->date.year==(p+j+1)->date.year && (p+j)->date.month<(p+j+1)->date.month)
                {
                    swap(p,j);
                    sorted=1;
                }
                if((p+j)->date.year==(p+j+1)->date.year && (p+j)->date.month==(p+j+1)->date.month && (p+j)->date.day<(p+j+1)->date.day)
                {
                    swap(p,j);
                    sorted=1;
                }
            }
            if(sorted==0)
                break;
        }
        print(p,count);
        break;
    }
}

void printmodify(contact *p,int a)
{
    printf("Entry\tFirstname\tLastname\tDate of Birth\tAddress\t\t\t\tEmail\t\t\tNumber\n");
    printf("%d\t",a+1);
    if(strlen((p+a)->firstname)<8)
        printf("%s\t\t",(p+a)->firstname);
    else
        printf("%s\t",(p+a)->firstname);
    if (strlen((p+a)->lastname)<8)
        printf("%s\t\t",(p+a)->lastname);
    else
        printf("%s\t",(p+a)->lastname);
    printf("%02d/%02d/%d\t",(p+a)->date.day,(p+a)->date.month,(p+a)->date.year);
    if (strlen((p+a)->address)<16)
        printf("%s\t\t\t",(p+a)->address);
    else if(strlen((p+a)->address)<24)
        printf("%s\t\t",(p+a)->address);
    else
        printf("%s\t",(p+a)->address);
    if(strlen((p+a)->email)<16)
        printf("%s\t\t",(p+a)->email);
    else
        printf("%s\t",(p+a)->email);
    printf("%s\n",(p+a)->number);
}

void modify(contact *p,int count)
{
    int flag,flag1,flag2,flag3,flag4,flag5,flag6,k,at1;
    char *at;
    char *alphabet;
    alphabet=malloc(100);
    alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *address;
    address=malloc(100);
    address="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789#. ";
    char *number;
    number=malloc(11);
    number="0123456789";
    char *domain;
    domain=malloc(100);
    domain="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.";
    char *a;
    int i,x,j,num;
    int *b;
    char *c;
    c=malloc(5);
    b=malloc(50);
    a=malloc(50);
    printf("Enter Lastname: ");
    do
    {
        gets(a);
        for(j=0; j<strlen(a); j++)
        {
            flag=0;
            for(i=0; i<52; i++)
            {
                if(a[j]==alphabet[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Lastname: ");
                break;
            }
        }
        if(*a=='\0')
            printf("No Input Found\nEnter Lastname: ");
    }
    while(*a=='\0' || flag==0);
    j=0;
    flag=0;
    for(i=0; i<count; i++)
    {
        if(strcasecmp(a,(p+i)->lastname)==0)
        {
            b[j]=i;
            j++;
            flag=1;
        }
    }
    num=j;
    printsearch(p,b,j,count);
    char *temp;
    temp=malloc(50);
    if(flag==1)
    {
        printf("Enter Entry Number You Wish To Modify: ");

        do
        {
            gets(c);
            for(j=0; j<strlen(c); j++)
            {
                flag=0;
                for(i=0; i<10; i++)
                {
                    if(c[j]==number[i])
                        flag=1;
                }
                if(flag==0)
                {
                    printf("Invalid Input\nEnter Number: ");
                    break;
                }
            }
            if(*c=='\0')
                printf("No Input Found\nEnter Number: ");
            else if(((int)strtol(c,NULL,10)>num || (int)strtol(c,NULL,10)<1) && flag==1)
            {
                printf("Invalid Input\nEnter Number:  ");
                flag=0;
            }
        }
        while(*c=='\0' || flag==0);
        x=(int)strtol(c,NULL,10);

        printf("Change Firstname %s to ",(p+b[x-1])->firstname);
        do
        {
            gets(temp);
            if(*temp!='\0')
            {
                for(j=0; j<strlen(temp); j++)
                {
                    flag=0;
                    for(i=0; i<52; i++)
                    {
                        if(temp[j]==alphabet[i])
                            flag=1;
                    }
                    if(flag==0)
                    {
                        printf("Invalid Input\nChange Firstname %s to: ",(p+b[x-1])->firstname);
                        break;
                    }
                }
            }
            else
                flag=1;
        }
        while(flag==0);
        if (*temp!='\0')
        {
            strcpy((p+b[x-1])->firstname,temp);
            temp[0]='\0';
        }

        printf("Change Lastname %s to ",(p+b[x-1])->lastname);
        do
        {
            gets(temp);
            if(*temp!='\0')
            {
                for(j=0; j<strlen(temp); j++)
                {
                    flag=0;
                    for(i=0; i<52; i++)
                    {
                        if(temp[j]==alphabet[i])
                            flag=1;
                    }
                    if(flag==0)
                    {
                        printf("Invalid Input\nChange Lastname %s to: ",(p+b[x-1])->lastname);
                        break;
                    }
                }
            }
            else
                flag=1;
        }
        while(flag==0);

        if (*temp!='\0')
        {
            strcpy((p+b[x-1])->lastname,temp);
            temp[0]='\0';
        }

        printf("Change Date of Birth\nDay %02d to ",(p+b[x-1])->date.day);
        do
        {
            gets(temp);
            if(*temp!='\0')
            {
                for(j=0; j<strlen(temp); j++)
                {
                    flag=0;
                    for(i=0; i<10; i++)
                    {
                        if(temp[j]==number[i])
                            flag=1;
                    }
                    if(flag==0)
                    {
                        printf("Invalid Input\nChange Day %02d to: ",(p+b[x-1])->date.day);
                        break;
                    }
                }
                if(((int)strtol(temp,NULL,10)>31 || (int)strtol(temp,NULL,10)<1) && flag==1)
                {
                    printf("Invalid Input\nChange Day %02d to: ",(p+b[x-1])->date.day);
                    flag=0;
                }
            }
            else
                flag=1;
        }
        while(flag==0);

        if(*temp!='\0')
        {
            (p+b[x-1])->date.day=(int)strtol(temp,NULL,10);
            temp[0]='\0';
        }

        printf("Change Month %02d to ",(p+b[x-1])->date.month);
        do
        {
            gets(temp);
            if(*temp!='\0')
            {
                for(j=0; j<strlen(temp); j++)
                {
                    flag=0;
                    for(i=0; i<10; i++)
                    {
                        if(temp[j]==number[i])
                            flag=1;
                    }
                    if(flag==0)
                    {
                        printf("Invalid Input\nChange Month %02d to: ",(p+b[x-1])->date.month);
                        break;
                    }
                }
                if(((int)strtol(temp,NULL,10)>12 || (int)strtol(temp,NULL,10)<1) && flag==1)
                {
                    printf("Invalid Input\nChange Month %02d to: ",(p+b[x-1])->date.month);
                    flag=0;
                }
            }
            else
                flag=1;
        }
        while(flag==0);

        if(*temp!='\0')
        {
            (p+b[x-1])->date.month=(int)strtol(temp,NULL,10);
            temp[0]='\0';
        }
        printf("Change Year %d to ",(p+b[x-1])->date.year);
        do
        {
            gets(temp);
            if(*temp!='\0')
            {
                for(j=0; j<strlen(temp); j++)
                {
                    flag=0;
                    for(i=0; i<10; i++)
                    {
                        if(temp[j]==number[i])
                            flag=1;
                    }
                    if(flag==0)
                    {
                        printf("Invalid Input\nChange Year %d to: ",(p+b[x-1])->date.year);
                        break;
                    }
                }
                if(((int)strtol(temp,NULL,10)>2019 || (int)strtol(temp,NULL,10)<1000) && flag==1)
                {
                    printf("Invalid Input\nChange Year %d to: ",(p+b[x-1])->date.year);
                    flag=0;
                }
            }
            else
                flag=1;
        }
        while(flag==0);
        if(*temp!='\0')
        {
            (p+b[x-1])->date.year=(int)strtol(temp,NULL,10);
            temp[0]='\0';
        }

        printf("Change Address %s to ",(p+b[x-1])->address);
        do
        {
            gets(temp);
            if(*temp!='\0')
            {
                for(j=0; j<strlen(temp); j++)
                {
                    flag=0;
                    for(i=0; i<65; i++)
                    {
                        if(temp[j]==address[i])
                            flag=1;
                    }
                    if(flag==0)
                    {
                        printf("Invalid Input\nChange Address %s to: ",(p+b[x-1])->address);
                        break;
                    }
                }
            }
            else
                flag=1;
        }
        while(flag==0);
        if (*temp!='\0')
        {
            strcpy((p+b[x-1])->address,temp);
            temp[0]='\0';
        }
        printf("Change Email %s to ",(p+b[x-1])->email);
        do
        {
            gets(temp);
            if(*temp!='\0')
            {
                flag1=0;
                flag2=0;
                flag=1;
                flag3=1;
                flag4=1;
                flag5=0;
                flag6=1;
                k=0;
                if(temp[0]=='.')
                    flag3=0;
                for(j=0; j<strlen(temp); j++)
                {
                    if(temp[j]==' ')
                        flag=0;
                    if(temp[j]=='@')
                    {
                        flag1=1;
                        k++;
                    }
                    if(temp[j]=='.')
                        flag2=1;

                }
                if(k==1)
                {
                    at = strchr(temp, '@');
                    at1=(int)(at-temp);
                    if(temp[at1-1]=='.')
                        flag4=0;

                    for(j=at1+1; j<strlen(temp); j++)
                    {
                        flag5=0;
                        for(i=0; i<64; i++)
                        {
                            if(temp[j]==domain[i])
                                flag5=1;
                        }
                        if(flag5==0)
                            break;
                    }
                    if((temp[at1+1]=='-') || (temp[at1+1]=='.'))
                        flag6=0;
                }
                if(flag1==0 || flag2==0 || flag==0 || k!=1 || flag3==0 || flag4==0 || flag5==0 || flag6==0)
                {
                    flag=0;
                    printf("Invalid Input\nEnter Email: ");
                }
            }
            else
                flag=1;
        }
        while(flag==0);
        if (*temp!='\0')
        {
            strcpy((p+b[x-1])->email,temp);
            temp[0]='\0';
        }
        printf("Change Number %s to ",(p+b[x-1])->number);
        do
        {
            gets(temp);
            flag=0;
            if(*temp!='\0')
            {
                for(j=0; j<strlen(temp); j++)
                {
                    flag=0;
                    for(i=0; i<10; i++)
                    {
                        if(temp[j]==number[i])
                            flag=1;
                    }
                    if(flag==0)
                    {
                        printf("Invalid Input\nChange Number %s to: ",(p+b[x-1])->number);
                        break;
                    }
                }
                if(flag==1)
                {
                    if(strlen(temp)<7)
                    {
                        printf("Invalid Input\nChange Number %s to: ",(p+b[x-1])->number);
                        flag=0;
                    }
                }
            }
            else
                flag=1;
        }
        while(flag==0);
        if (*temp!='\0')
        {
            strcpy((p+b[x-1])->number,temp);
            temp[0]='\0';
        }
        printmodify(p,b[x-1]);
    }
    free(alphabet);
    free(address);
    free(domain);
    free(number);
    free(a);
    free(b);
    free(c);
}

void deletecontact(contact *p,int *count)
{
    int flag,y;
    char *d;
    d=malloc(5);
    char *alphabet;
    alphabet=malloc(100);
    alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *number;
    number=malloc(11);
    number="0123456789";
    char *c;
    c=malloc(5);

    int i,j=0,q=0,k,x;
    char *firstname;
    firstname=malloc(50);
    char *lastname;
    lastname=malloc(50);
    int *a;
    a=malloc(50);
    int *b;
    b=malloc(50);
    printf("Enter Firstname: ");
    do
    {
        gets(firstname);
        for(j=0; j<strlen(firstname); j++)
        {
            flag=0;
            for(i=0; i<52; i++)
            {
                if((firstname)[j]==alphabet[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Firstname: ");
                break;
            }
        }
        if(*firstname=='\0')
            printf("No Input Found\nEnter Firstname: ");
    }
    while(*firstname=='\0' || flag==0);

    printf("Enter Lastname: ");
    do
    {
        gets(lastname);
        for(j=0; j<strlen(lastname); j++)
        {
            flag=0;
            for(i=0; i<52; i++)
            {
                if((lastname)[j]==alphabet[i])
                    flag=1;
            }
            if(flag==0)
            {
                printf("Invalid Input\nEnter Lastname: ");
                break;
            }
        }
        if(*lastname=='\0')
            printf("No Input Found\nEnter Lastname: ");
    }
    while(*lastname=='\0' || flag==0);
    j=0;
    for(i=0; i<*count; i++)
    {
        if(strcasecmp((p+i)->firstname,firstname)==0)
        {
            a[j]=i;
            j++;
        }
    }
    flag=0;
    for(i=0; i<*count; i++)
    {
        if(strcasecmp((p+i)->lastname,lastname)==0)
        {
            for(k=0; k<j; k++)
            {
                if(a[k]==i)
                {
                    b[q]=i;
                    q++;
                    flag=1;
                }
            }
        }
    }
    printsearch(p,b,q,*count);

    if(flag==1)
    {
        printf("Enter Entry Number You Wish to Delete: ");
        do
        {
            gets(c);
            for(j=0; j<strlen(c); j++)
            {
                flag=0;
                for(i=0; i<10; i++)
                {
                    if(c[j]==number[i])
                        flag=1;
                }
                if(flag==0)
                {
                    printf("Invalid Input\nEnter Number: ");
                    break;
                }
            }
            if(*c=='\0')
                printf("No Input Found\nEnter Number: ");
            else if(((int)strtol(c,NULL,10)>q || (int)strtol(c,NULL,10)<1) && flag==1)
            {
                printf("Invalid Input\nEnter Number:  ");
                flag=0;
            }
        }
        while(*c=='\0' || flag==0);
        x=(int)strtol(c,NULL,10);
        printf("Are You Sure You Want To Delete ?\n1.YES\t\t2.NO\n");
        do
        {
            gets(d);
            y=(int)strtol(d,NULL,10);
            if (*d=='\0')
                printf("No Input\nEnter Choice: ");
            else if(y!=1 && y!=2)
                printf("Invalid Input\nEnter Choice: ");
        }
        while((y!=1 && y!=2) || *d=='\0');

        switch(y)
        {
        case 1:
            for(i=b[x-1]; i<*count-1; i++)
            {
                (p+i)->firstname=(p+i+1)->firstname;
                (p+i)->lastname=(p+i+1)->lastname;
                (p+i)->address=(p+i+1)->address;
                (p+i)->email=(p+i+1)->email;
                (p+i)->number=(p+i+1)->number;
                (p+i)->date.day=(p+i+1)->date.day;
                (p+i)->date.month=(p+i+1)->date.month;
                (p+i)->date.year=(p+i+1)->date.year;
            }
            (p+*count-1)->firstname='\0';
            (p+*count-1)->lastname='\0';
            (p+*count-1)->address='\0';
            (p+*count-1)->email='\0';
            (p+*count-1)->number='\0';
            (p+*count-1)->date.day=0;
            (p+*count-1)->date.month=0;
            (p+*count-1)->date.year=0;
            --*count;
            print(p,*count);
            break;
        case 2:
            menu(p,count);
            break;
        }
    }
    free(alphabet);
    free(number);
    free(a);
    free(b);
    free(c);
    free(firstname);
    free(lastname);
}

void menu(contact *Pperson,int *cnt)
{
    int x,y,z,flag=0,f,l;
    char *a;
    a=malloc(5);
    char *b;
    b=malloc(5);
    char *c;
    c=malloc(5);
    char *d;
    d=malloc(5);
    char *e;
    e=malloc(5);
    printf("~~~~~Welcome To The PHONEBOOK~~~~~\n\n");
    do
    {
        printf("Choose Action Number You Wish To Do:\n1.Add Contact\n2.Search\n3.Sort\n4.Modify\n5.Delete\n6.Print\n7.Save\n8.Exit\nChoose Action: ");
        do
        {
            gets(c);
            x=(int)strtol(c,NULL,10);
            if(*c=='\0')
                printf("No Input\nEnter Choice: ");
            else if (x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6 && x!=7 && x!=8)
                printf("Invalid Input\nPlease Enter Again\n\n");
        }
        while((x!=1 && x!=2 && x!=3 && x!=4 && x!=5 && x!=6 && x!=7 && x!=8) || *c=='\0');
        if(x==7)
            flag=1;
        switch(x)
        {
        case 1:
            add(Pperson,cnt);
            print(Pperson,*cnt);
            break;
        case 2:
            search(Pperson,*cnt);
            break;
        case 3:
            printf("Sort by\n1.Firstname\n2.Lastname\n3.Date of Birth\n4.Back To Main Menu\n");
            do
            {
                gets(a);
                y=(int)strtol(a,NULL,10);
                if (*a=='\0')
                    printf("No Input\nEnter Choice: ");
                else if(y!=1 && y!=2 && y!=3&&y!=4)
                    printf("Invalid Input\nEnter Choice: ");
                else if(y==4)
                    menu(Pperson,cnt);
            }
            while((y!=1 && y!=2 && y!=3 &&y!=4) || *a=='\0');
            printf("Choose Sort Type\n1.Ascending\n2.Descending\n3.Back To Main Menu\n");
            do
            {
                gets(b);
                z=(int)strtol(b,NULL,10);
                if (*b=='\0')
                    printf("No Input\nEnter Choice: ");
                else if(z!=1 && z!=2 && z!=3)
                    printf("Invalid Input\nEnter Choice: ");
                else if(z==3)
                    menu(Pperson,cnt);
            }
            while((z!=1 && z!=2 && z!=3) || *b=='\0');
            switch(y)
            {
            case 1:
                sortbyfirstname(Pperson,*cnt,z);
                break;
            case 2:
                sortbylastname(Pperson,*cnt,z);
                break;
            case 3:
                sortbydate(Pperson,*cnt,z);
                break;
            case 4:
                break;
            }
            break;
        case 4:
            modify(Pperson,*cnt);
            break;
        case 5:
            deletecontact(Pperson,cnt);
            break;
        case 6:
            print(Pperson,*cnt);
            break;
        case 7:
            printf("Are You Sure You Want To Save ?\n1.YES\t\t2.NO\n");
            do
            {
                gets(d);
                l=(int)strtol(d,NULL,10);
                if (*d=='\0')
                    printf("No Input\nEnter Choice: ");
                else if(l!=1 && l!=2)
                    printf("Invalid Input\nEnter Choice: ");
            }
            while((l!=1 && l!=2) || *d=='\0');

            switch(l)
            {
            case 1:
                save(Pperson,*cnt);
                break;
            case 2:
                menu(Pperson,cnt);
                break;
            }
            break;
        case 8:
            if(flag==1)
            {
                free(Pperson);
                exit(0);
            }
            else
            {
                printf("Are You Sure You Want To Exit Without Saving ?\n1.YES\t\t2.NO\n");
                do
                {
                    gets(e);
                    f=(int)strtol(e,NULL,10);
                    if (*e=='\0')
                        printf("No Input\nEnter Choice: ");
                    else if(f!=1 && f!=2)
                        printf("Invalid Input\nEnter Choice: ");
                }
                while((f!=1 && f!=2) || *e=='\0');

                if(f==1)
                {
                    free(a);
                    free(b);
                    free(c);
                    free(d);
                    free(e);
                    free(Pperson);
                    exit(0);
                }
                else if(f==2)
                    menu(Pperson,cnt);

            }
            break;


        }
    }
    while(x!=8);
}
