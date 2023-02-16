#include <stdio.h>
int main()
{
    int a[20], b[20], c[40], i, j = 0, m, n, total_size;
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
    for (i = 0; i < n; i++)
    {
        c[i] = b[i];
    }
    for (i = 0; i < m; i++)
    {
        c[i + n] = a[i];
    }
    printf("Add of the second and first array-");
    for (i = 0; i < total_size; i++)
    {
        printf(" %d", c[i]);
    }
    return 0;
}