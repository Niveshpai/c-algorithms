// C program to implement Depth First Search in C

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void dfs(int m[SIZE][SIZE],int v,int source);

void main()
{
   int v,m[SIZE][SIZE],i,j,source;
   printf("enter the number of vertices=");
   scanf("%d",&v);
   printf("enter the graph in the form of matrix\n");
   for(i=0;i<v;i++)
    {
    for(j=0;j<v;j++)
      {
      scanf("%d",&m[i][j]);
      }
    }
   printf("enter the source vertex=");
   scanf("%d",&source);
   printf("THE DFS traversal is\n");
   dfs(m,v,source);
}

void dfs(int m[SIZE][SIZE],int v,int source)
{
  int i,visited[10];
  for(i=0;i<v;i++)
  {
    visited[i]=0;
  }
  visited[source]=1;
  for(i=0;i<v;i++)
  {
    if(m[source][i]==1 && visited[i]==0)
    {
     printf("%d\t",i);
     dfs(m,v,i);
    }
  }
}
