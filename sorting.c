#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, num, max, temp;
    printf(" Enter the lower limit of random numbers \n");
    scanf("%d", num);

    printf(" Enter the upper limit of random number: \n");
    scanf("%d", max);

    printf(" random number from %d to %d number are: \n", num, max);
    random();

    for (i = 1; i <= num; i++)
    {
        temp = random(max);
        printf(" %d ", temp);
    }
    return 0;
}
