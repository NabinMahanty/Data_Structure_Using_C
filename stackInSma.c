#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 5
void display();
void push(int ele);
void pop();
int isEmpty();
int isFull();
void display();
void peek();
int stack[N];
int top = -1;
 int main()
 {
   int  ch, ele;
   while (1)
   {
      printf("Enter 1 for push\n");
      printf("Enter 2 for pop\n");
      printf("Enter 3 for peek\n");
      printf("Enter 4 for diplay\n");
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
      }
   }
   return 0;
 }
 void push(int ele)
  {
      if(isFull())
      {
        printf("Stack Over flow\n");
      }
  else
    {
    top = top+1;
    stack[top] = ele;
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
        printf("Poped item is %d\n",stack[top]);
        top--;
      }
  }

  int isFull()
  {
    if(top==N-1)
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
    printf("Top element is %d\n",stack[top] );
  }
  void display()
  {
    int i;
    for (i=0;i<=top;i++)
  {
    printf("%d\n",stack[i] );
  }
  }
