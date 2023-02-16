#include<stdio.h>
int main()
{
    int population=100000,i;
    for(i=0;i<10;i++)
    {
        population=(population)-((population/100)*10);
        printf("%d year -%d\n",10-i,population);
    }
    return 0;
}