
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

typedef struct temp
{
    char *lastname;
    char *firstname;
    birthdate date;
    char *address;
    char *email;
    char *number;
} temp;

int count();
void load(contact *p);
void print(contact *p,int c);
void add(contact *p,int *c);
void save(contact *p,int count);
int initialsearchfirstname(contact *p,char *a,int *b,int count);
int initialsearchlastname(contact *p,char *a,int *b,int count);
int initialsearchaddress(contact *p,char *a,int *b,int count);
int initialsearchemail(contact *p,char *a,int *b,int count);
int initialsearchnumber(contact *p,char *a,int *b,int count);
int initialsearchdateofbirth(contact *p,char *d,char *m,char *y,int *b,int count);
int secondarysearchlastname(contact *p,char *a,int *b,int *c,int count,int len);
int secondarysearchaddress(contact *p,char *a,int *b,int *c,int count,int len);
int secondarysearchemail(contact *p,char *a,int *b,int *c,int count,int len);
int secondarysearchnumber(contact *p,char *a,int *b,int *c,int count,int len);
int secondarysearchdateofbirth(contact *p,char *d,char *m,char *y,int *b,int *c,int count,int len);
void printsearch(contact *p,int *ln,int len,int count);
void search(contact *p,int cnt);
void swap(contact *p,int i);
void sortbyfirstname(contact *p,int count,int x);
void sortbylastname(contact *p,int count,int x);
void sortbydate(contact *p,int count,int x);
void printmodify(contact *p,int a);
void modify(contact *p,int count);
void deletecontact(contact *p,int *count);
void menu(contact *Pperson,int *cnt);
