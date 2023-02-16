#include <stdio.h>
#define MAX 20
int queue[MAX];
int size;
int front = -1, rear = -1;
void enqueue(void);
void dequeue(void);
void display(void);
void reverse();
int main()
{
    int option;
    printf("\n Enter the size of Queue:-");
    scanf("%d", &size);
    printf("\n 1-Enqueue of the Element"); // Insertion of the element in the queue
    printf("\n 2-Dequeue of the Element"); // Deletetion of the element in the queue
    printf("\n 3-Display the queue");
    printf("\n 4-Reverse the queue");
    printf("\n 5-Exit");
    do
    {
        printf("\n Enter the Option:-");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            enqueue();
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            reverse(front, rear);
            printf("\n Elements the of queue reversed");
            break;
        }
        case 5:
        {
            printf("\n Exit ");
            break;
        }
        default:
        {
            printf("\nPlease enter a Valid Option");
        }
        }
    } while (option != 5);
    return 0;
}

void enqueue()
{
    int num;
    printf("\n Enter the number to be inserted in the queue:");
    scanf("%d", &num);
    if (rear == size - 1) // Condition of the queue is full queue is overflow
        printf("\n Queue is Overflow");
    else if (front == -1 && rear == -1) // Condition is there is no element in the queue
        front = rear = 0;
    else
        rear++; // the value is stored in the queue at the pointed by rear
    queue[rear] = num;
}
void dequeue()
{
    if (front == -1 || front > rear) // Condition of the underflow
    {
        printf("\n Queue is Underflow");
    }
    else
    {
        printf("\n the dequeueing element is %d", queue[front]);
        front++;
    }
}
void display()
{
    int i;
    printf("\n");
    if (front == -1 || front > rear)
        printf("\n Queue is empty");
    else
    {
        for (i = front; i <= rear; i++)
            printf("\t %d", queue[i]);
    }
}
void reverse(int front, int rear)
{
    if (front >= rear)
    {
        return;
    }
    int temp = queue[front];
    queue[front] = queue[rear];
    queue[rear] = temp;
    reverse(front + 1, rear - 1);
    return;
}
