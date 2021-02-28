// Program to implement Selection Sort in C

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void inputArray(int a[],int n)
{
    printf("Enter the items of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

int main()
{
    int a[SIZE],n,i,j,min,temp;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    inputArray(a,n);
    for(i=0;i<=n-2;i++)
    {
        min=i;
        for(j=i+1;j<=n-1;j++)
        {
          if(a[j]<a[min])
            {
               min=j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    printf("Items of the array\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
  return 0;
}
