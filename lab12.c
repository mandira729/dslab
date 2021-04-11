#include <stdio.h>
#include <stdlib.h>

#define HZ 3

FILE *fp;

struct employee
{
	int empno;
	char name[20];
	int sal;
};
typedef struct employee EMP;


struct hashtable
{
	int key;
	long int addr;
};
typedef struct hashtable ht;

int hashval(int num)
{
	return num % HZ;
}


void search(ht *h, int n)
{
	EMP a;
	int hindex, countindex;
	
	printf("Enter emp no to search : \n");
	scanf("%d", &(a.empno));
	hindex = hashval(a.empno);
	
	countindex = hindex;
	
	while(h[hindex].key != a.empno)
	{
		hindex = (hindex + 1) % HZ;
		if (countindex == hindex)
		{
			printf("Search unsuccessful\n");
			return;
		}
	}
	
	printf("Search successful\n");
	fseek(fp, h[hindex].addr, SEEK_SET);
	fscanf(fp, "%d%s%d", &(a.empno), a.name, &(a.sal));
	printf("%d%s%d\n", a.empno, a.name, a.sal);
}


void display(ht *h, int n)
{
	EMP a;
	int i, j;
	
	for (int i = 0; i < HZ; i++)
	{
		if (h[i].key != -1)
		{
			printf("Hashtable %d %li \t", h[i].key, h[i].addr);
			fseek(fp, h[i].addr, SEEK_SET);
			fscanf(fp, "%d%s%d", &(a.empno), a.name, &(a.sal));
printf("Contents in secondary storage : %d %s %d\n", a.empno, a.name, a.sal);
		}
	}
}

void insert(ht *h, int n)
{
	EMP a;
	int flag = 0;
	int i, hindex, countindex;
	
	for (i = 0; i < n; i++)
	{
		printf("Enter empno, name and salary\n");
		scanf("%d%s%d", &(a.empno), a.name, &(a.sal));
		hindex = hashval(a.empno);
		countindex = hindex;
		
		while(h[hindex].key != -1)
		{
			hindex = (hindex + 1) % HZ;
			flag = 1;
			
			if (hindex == countindex)
			{
				printf("Entry not possible.\n");
				return;
			}
		}
		h[hindex].key = a.empno;
		h[hindex].addr = ftell(fp);
		
		fprintf(fp, "%d %s %d\n", a.empno, a.name, a.sal);
		printf("Entry successful\n");
		if (flag)
			printf("Linear probing used \n");
	}
}


int main()
{
	ht h[HZ];
	EMP d;
	int n, ch;
	
	fp = fopen("emp.txt", "w+");
	for (n = 0; n < HZ; n++)
		h[n].key = -1;
	
	while(1)
	{
		printf("\n\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
		printf("Enter ch : ");
		scanf("%d", &ch);
		rewind(fp);
		
		switch(ch)
		{
			case 1: 	printf("Enter the number of employees : ");
						scanf("%d", &n);
						insert(h, n);
						break;
						
			case 2:		search(h, n);
						break;
			
			case 3:		display(h, n);
						break;
						
			default: 	exit(0);
		}
	}
}
