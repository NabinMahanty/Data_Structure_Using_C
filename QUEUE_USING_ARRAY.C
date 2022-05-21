#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 5
int queue[MAX];
int rear = -1;
int front = -1;
void peek();
void enqueue();
void dequeue();
void display();
int main()
{
  int ch;
  while(1)
  {
    printf("Enter 1 for Enque\n");
    printf("Enter 2 for Dequeue\n");
    printf("Enter 3 for Display\n");
    printf("Enter 4 for Peak\n");
    printf("Enter 5 for exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        peek();
        break;
      case 5:
        exit(0);
      default:
      printf("Enter carrect option\n");
    }
  }
  getch();
  return 0;
}
void enqueue()
{
  int data;
  if(rear == MAX-1)
  printf("Queue is full\n" );
  else
  {
    if(rear == -1)
    front = front+1;
    printf("Enter the data:" );
    scanf("%d",&data);
    rear = rear+1;
    queue[rear] = data;
  }
}
void dequeue()
{
  if(front == -1 || front>rear)
  printf("Queue is empty" );
  else
  {
    printf("Dequeue data is: %d\n",queue[front] );
    front++;
  }
}
void display()
{
  int i;
  printf("Queue element are: ");
  for(i=front;i<=rear;i++)
  printf("%d\t",queue[i] );
  printf("\n");
}
void peek()
{
  printf("The peek element is %d\n",queue[front] );
}
