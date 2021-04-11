// Array operations
#include <stdio.h>

int create(int arr[]);
int insert_at(int arr[], int ele, int pos, int n);
int delete_from(int arr[], int pos, int n);
void display(int arr[], int n);
					
int main()
{
	int arr[20], ch, ele, pos, n = 0;
	
	while(1)
	{
		printf("\n1. Create an array\n2. Insert at a pos\n3. Delete from a pos\n4. Display\nAny other key : Exit\n\nChoice : ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: n = create(arr);
					break;
			
			case 2: printf("\nEnter the element and its position :");
					scanf("%d %d", &ele, &pos);
					n = insert_at(arr, ele, pos, n);
					break;
					
			case 3: printf("\nEnter the position to be deleted :");
					scanf("%d", &pos);
					n = delete_from(arr, pos, n);
					break;
					
			case 4: display(arr, n);
					break;
					
			default: return 0;
					
		}
	}
}

int create(int arr[])
{
	int n;
	printf("\nEnter the size of the array(max 20) : ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		printf("Enter %dth element : ", i);
		scanf("%d", &arr[i]);
	}
	
	return n;
}


int insert_at(int arr[], int ele, int pos, int n)
{
	if (pos < 0 || pos > n)
	{
		printf("\nInvalid position.");
		return n;
	}
	
	if (pos == n - 1)
	{
		arr[n] = ele;
		n++;
		return n;
	}
	
	int start = n, target = pos;
	while (start != target)
	{
		arr[start] = arr[start - 1];
		start--;
	}
		
	arr[pos] = ele;
	
	n++;
	return n;
}

int delete_from(int arr[], int pos, int n)
{
	if (pos < 0 || pos >= n)
	{
		printf("\nInvalid position");
		return n;
	}
	
	for (int i = pos; i < n - 1; i++)
		arr[i] = arr[i + 1];
		
	n--;
	return n;
}


void display(int arr[], int n)
{
	printf("\nArray contains : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}




































