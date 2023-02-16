#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int main()
{
    int option,val;
    struct queue q;
    q.size = 100;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    printf("\n 1- Insert an element");
    printf("\n 2- delete an element");
    printf("\n 3- peek");
    printf("\n 4- Exit");
    do
    {
        printf("\n Enter your Option-");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            printf("\n the dequeueing element %d", dequeue(&q));
            break;
        case 3:
            Isfull();
            prinff("Queue is Overflow");
            break;
        }
    } while (option != 4);
  
    return 0;
}
int Isfull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q ,int val)
{
    int num;
    printf("\n Enter the number to be inserted in the queue:");
    scanf("%d", &num);
    if (Isfull(q))
    {
        printf("this Queue is overflow");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] == val;
    }
}
int IsEmpty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int dequeue(struct queue *q, int val)
{
    int a = -1;
    if (IsEmpty(q))
    {
        printf("queue is empty");
    }
    else
    {
        q->front++ ;
        a == q->arr[q->front];
    }
    return a;
}