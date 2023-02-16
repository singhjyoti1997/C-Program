#include<stdio.h>
#include<stdlib.h>

void generate_array(int* array, int size) {
    int i;
    for(i = 0; i < size; i++)
        array[i] = rand()%15;
}

void insert(int** map, int size, int key, int value) {
    int i, hash, index;
    hash = key % size;
    for (i = hash; i < size + hash; i++) {
        index = (i % size);
        if (map[index][0] == -9999) {
            map[index][0] = key;
            map[index][1] = value;
            break;
        }
    }
}

int search(int** map, int size, int key) {
    int i, hash, index, flag = 0;
    hash = key % size;
    if (key < 0)
        return -1;
    for (i = hash; i < size + hash; i++) {
        index = (i % size);
        if (map[index][0] == key) {
            return map[index][1];
        }
    }
    return -1;
}

void subArraySum(int* array, int** map, int size) {
    int i, sum = 0, cur_size, min_size = size+1, max_size = 0, index = -1, flag = 0;
    int max_s, max_e, min_s, min_e;
    for (i = 0; i < size; i++) {
        sum += array[i];
        if (sum == 15) {
            cur_size = i + 1;
            if (cur_size < min_size) {
                min_size = cur_size;
                min_s = 0;
                min_e = i;
            }
            if (cur_size > max_size) {
                max_size = cur_size;
                max_s = 0;
                max_e = i;
            }
        }

        index = search(map, size, sum - 15);
        if (index != -1) {
            cur_size = i - index;
            if (cur_size < min_size) {
                min_size = cur_size;
                min_s = index+1;
                min_e = i;
            }
            if (cur_size > max_size) {
                max_size = cur_size;
                max_s = index+1;
                max_e = i;
            }
        }
        insert(map, size, sum, i);
    }
    if (max_size != 0) {
        printf("largest subarry with sum 15 is of size: %d between indeces %d and %d\n", max_size, max_s, max_e);
        flag = 1;
    }
    if (min_size != size + 1) {
        printf("smallest subarry with sum 15 is of size: %d between indeces %d and %d\n", min_size, min_s, min_e);
        flag = 1;
    }
    if (flag == 0)
        printf("No subarray found with sum 15\n");
}

int main(void) {
    int size, i;
    int *array;
    int** map;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    map = (int**)malloc((size+1) * sizeof(int));
    for(i = 0; i < size; i++) {
        map[i] = (int*)malloc(2 * sizeof(int));
        map[i][0] = -9999;
    }

    array = (int *)malloc(size * sizeof(int));
    generate_array(array, size);
    printf("Generated random array is: ");
    for(i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");

    subArraySum(array, map, size);
}