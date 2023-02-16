#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double time1, timedif;
void random(int array[], int length, int max)
{
    for (int i = 0; i < length; i++)
        array[i] = (rand() % max) + 1;
}
void printArray(int array[], int size_arr)
{
    for (int i = 0; i < size_arr; ++i)
    {
        printf("%d\n ", array[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int array[], int size_arr)
{
    for (int step = 0; step < size_arr - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size_arr; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        swap(&array[min_idx], &array[step]);
    }
}
void insertionSort(int array[], int size_arr)
{
    for (int step = 1; step < size_arr; step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}
int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
int main(void)
{
    srand(time(NULL));
    int size_arr;
    int choice;
    int array[size_arr];
    printf("Please enter the number of random numbers to be genrated:\n");
    scanf("%d", &size_arr);
    random(array, size_arr, 10000);
    for (int i = 0; i < size_arr; i++)
    {
        printf("a[%d]=%d\n", i, array[i]);
    }
    printf("\n\t 1.selection sort\n\t 2.insertion sort\n\t 3.quick sort\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            time1 = (double)clock();
            time1 = time1 / CLOCKS_PER_SEC;
            selectionSort(array, size_arr);
            timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
            printf("The elapsed time is %f seconds\n", timedif);
            break;
        }
        case 2:
        {
            time1 = (double)clock();
            time1 = time1 / CLOCKS_PER_SEC;
            insertionSort(array, size_arr);
            timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
            printf("The elapsed time is %f seconds\n", timedif);
            break;
        }
        case 3:
        {
            time1 = (double)clock();
            time1 = time1 / CLOCKS_PER_SEC;
            quickSort(array, 0, size_arr - 1);
            timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
            printf("The elapsed time is %f seconds\n", timedif);
            break;
        }
        case 4:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        default:
        {
            printf("\n\t Please enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (choice != 4);

    return 0;
}