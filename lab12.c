#include <stdio.h>
#include <stdlib.h>

#define HZ 3

struct employee
{
    char name[30];
    int salary, empno;
};

struct hashtable
{
    int empno;
    long address;
};


FILE *fp;

int hashval(int key)
{
    return key % HZ;
}


void insert(struct hashtable ht[])
{
    int n, flag;
    struct employee x;
    printf("Enter the number of entries : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        flag = 0;
        printf("Enter the employee id, name and salary : ");
        scanf("%d %s %d", &x.empno, x.name, &x.salary);

        int orghash = hashval(x.empno);
        int currhash = orghash;

        while (ht[currhash].empno != -1)
        {
            flag = 1;
            currhash = (currhash + 1) % HZ;
            if(currhash == orghash)
            {
                printf("Hash table full\n.Exiting.\n");
                return;
            }
        }

        ht[currhash].empno = x.empno;
        ht[currhash].address = ftell(fp);

        fprintf(fp, "%d %s %d ", x.empno, x.name, x.salary);
        if (flag)
            printf("Linear probing used and inserted successfully\n");
        else
            printf("Inserted without any collision.\n");
    }
}

void search(struct hashtable ht[])
{
    struct employee x;
    printf("Enter the employee number to search for : ");
    scanf("%d", &x.empno);

    int hashloc = hashval(x.empno);
    int orghash = hashloc;

    while (ht[hashloc].empno != x.empno)
    {
        hashloc = (hashloc + 1) % HZ;
        if (hashloc == orghash || ht[hashloc].empno == -1)
        {
            printf("Not found.\n");
            return;
        }        
    }

    fseek(fp, ht[hashloc].address, SEEK_SET);
    fscanf(fp, "%d %s %d ", &x.empno, x.name, &x.salary);
    printf("Data obtained : \n%d\n%s\n%d\nAt file address %li", x.empno, x.name, x.salary, ht[hashloc].address);
}

void display(struct hashtable ht[])
{
    struct employee x;
    for (int i = 0; i < HZ; i++)
    {
        if (ht[i].empno != -1)
        {
            fseek(fp, ht[i].address, SEEK_SET);
            fscanf(fp, "%d %s %d ", &x.empno, x.name, &x.salary);
            printf("\nEntry at %dth ht index and %li address in file : \n%d %s %d\n", i, ht[i].address, x.empno, x.name, x.salary);
        }
    }
}

int main()
{
    struct hashtable ht[3] = {{-1, 0}, {-1, 0}, {-1, 0}};
    int ch;

    fp = fopen("emp.txt", "w+");

    while(1)
    {
        printf("\n1. Insert\n2. Search\n3. Display\n\n:");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert(ht);
                    break;
                
            case 2: search(ht);
                    break;
            
            case 3: display(ht);
                    break;
            
            default: return 0;
        }
    }
}
