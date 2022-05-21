/* STACK implementation using Linked List */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct nodetype
{
int data;
struct nodetype *link;
}stack;
void push(stack **);
int pop(stack **);
void displaystack(stack *);
void deletestack(stack **);
int main()
{
stack *top=NULL;
int v,choice;
do
{
// clrscr();
printf("1. Push\n");
printf("2. Pop\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
// clrscr();
switch(choice)
{
case 1:
push(&top);
break;
case 2:
if(NULL==top)
{
printf("Stack is empty...\nPress any key...");
}
else
{
v=pop(&top);
printf("Item popped=%d",v);
printf("\nPress any key...");
}
getch();
break;
case 3:
if(NULL==top)
{
printf("Stack is empty...\nPress any key...");
}
else
{
displaystack(top);
}
getch();
break;
}
}while(choice!=4);
deletestack(&top);
return 0;
}
void push(stack **top)
{
stack *ptr;
int value;
ptr=(stack *)malloc(sizeof(stack));
if(NULL==ptr)
{
printf("Memory not allocated...\nPress any key...");
getch();
}
else
{
printf("Enter any data value:");
scanf("%d",&value);
ptr->data=value;
ptr->link=*top;
*top=ptr;
}
}
int pop(stack **top)
{
int temp;
stack *ptr;
ptr=*top;
temp=ptr->data;
*top=ptr->link;
free(ptr);
return temp;
}
void displaystack(stack *top)
{
while(top!=NULL)
{
printf("\n%d",top->data);
top=top->link;
}
}
void deletestack(stack **top)
{
stack *ptr;
while(*top!=NULL)
{
ptr=*top;
*top=ptr->link;
}
}
