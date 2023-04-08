#include <iostream>
#include <cstring>
#include <stdbool.h>

void printProduct(std::string produto[]) {

		std::cout << "Nome: " << produto[0] << std::endl;
		std::cout << "Codigo: " << produto[1] << std::endl;
		std::cout << "Preco: " << produto[2] << std::endl;

}

int main() {

	const int QTDE = 3;
		
	std::string produtos[QTDE][3], eleito[3];
	int i, j;
	for(i=0; i < QTDE; i++) {

		std::cout << "Nome: ";
		std::cin >> produtos[i][0];
		std::cout << "Codigo: ";
		std::cin >> produtos[i][1];
		std::cout << "Preco: ";
		std::cin >> produtos[i][2];
	}	

	for(i=1;i<QTDE;i++)
	{
		std::copy(produtos[i], produtos[i] + 3, eleito);
		j = i-1;
		while(j>=0 && stoi(produtos[j][1]) > stoi(eleito[1])) {
			std::copy(produtos[j], produtos[j] + 3, produtos[j+1]);
			j--;
		}

		std::copy(eleito, eleito+3, produtos[j+1]);
	}


	//print
	std::cout << "\n===PRODUCT INFO===\n" << std::endl;
	for(i=0;i<QTDE; i++)
		printProduct(produtos[i]);

	//search
	int codigo;
	std::cout << "\nDigite o código do produto a ser buscado: ";
	std::cin >> codigo;

	int inicio = 0;
	int fim = QTDE - 1;
	int meio = (inicio+fim) / 2;

	bool achou = false;
	while(inicio <= fim && !achou)
	{
		if(stoi(produtos[meio][1]) == codigo) achou = true;
		else {
			if(codigo < stoi(produtos[meio][1]))
			{
				fim = meio - 1;
			} else
				inicio = meio + 1;

			meio = (inicio+fim)/2;
		}
	}

	if(achou) {
		std::cout << "\nProduct found: \n" << std::endl;
		printProduct(produtos[meio]);
	} else {
		std::cout << "\nProduct not found\n";
	}
	
	return 0;
}
