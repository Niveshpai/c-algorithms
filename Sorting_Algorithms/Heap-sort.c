// C program to implement Sorting Algorithm using C

#include<stdio.h>
#include<stdlib.h>
int temp;

void heapify(int arr[], int size, int i)
{
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;

  if (left < size && arr[left] >arr[largest])
  largest = left;

  if (right < size && arr[right] > arr[largest])
  largest = right;

  if (largest != i)
  {
    temp = arr[i];
      arr[i]= arr[largest];
      arr[largest] = temp;
   heapify(arr, size, largest);
  }
}

void heapSort(int arr[], int size)
{
  int i;
  for (i = size / 2 - 1; i >= 0; i--)
  heapify(arr, size, i);
  for (i=size-1; i>=0; i--)
  {
    temp = arr[0];
     arr[0]= arr[i];
     arr[i] = temp;
   heapify(arr, i, 0);
  }
}


void readarray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void displayarray(int arr[],int n)
{
     int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main()
{
  int arr[100],i,size ;
  printf("enter the number of elements\n");
  scanf("%d",&size);
  printf("enter the array elements:\n");
  readarray(arr,size);
  heapSort(arr, size);
  displayarray(arr,size);
  return 0;
}
