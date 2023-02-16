#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, i, x, y;
    printf("Enter the size:- ");
    scanf("%d", &x);

    ptr = (int *)malloc(x * sizeof(int));

    printf("Addresses of x allocated memory is :-\n");
    for (i = 0; i < x; i++)
        printf("%p\n", ptr + i);

    printf("\n Enter the new size:- ");
    scanf("%d", &y);

    ptr = realloc(ptr, y * sizeof(int));

    printf("Addresses of y allocated memory:\n");
    for (i = 0; i < y; i++)
        printf("%p\n", ptr + i);

    free(ptr);

    return 0;
}
