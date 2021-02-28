// Program to implement Quick Sort in C

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

void quickSort(int [],int ,int );
int partition(int [],int ,int );
void Print(int [],int );
void inputArray(int [],int );

int main()
{
    int a[SIZE],n,i,j,min,temp;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    inputArray(a,n);
    quickSort(a,0,n-1);
    printf("Items of the sorted array\n");
    Print(a,n);
    return 0;
}

void inputArray(int a[],int n)
{
    printf("Enter the items of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

void quickSort(int a[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quickSort(a,l,s-1);
        quickSort(a,s+1,r);
    }

}

int partition(int a[],int l,int r)
{
    int pivot,i,j,temp;
    pivot=a[l];
    i=l;
    j=r;
    while(i<j)
    {
       while(a[i]>=pivot)
       {
          i++;
       }
      
       while(a[j]<=pivot)
       {
          j--;
       }
          //swap a[i] and a[j]  
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
    }
    //swap a[l] and a[j]
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}

void Print(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}
