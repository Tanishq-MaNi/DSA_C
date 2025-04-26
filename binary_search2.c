#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct array
{
    int max_size;
    int used_size;
    int *arr_ptr;
} Array;

void create(Array *array, int msize, int usize)
{
    array->max_size = msize;
    array->used_size = usize;
    array->arr_ptr = (int *)malloc(msize * sizeof(int));
}

void random_array(Array *array)
{
    srand(time(0));
    // Generate a random number between 1 and 100
    for (int i = 0; i < array->used_size; i++)
    {
        int random = (rand() % 100) + 1;
        (array->arr_ptr)[i] = random;
    }
}

void sort(Array *array)
{
    int temp, j;

    // Insertion sort algorithm
    for (int i = 1; i < array->used_size; i++)
    {
        temp = (array->arr_ptr)[i];
        j = i - 1;

        while (j >= 0 && (array->arr_ptr)[j] > temp)
        {
            (array->arr_ptr)[j + 1] = (array->arr_ptr)[j];
            j--;
        }
        (array->arr_ptr)[j + 1] = temp; // Place the current element in its correct position
    }
}

void binary_search(Array array, int num)
{

    int first = 0, last = (array.used_size) - 1, mid;

    while (first <= last)
    {
        mid = (first + last) / 2;
        if (array.arr_ptr[mid] < num)
        {
            first = mid + 1;
        }
        else if (array.arr_ptr[mid] > num)
        {
            last = mid - 1;
        }
        else
        {
            printf("the index of given number \"%d\" is:%d ", num, mid);
            break;
        }
    }
    if (first > last)
    {
        printf("given number is not in array!");
    }
}

void display(Array *array)
{
    printf("the array is:-\n");
    for (size_t i = 0; i < array->used_size; i++)
    {
        if (i == (array->used_size) - 1)
        {
            printf("%d\n", (array->arr_ptr)[i]);
        }
        else
        {
            printf("%d, ", (array->arr_ptr)[i]);
        }
    }
}

int main()
{
    Array array;
    int msize = 100, usize = 60, num;
    create(&array, msize, usize);
    random_array(&array);

    display(&array);
    sort(&array);
    display(&array);

    printf("enter the number u want to find the index of:-");
    scanf("%d", &num);
    binary_search(array, num);

    free(array.arr_ptr);
    return 0;
}