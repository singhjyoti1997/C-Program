#include<stdio.h>
void swap (int x ,int y);
int main()
{
    int num1 , num2 ;
    printf("Enter the value of num1 and num2:-");
    scanf("%d%d",&num1,&num2);
    swap(num1,num2);
    return 0;
}
void swap(int x , int y)
{
    x=x+y;
    y=x-y;
    x=x-y;
    printf("%d %d",x,y);
}