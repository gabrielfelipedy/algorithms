#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getmax(int arr[], int size)
{
    int maximo = arr[0];
    
    for(int i = 0; i < size; i++)
    {
        if(arr[i] > maximo) maximo = arr[i];
    }
    
    return maximo;
}

void counting_sort(int arr[], int size, int exp)
{
    int output[size];
    
    int* count = (int*)calloc(10, sizeof(int));
    
    for(int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    
    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    
    for(int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10]-- - 1] = arr[i];
    }
    
    for(int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int size)
{
    int max = getmax(arr, size);
    
    for(int exp = 1; (max/exp) > 0; exp *= 10)
        counting_sort(arr, size, exp);
}

void print_array(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
        
    putchar('\n');
}

int main()
{
    int array[] = {0, 4, 2, 5, 6, 9, 81, 34, 42, 1, 191};
    int size = sizeof(array) / sizeof(array[0]);
    
    print_array(array, size);
    
    radixsort(array, size);
    print_array(array, size);
    
    return 0;
}
