#include <stdio.h>
#include <stdlib.h>

typedef struct myarray
{
    int total_size;
    int used_size;
    int *arr_ptr;
} myarray;

void memory_allocation(myarray *array, int tsize, int usize)
{
    array->total_size = tsize;
    array->used_size = usize;
    array->arr_ptr = (int *)malloc(tsize * (sizeof(int)));
}

void array_val(myarray *array)
{

    for (int i = 0; i < array->used_size; i++)
    {
        scanf("%d", &(array->arr_ptr)[i]);
        printf("\n");
    }
}

int insertion(myarray *array, int index, int num)
{
    if (array->total_size == array->used_size || index >= array->total_size)
    {
        return -1;
    }
    else if (index > (array->used_size) - 1)
    {
        printf("a\n");
        (array->arr_ptr)[array->used_size] = num;
        (array->used_size)++;
        return 1;
    }
    else
    {
        for (int i = array->used_size; i > index; i--)
        {
            (array->arr_ptr)[i] = (array->arr_ptr)[i - 1];
        }
        (array->arr_ptr)[index] = num;
        (array->used_size)++;
        return 1;
    }
}

int deletion(myarray *array, int index)
{
    if (index > array->used_size)
    {
        return -1;
    }
    for (int i = index; i < array->used_size - 1; i++)
    {
        (array->arr_ptr)[i] = (array->arr_ptr)[i + 1];
    }
    (array->used_size)--;
    return 1;
}

void display(myarray *array)
{
    for (int i = 0; i < array->used_size; i++)
    {
        printf("%d, ", (array->arr_ptr)[i]);
    }
}

int main()
{
    myarray array;
    int tsize, usize;

    printf("enter the total size of array:");
    scanf("%d", &tsize);
    printf("enter the used size of array:");
    scanf("%d", &usize);
    memory_allocation(&array, tsize, usize);

    printf("enter the values of array:\n");
    array_val(&array);

    insertion(&array, 0, 45);

    deletion(&array, 3);
    
    printf("display of entered array:\n");
    display(&array);
    free(array.arr_ptr);
    return 0;
}