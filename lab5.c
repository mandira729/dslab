#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 5

int solve(int op1, char operator, int op2)
{
	switch(operator)
	{
		case '+': return op1 + op2;
		case '-': return op1 - op2;
		case '*': return op1*op2;
		case '/': return op1/op2;
		case '^': return pow(op1, op2);
		case '%': return op1 % op2;
	}
}

int evaluate_postfix(char postfix[20])
{
	int stack[20], top = -1, operator;
	int op1, op2;
	
	for (int i = 0; i < strlen(postfix); i++)
	{
		if (isdigit(postfix[i]))
			stack[++top] = postfix[i] - '0';
		else
		{
			op2 = stack[top--];
			op1 = stack[top--];
			
			stack[++top] = solve(op1, postfix[i], op2);
		}
	}
	
	return stack[top];
}

void towerofhanoi(int n, char s, char t, char d)
{
	if (n == 0)
		return;
		
	towerofhanoi(n - 1, s, d, t);
	printf("Move disc %d from %c to %c.\n", n, s, d);
	towerofhanoi(n - 1, t, s, d);
}


int main()
{
	char postfix[20];
	int n, ch;
	
	while(1)
	{
		printf("\n1. Postfix expression evaluation.\n2. Tower of Hanoi\nAnything else: exit\nChoice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: printf("\nEnter the postfix expr : ");
					scanf("%s", postfix);
	
					printf("The solution of this expression is %d. \n\n", evaluate_postfix(postfix));
					break;
				
			case 2: printf("\nEnter the number of discs : ");
					scanf("%d", &n);
					towerofhanoi(n, 'A', 'B', 'C');
					break;
					
			default: return 0;
		}
	}	
}
