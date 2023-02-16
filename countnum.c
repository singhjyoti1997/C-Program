#include<stdio.h>
int main()
{
   int num , positive_num=0, negative_num=0, zero_num=0 , limit_num=0;
   printf("Enter the user want limit of number-");
   scanf("%d",&limit_num);
   while(limit_num)
   {
    scanf("%d",&num);
    (num>0)?(positive_num++):((num<0)?(negative_num++):(zero_num++));
    limit_num--;
   }
printf("total positive numbers are - %d\n",positive_num);
printf("total negative numbers are - %d\n",negative_num);
printf("total zero numbers are - %d\n",zero_num);
return 0 ;
} 