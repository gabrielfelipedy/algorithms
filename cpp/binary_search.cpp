#include <iostream>
#include <stdbool.h>

#define ARRAY_LENGTH 1000000

int main() {

	int array[ARRAY_LENGTH], i, n, inicio, meio, fim;
	bool achou;

	//load the vector numbers:
	for(i=0; i<ARRAY_LENGTH; i++)
	{
		array[i] = i+1;
	}

	std::cout << "Type the number to look for: ";
	std::cin >> n;

	achou = false;
	inicio = 0;
	fim = ARRAY_LENGTH - 1;
	meio = (inicio+fim)/2;

	while(inicio <= fim && !achou) {

		if(array[meio] == n)
			achou = true;
		else {
			if(n < array[meio]) fim = meio - 1;
			else inicio = meio + 1;
			meio = (inicio+fim)/2;
		}
	}

	if(achou) std::cout << "Number found at position " << meio + 1 << std::endl;
	else std::cout << "Number not found" << std::endl;

	return 0;
}
