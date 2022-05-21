#include <stdio.h>
#include <stdlib.h>
void append();
void display();
int length();
void add_at_begin();
void add_at_position();
void deleteFromBeg();
void deletelist();

struct node
{
  int data;
  struct node *link;
};
struct node*root=NULL;
int main()
{
  int ch,l;
  while(1)
  {
    printf("Press 1 for Append\n");
    printf("Press 2 for Display\n");
    printf("Press 3 for length_of_List\n");
    printf("Press 4 for add_at_begin\n");
    printf("Press 5 for add_at_position\n");
    printf("Press 6 for Delete from Beginning\n");
    printf("Press 7 for Delete List\n");
    printf("Press 8 for Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        append();
        break;
      case 2:
          display();
          break;
      case 3:
            l=length();
            printf("Length of list = %d\n",l);
            break;
      case 4:
            add_at_begin();
            break;
      case 5:
            add_at_position();
            break;
      case 6:
            deleteFromBeg();
            break;
      case 7:
            deletelist();
      case 8:
            exit(0);
    }
  }
  return 0;
}

void append()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&temp->data);
  temp->link = NULL;
  if(root==NULL)
  {
      root = temp;
  }
  else
  {
    struct node*p = root;
    while(p->link!=NULL)
    {
      p=p->link;
    }
    p->link = temp;
  }
}

void display()
{
  struct node *p = root;
  if(p==NULL)
  {
    printf("List is empty\n" );
  }
  else
    {
      while(p!=NULL)
      {
        printf("\n%d",p->data);
        p = p->link;
      }
      printf("\n");
    }
  }


  int length()
  {
    int count = 0;
    struct node *temp = root;
    while(temp!=NULL)
    {
      count++;
      temp = temp->link;
    }
    return count;
  }
void  add_at_begin()
{
  struct node *temp;
  temp =  (struct node *)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&temp->data);
  temp->link = NULL;
  if(root==NULL)
  {
    root = temp;
  }
  else
  {
    temp->link=root;
    root = temp;
  }
}

void add_at_position()
{
  struct node *temp = NULL,*p=NULL;
  int pos, i= 1;
  printf("Enter the position" );
  scanf("%d",&pos );
  if(pos>length())
  {
    printf("Invalid position\n");
    printf("Currently list having %d nodes\n",length() );
  }
  else
  {
    p = root;
    while(i<pos)
    {
      p = p->link;
      i++;
    }
  }
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&temp->data);
  temp->link = NULL;
  temp->link = p->link;
  p->link = temp;
}
void deleteFromBeg()
{
  struct node *p = root;
  if(p==NULL)
  {
    printf("List is empty\n" );
  }
  else
  p = root;
  root = root->link;
  free(p);
}
void deletelist()
{
  struct node *p = root;
  while(NULL != root)
  {
    p = root;
    *root = *root->link;
    free(p);
  }
}
