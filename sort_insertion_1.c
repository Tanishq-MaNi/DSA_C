#include <stdio.h>
int main()
{
    int arr[10]={2458,124,655,245,854,25,235,4571,521,325},temp;

    for (int i = 0; i < 9; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;

            if (i > 0)
            {
                for (int j = i; j > 0; j--)
                {
                    if (arr[j] < arr[j - 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j - 1];
                        arr[j - 1] = temp;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", arr[i]);
    }
}