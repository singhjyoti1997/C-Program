#include<stdio.h>
void primefactor(int);
int main()
{
    int num;
    printf("Enter the positive interger:-");
    scanf("%d",&num);
    primefactor(num);
    return 0;
}
void primefactor( int num)
{
    int i;
    for(i=2;num>1;i++)
    {
        while(num%i==0)
        {
            printf(" %d ",i);
            num=num/i;
        }
    }
}