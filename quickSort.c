#include <stdio.h>
void quickSort(int number[50],int first, int last)
{
  int i,j,pivot,temp;
  if(first<last)
  {
    pivot = first;
    i = first;
    j = last;
    while(i<j)
    {
      while(number[i]<=number[pivot]&&i<last)
      i++;
      while(number[j]>number[pivot])
      j--;
      if(i<j)
      {
        temp = number[i];
        number[i] = number[j];
        number[j] = temp;
      }
    }
    temp = number[pivot];
    number[pivot] = number[j];
    number[j] = temp;
    quickSort(number,first,j-1);
    quickSort(number,j+1,last);
  }
}

int main()
{
  int i,count,number[50];
  printf("Enter how many element you want to sort(MAX 50) = ");
  scanf("%d",&count);
  printf("Enter %d element:",count);
  for(i=0;i<count;i++)
  scanf("%d",&number[i] );
  quickSort(number, 0, count-1);
  printf("The sorted order is : " );
  for(i = 0; i<count; i++)
  printf("\t%d",number[i] );
  return 0;
}
