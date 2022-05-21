#include <stdio.h>
#include <stdlib.h>
void heapsort(int arr[], int size);
void heapify(int arr[], int size);
void reheapDown(int arr[],int start, int finish);
int main()
{
  int arr[50],size,i;
  printf("Enter how many element you want to sort(MAX 50) = " );
  scanf("%d",&size );
  printf("Enter %d element:",size );
  for(i=1;i<=size;i++)
  scanf("%d",&arr[i] );
	heapsort(arr,size);
  printf("\n\nSorted list of element\n");
  for(i=1; i<=size;i++)
  {
    printf("%d\t",arr[i]);
  }
	return 0;
}
void heapsort(int arr[], int size)
{
  int i,temp;
  heapify(arr, size);
  for(i=size; i>1; i--)
  {
    temp = arr[1];
    arr[1] = arr[i];
    arr[i] = temp;
    reheapDown(arr,1,i-1);
  }
}
void reheapDown(int arr[],int start, int finish)
{
  int index, lchild, rchild, maximum, temp;
  lchild = 2*start;
  // rchild = lchild+1;
  rchild = (2*start)+1;
  if(lchild<=finish)
  {
    maximum = arr[lchild];
    index = lchild;
    if(rchild<=finish)
    {
      if(arr[rchild]>maximum)
      {
        maximum = arr[rchild];
        index = rchild;
      }
    }
    if(arr[start]<arr[index])
    {
      temp = arr[start];
      arr[start] = arr[index];
      arr[index] = temp;
      reheapDown(arr, index, finish);
    }
  }
}
void heapify(int arr[], int size)
{
  int i,index;
  index = size/2;
  for(i=index; i>=1; i--)
  reheapDown(arr,i,size);
}
