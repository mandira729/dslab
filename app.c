#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int visited[MAX];
int a[MAX][MAX]; //adjacency matrix
 //no. of vertices
void ReadAdjMatrix(int);
void dfs(int,int);
int main()
{
   int start;
   int n;
   printf("enter the no. of vertices\n");
   scanf("%d", &n);
   ReadAdjMatrix(n);
   
   for(int source=0;source<n;source++){
      for(int i=0;i<n;i++)
         visited[i]=0;
      printf("NOdes reachable from %d: ",source);
      dfs(source,n);
      printf("\n");
   }
   return 0;
}
void ReadAdjMatrix(int n)
{
int i,j;

printf("enter Adjacency matrix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d", &a[i][j]);
}
void dfs(int v,int n)
{
   int w;
   printf("%d->",v);
   visited[v]=1;
   for(w=0;w<n;w++)
   {
      if(visited[w]==0 &&a[v][w]==1)
      dfs(w,n);
   }
}