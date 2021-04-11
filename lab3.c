//stack stuff

#include<stdio.h>
#include<string.h>

#define MAX 10

void push(int stack[], int ele, int *top)
{
	if (*top == MAX -1)
	{
		printf("Overflow\n");
		return;
	}
	*top = *top + 1;
	stack[*top] = ele;
}

int pop(int stack[], int *top)
{
	if (*top == -1)
	{
		printf("Underflow\n");
		return -1;
	}
	
	int ele = stack[*top];
	*top = *top - 1;

	
	return ele;
}

void display(int stack[], int top)
{
	printf("\nThe stack values from the top are : ");
	for (int i = top; i >= 0; i--)
		printf("%d ", stack[i]);
	printf("\n");
}

void check_palindrome(char str[])
{
	int stack[MAX], top = -1;
	for (int i = 0; i < strlen(str); i++)
		push(stack, str[i], &top);
		
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] != pop(stack, &top))
		{
			printf("Not palindrome!\n");
			return;
		}
	}
	
	printf("It was a palindrome.\n");
}



int main()
{
	char str[20];
	int stack[MAX], top = -1, ch, n;
	
	while(1)
	{
		printf("\n\n1. Push\n2. Pop\n3. Check Palindrome\n4. Display\nAnything else : exit\n\nChoice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: printf("Enter the number to be pushed: ");
					scanf("%d", &n);
					push(stack, n, &top);
					break;
			
			case 2: n = pop(stack, &top);
					if (n != -1)
						printf("Popped : %d\n", n);	
					break;
					
			case 3: printf("Enter string to check palindrome: ");
					scanf("%s", str);
					check_palindrome(str);
					break;
				
			case 4: display(stack, top);
					break;
					
			default: return 0;
		}
	}
}
			




















	
