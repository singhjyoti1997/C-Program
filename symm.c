#include <stdio.h>
int main()
{
    int row, column, i, j, a[20][20], trans[20][20], c = 1;
    printf("Enter the number of rows and column of a matrix-\n");
    scanf("%d %d", &row, &column);
    printf("Enter the number of matrix-\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            trans[j][i] = a[i][j];
        }
    }
    printf("transpose of given  matrix-\n ");
    for (i = 0; i < column; i++)
    {
        for (j = 0; j < row; j++)
        {
            printf("%d\t", trans[i][j]);
        }
        printf("\n");
    }
    if (row == column)
    {
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                if (a[i][j] != trans[i][j])
                {
                    c = 0;
                    break;
                }
            }
            if (c == 0)
            {
                printf("\nthe matrix is not symmetric");
                break;
            }
        }
        if (c == 1)
        {
            printf("\nthe matrix is symmetric");
        }
    }
    else
    {
        printf(" the matrix is not symmetric");
    }

    return 0;
}
