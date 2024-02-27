#include <stdio.h>

void troca(int* a, int* b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int partition(int arr[], int begin, int end)
{
	int pivot = (begin + end) / 2;

	int maior_esquerda = begin;
	int menor_direita = end;

	while(maior_esquerda < menor_direita)
	{
		while(arr[maior_esquerda] < arr[pivot])
			maior_esquerda++;

		while(arr[menor_direita] > arr[pivot])
			menor_direita--;

		if(maior_esquerda < menor_direita)
		{
			troca(&arr[maior_esquerda], &arr[menor_direita]);

			maior_esquerda++;
			menor_direita--;
		}
	}

	return pivot;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quicksort(arr, left, pivotIndex);
        quicksort(arr, pivotIndex + 1, right);
    }
}

void print_array(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	putchar('\n');
}


int main() {

	int vet[] = { 2, 5, 3, 1, 4 };
	int size = sizeof(vet) / sizeof(vet[0]);

	print_array(vet, size);
	quicksort(vet, 0, size - 1);
	print_array(vet, size);

	return 0;
}