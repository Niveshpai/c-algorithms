// C program to implement Insert Sorting in C

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void inputArray(int a[],int n)
{
    printf("Enter the items of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

void main()
{
    int a[SIZE],n,i,j,min,temp;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    inputArray(a,n);
    for(i=1;i<=n-1;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]<temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
    printf("Items of the array\n");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
}
