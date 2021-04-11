#include <stdio.h>
#include <stdlib.h>

struct employee
{
	char ssn[10], name[20], dept[20], des[10], phno[10];
	int sal;
};
typedef struct employee emp;

struct node
{
	emp s;
	struct node *next;
	struct node *prev;
};
typedef struct node * NODE;


NODE getnode()
{
	NODE x = (NODE) malloc(sizeof(struct node));
	if (x == NULL)
		exit(0);
	return x;
}

NODE insertfront(NODE head)
{
	NODE new = getnode();
	printf("\nEnter ssn, name, dept, des, phno and sal resp : ");
	scanf("%s %s %s %s %s %d", new->s.ssn, new->s.name, new->s.dept, new->s.des, new->s.phno, &(new->s.sal));
	
	
	new->next = head;
	new->prev = NULL;
	
	if (head)
		head->prev = new;
	head = new;
	
	return head;
}

NODE insertrear(NODE head)
{
	NODE new = getnode(), curr = head;
	printf("\nEnter ssn, name, dept, des, phno and sal resp : ");
	scanf("%s %s %s %s %s %d", new->s.ssn, new->s.name, new->s.dept, new->s.des, new->s.phno, &(new->s.sal));
	
	
	if (curr == NULL)
	{
		head = new;
		new->next = NULL;
		new->prev = NULL;
		return head;
	}
	
	while (curr->next != NULL)
		curr = curr->next;
		
	curr->next = new;
	new->prev = curr;
	new->next = NULL;
	return head;
}

NODE deletefront(NODE head)
{
	if (head == NULL)
	{
		printf("Nothing to delete : ");
		return head;
	}
	printf("Deleting ssn %s \n", head->s.ssn);
	
	NODE curr = head;
	head = head->next;
	head->prev = NULL;
	free(curr);
	
	return head;
}

NODE deleterear(NODE head)
{
	NODE curr = head;
	
	if (head == NULL)
	{
		printf("Nothing to delete : ");
		return head;
	}
	
	if (head->next == NULL)
	{
		printf("Deleting %s\n", head->s.ssn);
		free(head);
		head = NULL;
		return head;
	}
	
	while (curr->next->next != NULL)
		curr = curr->next;
	
	printf("Deleting %s\n", (head->next->s).ssn);
	free(curr->next);
	curr->next = NULL;
	
	return head;
}

void display(NODE head)
{
	int count = 0;
	if (head == NULL)
	{
		printf("Nothing to display\n");
		return;
	}
	
	NODE curr = head;
	
	for (curr = head; curr != NULL; curr = curr->next, count++)
		printf("%s\n%s\n%s\n%s\n%s\n%d\n\n", curr->s.ssn, curr->s.name, curr->s.dept, curr->s.des, curr->s.phno, curr->s.sal);
	
	printf("\nNumber of nodes in it were %d.\n", count);	
}

NODE create_n(NODE head, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Entering %dth element : \n", i);
		head = insertrear(head);
	}
}

int main()
{
	NODE head = NULL;
	int ch, n;
	
	while (1)
	{
		printf("1. Ins front\n2. Ins rear\n3. Del front\n4. Del rear\n5. Display\n6. Create n elements\n\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: head = insertfront(head);
					break;
			case 2: head = insertrear(head);
					break;
			case 3: head = deletefront(head);
					break;
			case 4: head = deleterear(head);
					break;
			case 5: display(head);
					break;
			case 6: printf("Enter the number of elements to insert : ");
					scanf("%d", &n);
					head = create_n(head, n);
					break;
			default:return 0;
		}
	}
}