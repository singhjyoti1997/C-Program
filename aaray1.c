#include <stdio.h>
int main()
{
    int a[20], b[20], c[40], i, m, n, total_size;
    printf("Enter the size of first array-");
    scanf("%d", &m);
    printf("Enter the element of first array-");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the size of second array-");
    scanf("%d", &n);
    printf("Enter the element of second array-");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    total_size = m + n;
    for (i = 0; i < m; i++)
    {
        c[i] = a[i];
    }

    for (i = 0; i < n; i++)
    {
        c[i + m] = b[i];
    }
    printf("Add of the first and second array-");
    for (i = 0; i < total_size; i++)
    {
        printf(" %d", c[i]);
    }
    return 0;
}