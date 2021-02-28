// Program to implement Bubble Sort in C

#include<stdio.h>
#include<stdlib.h>

void bubblesort(int a[],int n)
{
  int i,j,temp;
  for(i=0;i<=n-2;i++)
  {
    for(j=0;j<=n-2-i;j++)
    {
      if(a[j+1]<a[j])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
  printf("elements after sorting\n");
  for(i=0;i<n;i++)
  {
     printf("%d\t",a[i]);
  }
}

int main()
{
  int i,n,a[10];
  printf("enter the number of elements=");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
  }
  bubblesort(a,n);
  return 0;
}
