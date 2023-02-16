#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct queue{
    struct node *front;
    struct node *rear;
};
struct queue *q ;
void create_queue(struct queue *);
struct queue *enqueue(struct queue *, int);
struct queue *dequeue(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);
int main()
{
    int val, option;
    create_queue(q);

    printf("\n 1-Enqueue of the element");
    printf("\n 2-Dequeue of the Element");
    printf("\n 3-Peek");
    printf("\n 4-Display the queue");
    printf("\n 5-Exit");
    do
    {
        printf("\n Enter the option");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the number to insert in the queue-");
            scanf("%d", &val);
            q = enqueue(q, val);
            break;
        case 2:
            q = dequeue(q);
            break;
        case 3:
            val = peek(q);
            if (val != -1)
                printf("\n The Value at front of queue is:%d ", val);
            break;
        case 4:
            q = display(q);
            break;
        }
    } while (option != 5);
    return 0;
}
void create_queue(struct queue *q)
{
    q->rear = NULL;
    q->front = NULL;
}
struct queue *enqueue(struct queue *q, int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;                   //the data part of the new node is initialized the value to  be stored in the node
    if (q->front == NULL)              //we check new node is the first node of the linked queue
    {
        q->front = ptr;
        q->rear = ptr;
        q->front->next = q->rear->next = 0;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
        q->rear->next = NULL;
    }
    return q;
}
struct queue *display(struct queue *q)
{
    struct node *ptr;
    ptr = q->front;
    if (ptr == NULL)
        printf("\n Queue is empty");
    else
    {
        printf("\n");
        while (ptr != q->rear)
        {
            printf("%d\t", ptr->data);
            ptr->next;
        }
        printf("%d\t", ptr->data);
    }
    return q;
}
struct queue *dequeue(struct queue *q)
{
    struct node *ptr;
    ptr = q->front;                   // pointer ptr point to front
    if (q->front == NULL)                    // check condition of the underflow        
        printf("\n Queue is underflow");
    else
    {
        q->front = q->front->next;                   // fornt to point to the next node in sequence
        printf("\n The Value being deleted is %d", ptr->data);
        free(ptr);                                       // the memory occupied by ptr is use  to free
    }
    return q;
}
int peek(struct queue *q)
{
    if (q->front = NULL)
    {
        printf("\n Queue is empty");
        return -1;
    }
    else
        return q->front->data;
}