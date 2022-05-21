#include <stdio.h>
#include <conio.h>
int binsearch(int a[],int beg, int end,int item)
{
  beg = 0;
  int mid = (beg+end)/2;
  while((beg<=end)&&(item!=a[mid]))
  {
  if(item<a[mid])
  end = mid-1;
  else
  beg = mid+1;
  mid=(beg+end)/2;
  }

  if(beg>end)
  return -1;
  else
  return mid;
}
int main()
{
  int a[] = {2,4,6,8,10};
  int loc,n,item;
  // clrscr();
  printf("0 to 10 even number\n");
  n = 5;
  printf("Enter data you want to search: ");
  scanf("%d",&item);
  loc = binsearch(a,0,n-1,item);
  if(loc==-1)
  printf("Item not found");
  else
  printf("Item is at index %d\n",loc);
  getch();
  return 0;
}
