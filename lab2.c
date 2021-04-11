// Pattern replacing question

#include <stdio.h>

int len(char str[])
{
	int l = 0;
	
	while(str[l] != '\0')
		l++;
		
	return l;
}

void pattern_replace(char ans[], char str[], char pat[], char rep[])
{
	//get length of all the strings
	int s = len(str), p = len(pat), r = len(rep);
	int j = 0, k = 0;
	
	for (int i = 0; i < s; i++)
	{
		j = 0;
		while(pat[j] == str[i + j] && j < p && (i + j) < s)
			j++;
			
		if (j == p)
		{
			for (int l = 0; l < r; l++)
				ans[k++] = rep[l];
			i += (p - 1);
		}
		
		else
			ans[k++] = str[i];
	}
	ans[k] = '\0';
}

void get_operands(char str[], char rep[], char pat[])
{
	printf("\nEnter the text : ");
	gets(str);
	
	printf("\nEnter the pattern string : ");
	gets(pat);
	
	printf("\nEnter the replacement string : ");
	gets(rep);
}


int main()
{
	char str[50], rep[50], pat[50], ans[50];
	get_operands(str, rep, pat);
	pattern_replace(ans, str, pat, rep);
	printf("\nNew String : %s\n", ans);
} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		 
