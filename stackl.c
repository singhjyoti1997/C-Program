#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);
int main()
{
    int val, option;
    printf("\n 1-Push of the element");
    printf("\n 2-Pop of the element");
    printf("\n 3-Peek");
    printf("\n 4-Display of stack");
    printf("\n 5-Exit");
    do
    {
        printf("\n Enter the Option-");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the number push in the stack");
            scanf("%d", &val);
            top = push(top, val);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            val = peek(top);
            if (val != -1)
                printf("\n the value of the top of stack is %d", val);
            else
                printf("\n stack is empty");
            break;
        case 4:
            top = display(top);
            break;
        }

    } while (option != 5);
    return 0;
}
struct stack *push(struct stack *top, int val)
{
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = val;                    // the data of the new node initialising to the value to be stored in the node
    if (top == NULL)                              // stack is empty , new node is the first node of the linked list 
    {
        ptr->next = NULL;
        top = ptr;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    return top;
}
struct stack *display(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top == NULL)
        printf("\n Stack is empty");
    else
    {
        while (ptr != NULL)
        {
            printf("\n %d", ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}
struct stack *pop(struct stack *top)
{
    struct stack *ptr;
    ptr = top;
    if (top = NULL)                    // stack is empty, deletion of value can not be we done
        printf("\n Stack is Underflow");
    else
    {
        top = top->next;                     // top is point to next node in the sequence
        printf("\n the value is deleted is %d", ptr->data);
        free(ptr);                         // memory occupied by ptr back to free
    }
    return top;
}
int peek(struct stack *top)
{
    if (top == NULL)
        return -1;
    else
        return top->data;
}