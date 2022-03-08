#include<stdio.h>
void insertionsort(int arr[],int size)
{
	int i,j,k,temp;
	for(i=1;i<size;i++)
	{
		temp=arr[i];
		for(j=i-1;j>=0 && arr[j]>temp;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
	}
	for(k=0;k<size;k++)
	{
		printf("%d	",arr[k]);
	}
}
int main()
{
	int arr[]={5,4,10,1,6,2};
	int size;
	size=sizeof(arr)/sizeof(arr[0]);
	insertionsort(arr,size);
	return 0;
}
