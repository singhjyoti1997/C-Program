#include <stdio.h>
int main()
{
    int num = 53278;
    int sum = 0;
    while (num != 0)
    {
        sum = sum + num % 10;
        num = num / 10;
    }
    printf("Sum of digit of five numbers:=%d", sum);
    return 0;
}