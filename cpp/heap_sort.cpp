#include <iostream>

void troca(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void heap_fica(int array[], int i, int tam)
{
	int esq = 2*i + 1;
	int dir = 2*i + 2;
	int maior = i;

	if(esq < tam && array[esq] > array[maior])
		maior = esq;

	if(dir < tam && array[dir] > array[maior])
		maior = dir;

	if (maior != i) {
		troca(&array[i], &array[maior]);
		heap_fica(array, maior, tam);
	}
}

void transforma_heap(int array[], int qtde) {
	for(int i = (qtde/2) - 1; i >= 0; i--) {
		heap_fica(array, i, qtde);
	}
}

void heapsort(int array[], int qtde) {

	transforma_heap(array, qtde);

	for(int i = qtde-1; i >= 1; i--)
	{
		troca(&array[0], &array[i]);
		heap_fica(array, 0, i);
	}
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    putchar('\n');
}

int main() {

	int arr[] = {1, 5, 4, 2, 5, 3, 3, 7};
    int size = (sizeof(arr) / sizeof(arr[0]));

    printArray(arr, size);

    heapsort(arr, size);
    printArray(arr, size);
}
