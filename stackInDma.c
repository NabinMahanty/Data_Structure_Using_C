#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int i;
int *ptr = NULL;
int push(int ele);
void pop();
int isFull();
int isEmpty();
void peek();
int top = -1;
void display();
int main()
{
	printf("Enter The ArraySize:- ");
	scanf("%d",&i);
	ptr = (int*)calloc(i,sizeof(int));
	int ch,ele;
	while(1)
	{
		printf("Enter 1 for push\n");
      printf("Enter 2 for pop\n");
      printf("Enter 3 for peek\n");
      printf("Enter 4 for display\n");
      printf("Enter 5 for exit\n");
      scanf("%d",&ch);


      switch (ch)
      {
        case 1:
          printf("Enter a element\n");
          scanf("%d",&ele);
          push(ele);
          break;
        case 2:
          pop();
          break;
        case 3:
          peek();
          break;
        case 4:
          display();
          break;
        case 5:
            exit(0);
          default :
            printf("Enter a valid option\n");
            break;
		}
	}
	free(ptr);
	return 0;
}
int push(int ele)
{
	if(isFull())
	printf("stack overflow!!!\n");
	else
	{
		++top;
//		top = top+1;
		*(ptr+top)=ele;
	}
}

void pop()
{
	int ele;
  if(isEmpty())
  	{
      printf("Stack underFlow\n\n");
     }
      else
     {
        printf("Poped item is %d\n",*(ptr+top));
        top--;
     }
}

int isFull()
{
	if(top==i-1)
	return 1;
	else
	return 0;
}
int isEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void peek()
  {
    printf("Top element is %d\n",*(ptr+top) );
  }
 void display()
  {
    int i;
    for (i=0;i<=top;i++)
   {
    printf("%d\n",*(ptr+top) );
   }
  }

