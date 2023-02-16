#include<stdio.h>
int main()
{
    int row, column,space ,num=5,n;
    for(row=0;row<num;row++)
    {
        for(space=0;space<num-row;space++)
        {
            printf(" ");
        }
        n=1;
        for(column=0;column<=row;column++)
        {
          printf(" %d",n);
          n=(n*(row-column)/(column+1));
        }
        printf("\n");
    }
    return 0 ;
}