#include<stdio.h>
int stack[100],
ch,size,top,pushvalue,i;
void push(void);
void pop(void);
void display(void);
int main()
{
    top=-1;
    printf("\n Enter the size of Stack:");
    scanf("%d",&size);
    printf("\n\t 1.Push\n\t 2.pop\n\t 3.Display\n\t 4.Exit");
    do
    {
        printf("\n Enter the Choice:-");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n Exit point ");
                break;
            }
            default:
            {
                printf ("\n\t Please enter a Valid Choice");
            }
                
        }
    }
    while(ch!=4);
    return 0;
}
void push()
{
    if(top>=size-1)
    {
        printf("\n\tStack is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&pushvalue);
        top++;
        stack[top]=pushvalue;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in Stack \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n  Next Choice");
    }
    else
    {
        printf("\n Stack is empty");
    }
}