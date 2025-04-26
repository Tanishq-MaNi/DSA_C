#include <stdio.h>
int binary_search(int *arr, int num, int length)
{
    int min = 0, max = length - 1, mid;

    while (min <= max)
    {
        mid = min + (max - min) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        // else if (arr[min] == num)
        // {
        //     return min;
        // }
        // else if (arr[max] == num)
        // {
        //     return max;
        // }
        else if (arr[mid] < num)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int length = sizeof(arr) / sizeof(arr[0]);
    int num;

    printf("Enter a number to search: ");
    scanf("%d", &num);

    int result = binary_search(arr, num, length);

    if (result != -1) {
        printf("Number %d found at index %d.\n", num, result);
    } else {
        printf("Number %d not found in the array.\n", num);
    }

    return 0;
}