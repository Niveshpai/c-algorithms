// C program to implement Dijkstra's algorithm

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 100

int min(int dist[],int visited[],int n)
{
    int min,i=0,j=0;

    for(i=0;i<n;i++)
    {
        if(visited[i]!=1)
        {
            min=i;
            break;
        }
    }
    for(j=0;j<n;j++)
    {
        if(visited[j]==0&&dist[j]<dist[min])
        {
            min=j;
        }
    }
    return min;
}

int minimum(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int main()
{   ///n->no.of vertices
    int dist[SIZE],path[SIZE],i,j,n,weight[SIZE][SIZE],sv,visited[SIZE],u;
    printf("Enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the weight matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&weight[i][j]);
    printf("Enter the source vertex\n");
    scanf("%d",&sv);
    for(i=0;i<n;i++)
    {
      dist[i]=weight[sv][i];
      if(i==sv)
      {
          visited[sv]=1;
      }
      else
        visited[i]=0;
    }

    for(i=0;i<n;i++)
        path[i]=sv;

    for(i=0;i<n;i++)
    {
        u=min(dist,visited,n);
        visited[u]=1;
        for(j=0;j<n;j++)
           {
               if(visited[j]==0)
               {
                   dist[j]=minimum(dist[j],(weight[u][j]+dist[u]));
               }
           }

    }
      for(i=0;i<n;i++)
        printf("Least distance from source-vertex %d to vertex %d is %d units\n",sv,i,dist[i]);
    printf("\n");
    /*for(i=0;i<n;i++)
        printf("%d\t",visited[i]);*/
    return 0;
}
