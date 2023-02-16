#include <stdio.h>
int main()
{
    int rs = 0, one = 0, two = 0, five = 0, ten = 0, fifty = 0,
     hundred = 0;
    printf("Enter the sum of rupees:-");
    scanf("%d", &rs);
    if (rs >= 100)
    {
        hundred = rs / 100;
        rs = rs % 100;
    }
    if (rs >= 50)
    {
        fifty = rs / 50;
        rs = rs % 50;
    }
    if (rs >= 10)
    {
        ten = rs / 10;
        rs = rs % 10;
    }
    if (rs >= 5)
    {
        five = rs / 5;
        rs = rs % 5;
    }
    if (rs >= 2)
    {
        two = rs / 2;
        rs = rs % 2;
    }
    if (rs >= 1)
    {
        one= rs;
    }
    printf("Rs 100 =%d\n", hundred);
    printf("Rs 50=%d\n", fifty);
    printf("Rs 10=%d\n", ten);
    printf("Rs 5=%d\n", five);
    printf("Rs 2=%d\n", two);
    printf("Rs 1=%d\n", one);
    return 0;
}
