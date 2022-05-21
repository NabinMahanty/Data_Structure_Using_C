/* Circular Queue */
#include <stdio.h>
#include <conio.h>
#define MAX 5
typedef struct
{
    int item[MAX];
    int front, rear;
} queue;
void createQ(queue *);
void enQ(queue *, int);
int isFull(queue *);
int isEmpty(queue *);
void display(queue);
int DeQ(queue *);
int main()
{
    queue q;
    int choice, x;
    createQ(&q); /* initialization of queue*/
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&q))
            {
                printf("Queue is Full...\nPress any key...");
                getch();
            }
            else
            {
                printf("Enter any Value to insert:");
                scanf("%d", &x);
                enQ(&q, x);
            }
            break;
        case 2:
            if (isEmpty(&q))
            {
                printf("Queue is Empty...\nPress any key...");
            }
            else
            {
                x = DeQ(&q);
                printf("\n %d is Dqueued\nPress anykey...", x);
            }
            getch();
            break;
        case 3:
            if (isEmpty(&q))
            {
                printf("Queue is Empty...\nPress any key...");
            }
            else
            {
                display(q);
            }
            getch();
            break;
        }
    } while (choice != 4);
    return 0;
}
void createQ(queue *q)
{
    q->front = q->rear = -1;
    return;
}
void enQ(queue *q, int x)
{
    if (q->front == -1)
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % MAX;
    q->item[q->rear] = x;
}
int isFull(queue *q)
{
    if (q->front == (q->rear + 1) % MAX)
        return 1;
    else
        return 0;
}
int isEmpty(queue *q)
{
    if (q->front == -1)
        return 1;
    else
        return 0;
}
void display(queue q)
{
    int i;
    if (q.front <= q.rear)
    {
        for (i = q.front; i <= q.rear; i++)
            printf("\t%d", q.item[i]);
    }
    else
    {
        for (i = q.front; i <= MAX - 1; i++)
            printf("\t%d", q.item[i]);
        for (i = 0; i <= q.rear; i++)
            printf("\t%d", q.item[i]);
    }
    return;
}
int DeQ(queue *q)
{
    int value;
    value = q->item[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;
    return value;
}
