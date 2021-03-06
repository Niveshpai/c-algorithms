// Program to implement Merge Sort in C

#include<stdio.h>
#include<stdlib.h>

void mergeSort(int [],int ,int );
void merge(int [],int ,int ,int );
void inputArray(int [],int );
void printArray(int [],int );

int main()
{
    int a[100],b[100],c[100],i,j,d,n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    inputArray(a,n);
    mergeSort(a,0,n-1);
    printArray(a,n);
    return 0;
}

void inputArray(int a[],int n)
{
    printf("Enter the items of the array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
}

void mergeSort(int a[],int l, int r)
{
    int m;
    if(r>l)
    {
        m=(l+r-1)/2;
     mergeSort(a,l,m);
     mergeSort(a,m+1,r);
     merge(a,l,m,r);
    }
}

void merge(int a[],int l,int m,int r)
{
    int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[i+l];
    for(j=0;j<n2;j++)
        R[j]=a[j+m+1];
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
         if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
            a[k] = L[i];
            i++;
            k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}
