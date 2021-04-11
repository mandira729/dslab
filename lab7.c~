#include <stdio.h>
#include <stdlib.h>

struct student
{
	char usn[10], name[20], programme[20], phno[10];
	int sem;
};
typedef struct student stu;

struct node
{
	stu s;
	struct node *next;
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
	printf("\nEnter usn, name, programme, phno and semester resp : ");
	scanf("%s %s %s %s %d", new->s.usn, new->s.name, new->s.programme, new->s.phno, &(new->s.sem));
	
	
	new->next = head;
	head = new;
	
	return head;
}

NODE insertrear(NODE head)
{
	NODE new = getnode(), curr = head;
	printf("\nEnter usn, name, programme, phno and semester resp : ");
	scanf("%s %s %s %s %d", new->s.usn, new->s.name, new->s.programme, new->s.phno, &(new->s.sem));
	
	
	if (curr == NULL)
	{
		head = new;
		new->next = NULL;
		return head;
	}
	
	while (curr->next != NULL)
		curr = curr->next;
		
	curr->next = new;
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
	printf("Deleting usn %s \n", head->s.usn);
	
	NODE curr = head;
	head = head->next;
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
		printf("Deleting %s\n", head->s.usn);
		free(head);
		head = NULL;
		return head;
	}
	
	while (curr->next->next != NULL)
		curr = curr->next;
	
	printf("Deleting %s\n", (head->next->s).usn);
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
	
	while (curr)
	{
		printf("%s\n%s\n%s\n%s\n%d\n\n", curr->s.usn, curr->s.name, curr->s.programme, curr->s.phno, curr->s.sem);
		count++;
		curr = curr->next;
	}
	
	printf("\nNumber of nodes in it were %d.\n", count);	
}

int main()
{
	NODE head = NULL;
	int ch;
	
	while (1)
	{
		printf("1. Ins front\n2. Ins rear\n3. Del front\n4. Del rear\n5. Display\n\n");
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
			default:return 0;
		}
	}
}
		
		
		
		
		
		
		
				
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
