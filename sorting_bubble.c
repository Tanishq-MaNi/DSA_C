#include<stdio.h>
int main(){
    int arr[100]={69, 17, 15, 7, 33, 5, 78, 66, 25, 9, 15, 93, 85, 14, 55, 94, 99, 90, 26, 75, 37, 9, 33, 40, 77, 10, 40, 44, 67, 6, 59, 78, 14, 96, 26, 98, 77, 81, 92, 36, 87, 44, 52, 87, 12, 44, 87, 90, 27, 36, 85, 55, 76, 68, 72, 17, 71, 23, 97, 96, 34, 84, 64, 2, 14, 21, 90, 92, 65, 72, 33, 53, 82, 3, 40, 66, 14, 75, 76, 39, 13, 45, 34, 1, 8, 22, 41, 93, 26, 39, 39, 28, 64, 67, 63, 35, 85, 3, 41, 97},temp;
    for (int  i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100-i-1; j++)
        {
         if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
         }   
        }
        
    }
    for (int i = 0; i < 100; i++)
    {
        printf("%d, ",arr[i]);
    }
}