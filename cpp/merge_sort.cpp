#include <iostream>

void intercala(int array[], int inicio, int fim, int meio)
{
	int poslivre, inicio_v1, inicio_v2, aux[10], i;

	inicio_v1 = inicio;
	inicio_v2 = meio + 1;
	poslivre = inicio;

	while(inicio_v1 <= meio && inicio_v2 <= fim)
	{
		if(array[inicio_v1] <= array[inicio_v2]) {
			aux[poslivre] = array[inicio_v1];
			inicio_v1++;
		} else {
			aux[poslivre] = array[inicio_v2];
			inicio_v2++;
		}

		poslivre++;
	}

	//se nem todos os elementos foram intercalados em v1
	for(i = inicio_v1; i <= meio; i++)
	{
		aux[poslivre] = array[i];
		poslivre++;
	}

	//o mesmo acima para v2
	for(i = inicio_v2; i <= fim; i++)
	{
		aux[poslivre] = array[i];
		poslivre++;
	}

	//aux --> array
	for(i = inicio; i <= fim; i++)
	{
		array[i] = aux[i];
	}
}
void merge(int array[], int inicio, int fim)
{
	int meio;
	if(inicio < fim) {

		meio = (inicio + fim) / 2;
		merge(array, inicio, meio);
		merge(array, meio+1, fim);
		intercala(array, inicio, fim, meio);
	}
}

int main() {

	int array[10], i;

	for(i = 0; i < 10; i++)
	{
		std::cout << "Type the "<< (i+1) << "° number: ";
		std::cin >> array[i];
	}

	merge(array, 0, 9);

	//printing
	for(i = 0; i < 10; i++){
		std::cout << (i+1) <<"° number: " << array[i] << std::endl;
	}

	return 0;
}
