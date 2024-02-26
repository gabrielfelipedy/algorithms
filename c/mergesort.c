#include <stdio.h>

void merge(int arr[], int begin, int mid, int end)
{
    int tam1 = mid - begin + 1;
    int tam2 = end - mid;
    
    int temp1[tam1];
    int temp2[tam2];
    
    for(int i = 0; i < tam1; i++)
        temp1[i] = arr[begin + i];
    
    for(int j = 0; j < tam2; j++)
        temp2[j] = arr[mid + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = begin;
    
    while(i < tam1 && j < tam2)
    {
        if(temp1[i] <= temp2[j])
        {
            arr[k++] = temp1[i++];
        }
        else
        {
            arr[k++] = temp2[j++];
        }
    }
    
    while(i < tam1)
        arr[k++] = temp1[i++];
    
    while(i < tam2)
        arr[k++] = temp2[j++];
}

void mergesort(int arr[], int begin, int end)
{
    if(begin >= end) return;
    
    int mid = (begin + end) / 2;
    
    mergesort(arr, begin, mid);
    mergesort(arr, mid + 1, end);
  
    merge(arr, begin, mid, end);
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    putchar('\n');
}

int main()
{
    int arr[] = {2, 1, 0, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printArray(arr, size);
    
    mergesort(arr, 0, size-1);
    
    printArray(arr, size);

    return 0;
}
