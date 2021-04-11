// graph of N cities
#include <stdio.h>
#include <stdlib.h>



void create (int adj[][20], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("\nIs there a link from city %d to %d ? (1/0) :", i, j);
			scanf("%d", &adj[i][j]);
		}
	}
}

void printadj(int adj[][20], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", adj[i][j]);
		}
		printf("\n");
	}
}

void dfs(int u, int adj[][20], int visited[], int n)
{
	printf("%d ", u);
	visited[u] = 1;
	
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0 && adj[u][i] == 1)
			dfs(i, adj, visited, n);
	}
}

void bfs(int u, int adj[][20], int visited[], int n)
{
	int queue[50], front = 0, rear = -1;
	queue[++rear] = u;
	visited[u] = 1;
	int x;
	
	while (front <= rear)
	{
	    for (int k = front; k <= rear; k++)
	    	printf("q %d : ", queue[k]);
	    printf("\n");
	    
		x = queue[front++];
		printf("%d ", x);
		
		for (int i = 0; i < n; i++)
		{
			if (adj[x][i] == 1 && visited[i] == 0)
			{
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

// 0 0 0 0 0 0 0 1 1 1 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0


int main()
{
	int n, adj[20][20], ch, visited[20], u;
	
	while (1)
	{
		printf("\n1. Create graph of n cities\n2. DFS & BFS from a node\nDefault : exit");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: printf("Enter number of cities : ");
					scanf("%d", &n);
					create(adj, n);
					printadj(adj, n);
					break;
			
			case 2: for (int i = 0; i < n; i++)
						visited[i] = 0;
					printf("\nEnter city number : ");
					scanf("%d", &u);
					printf("\nDFS : ");
					dfs(u, adj, visited, n);
					
					for (int i = 0; i < n; i++)
						visited[i] = 0;
					printf("\nBFS : ");
					bfs(u, adj, visited, n);	
					
					break;
					
			default: return 0;
					
		}
	}
}

