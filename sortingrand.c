#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random(int arr[], int len, int max)
{
    for (int i = 0; i < len; i++)
        arr[i] = (rand() % max) + 1;
}

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n ", arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionsort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = arr[i];
        j = i - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionsort(int arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        int indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexofmin])
                indexofmin = j;
        }
        swap(&arr[indexofmin], &arr[i]);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
double time1,timedif;
int main(void)
{
    srand(time(NULL));
    int n;
    int option;
    int arr[n];
    printf("Please Enter the Number of Random Numbers Genrated:\n");
    scanf("%d", &n);
    random(arr, n, 100000000);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]=%d\n", i, arr[i]);
    }
    printf("1-Insertion Sort\n");
    printf("2-Selection Sort\n");
    printf("3-Quick Sort\n");
    printf("4-Merge Sort\n");
    printf("5-Exit\n");
    do
    {
        printf("\n Enter the Option:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            time1 = (double)clock();
            time1 = time1 / CLOCKS_PER_SEC;
            insertionsort(arr, n);
            printf("Sorted Array by insertion sort:\n");
            printarray(arr, n);
            timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
            printf("The elapsed time is %f seconds\n", timedif);
            break;
        }
        case 2:
        {
            time1 = (double)clock();
            time1 = time1 / CLOCKS_PER_SEC;
            selectionsort(arr, n);
            printf("Sorted Array by selection sort:\n");
            printarray(arr, n);
            break;
            timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
            printf("The elapsed time is %f seconds\n", timedif);
        }
        case 3:
        { 
            time1 = (double)clock();
            time1 = time1 / CLOCKS_PER_SEC;
            quicksort(arr, 0, n - 1);
            printf("Sorted Array by quick sort: \n");
            printarray(arr, n);
            timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
            printf("The elapsed time is %f seconds\n", timedif);
            break;
        }
        case 4:
        {
            time1 = (double)clock();
            time1 = time1 / CLOCKS_PER_SEC;
            mergesort(arr, 0, n - 1);
            printf("Sorted Array by merge sort: \n");
            printarray(arr, n);
            timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
            printf("The elapsed time is %f seconds\n", timedif);
            break;
        }
        case 5:
        {
            printf("\n Exit ");
            break;
        }
        default:
        {
            printf("\n Please Enter a Valid Option");
        }
        }
    } while (option != 5);
    return 0;
}
