// Character circular queue

#include <stdio.h>
#define MAX 10

void insert(char cqueue[], int *rear, int *count)
{
	char ele;
	if (*count == MAX)
	{
		printf("Overflow conditiAon\n");
		return;
	}
	
	printf("\nEnter the character to be inserted : ");
	scanf(" %c", &ele);
	
	*rear = (*rear + 1) % MAX;
	cqueue[*rear] = ele;
	*count += 1;
}

char delete(char cqueue[], int *front, int *count)
{
	char ch;
	if (*count == 0)
	{
		printf("Underflow condition");
		return '\0';
	}
	
	printf("Removing %c\n", cqueue[*front]);
	ch = cqueue[*front];
	*front = (*front + 1) % MAX;
	*count -= 1;
	
	return ch;
}

void display(char cqueue[], int front, int count)
{
	if (count == 0)
		printf("Nothing in the queue");

	while(count--)
	{
		printf("%c\n", cqueue[(front)%MAX]);
		front += 1;
	}
	
	printf("\n");
}


int main()
{
	int front = 0, rear = -1, count = 0, ch;
	char cqueue[MAX], ele;
	
	while (1)
	{

		printf("\n1. Insert\n2. Delete\n3. Display\nAnything else: exit : ");
		scanf("%d", &ch);
		

		switch(ch)
		{
			case 1: 	insert(cqueue, &rear, &count);

						break;
						
			case 2: 	delete(cqueue, &front, &count);
						break;
						
			case 3:		display(cqueue, front, count);
						break;
			
			default: 	return 0;
		}
	}
}
















		
		
		
		
		
