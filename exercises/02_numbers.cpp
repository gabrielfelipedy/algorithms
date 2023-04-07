#include <iostream>
#include <cstring>
#include <stdbool.h>

int main() {

	int numbers[10], i, j;
	int lenth = 10;

	for(i=0;i<lenth; i++) {

		std::cout << "Type the " <<(i+1)<<"° number: ";
		std::cin >> numbers[i];
	}

	//sort
	bool troca = true;
	i = 1;
	int maior = numbers[0];
	int menor = numbers[0];
	int vm = 0;
	int vM = 0;

	while(i <= lenth && troca) {
		troca = false;

		if(numbers[i-1] == maior) vM++;
                if(numbers[i-1] == menor) vm++;

		if(numbers[i-1] > maior) {
                        maior = numbers[i-1];
                        vM = 1;

		} 
		if(numbers[i-1] < menor) {
                        menor = numbers[i-1];
                        vm = 1;

                } 

		for(j=0;j<lenth-1;j++) {

			if(numbers[j] > numbers[j+1]) {
				int aux = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = aux;
				troca = true;
			}
		}

		i++;
	}
		
	//print
	std::cout << "\n===CLIENT INFO===\n" << std::endl;
	for(i=0; i<lenth; i++) {

		std::cout <<(i+1)<<"° number: " <<numbers[i] << std::endl;
	}

	std::cout << "O maior número do vetor é " << numbers[lenth-1] << " que aparece " << vM << " vezes" << std::endl;

	std::cout << "O menor número do vetor é " << numbers[0] << " que aparece " << vm << " vezes" << std::endl;
	return 0;
}
