#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void dequeue();
void enqueue();
void display();

struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL,*tail = NULL;
int main()
{
  int ch;
  while(1)
  {
  printf("Enter 1 for Enque\n");
  printf("Enter 2 for Dequeue\n");
  // printf("Enter 3 for Display\n");
  // printf("Enter 4 for Peak\n");
  printf("Enter 3 for exit\n");
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
  struct node *newnode = NULL;
  newnode = (struct node *)malloc(sizeof(struct node));
  printf("Enter the data");
  scanf("%d",&newnode->data);
  newnode->next = NULL;
  if(head == NULL)
  {
    head = newnode;
    tail = newnode;
  }
  else
  {
    tail->next = newnode;
    tail = newnode;
  }
}
void dequeue()
{
  if(head == NULL)
  printf("Queue is empty\n");
  else
  {
    struct node *temp = head;
    while (temp!= NULL)
     {
       printf("%d\t",temp->data );
       temp = temp->next;
    }
  }
}
