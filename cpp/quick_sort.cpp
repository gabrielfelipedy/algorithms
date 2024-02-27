#include <iostream>

void troca(int array[], int i, int j)
{
	int aux = array[i];
	array[i] = array[j];
	array[j] = aux;
}

int particao(int array[], int p, int r) {

	int pivo = array[(p+r)/2];
	
	int i = p - 1;
	int j = r + 1;

	while(i < j) {
		do {

			j--;

		} while(array[j] > pivo);
		do {

			i++;

		} while(array[i] < pivo);
		
		if(i < j) troca(array, i, j);
	}

	return j;
}

void quick_sort(int array[], int p, int r) {

	int q;
	if(p < r) {
		q = particao(array, p, r);
		quick_sort(array, p, q);
		quick_sort(array, q+1, r);
	}
}

int main() {

	int array[10] = {1, 4, 2, 6, 4, 8, 9, 10, -1, 42};

	for(int i=0; i < 10; i++)
	{
		std::cout <<(1+i)<<"° element: "<<array[i]<<std::endl;
	}

	quick_sort(array, 0, 9);

	//print
	for(int i=0; i < 10; i++)
	{
		std::cout <<(1+i)<<"° element: "<<array[i]<<std::endl;
	}
}
