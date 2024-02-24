#include <stdio.h>

void troca(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void heapify(int arr[], int size, int i)
{
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int maior = i;

    if(esq < size && arr[esq] > arr[maior])
        maior = esq;
    
    if(dir < size && arr[dir] > arr[maior])
        maior = dir;

    if(maior != i)
    {
        troca(&arr[i], &arr[maior]);
        heapify(arr, size, maior);
    }   
}

void transforma_heap(int arr[], int size)
{
    for(int i = (size/2) - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

void heapsort(int arr[], int size) {

    transforma_heap(arr, size);
    
    for(int i = size - 1; i >= 1; i--)
    {
        troca(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    putchar('\n');
}

int main() {

    int arr[] = {1, 5, 4, 2, 9, 3, -1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    heapsort(arr, size);
    printArray(arr, size);

    return 0;
}