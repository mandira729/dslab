#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int F(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':	return 2;
		
		case '*':
		case '%':
		case '/': 	return 4;
		
		case '^':
		case '$':	return 5;
		
		case '(': 	return 0;
		case '#': 	return -1;
		
		default:	return 8;
	}
}

int G(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':	return 1;
		
		case '*':
		case '%':
		case '/':	return 3;
		
		case '^':
		case '$':	return 6;
		case '(':	return 9;
		case ')': 	return 0;
		
		default: 	return 7;
	}
}

int main()
{
	char str[20];
	printf("Enter the infix string : ");
	scanf("%s", str);
	char stack[20], symbol, postfix[20];
	
	int top = -1, j = 0;
	stack[++top] = '#';
	
	for (int i = 0; i < strlen(str); i++)
	{
		// printf("%d", i);
		symbol = str[i];
		while(F(stack[top]) > G(symbol))
		{
			postfix[j++] = stack[top--];

		}
		if (F(stack[top]) != G(symbol))
			stack[++top] = symbol;
		else
			top--;
	}
	
	while (stack[top] != '#')
		postfix[j++] = stack[top--];
	postfix[j] = '\0';
	
	printf("\nPostfix expression is : %s\n", postfix);
	return 0;
}


















