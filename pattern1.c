#include<stdio.h>
int main()
{
    int row,column,space,num=3,n=1;
    for(row=1;row<=num;row++)
    {
        
        for(column=1;column<=row;column++)
        {
            printf(" %d",n);
            n++;
        }
        printf("\n");
    }
    return 0;
}