#include <iostream>
#include <string.h>
#include <stdlib.h>

int main() {

	std::string array[2][5];
	int i, j, eleito, menor, pos;

	for(i=0; i<5; i++) {

                std::cout << "Type de name of the "<<(i+1)<<"° empregated: ";                                                                   std::cin >> array[0][i];
                std::cout << "Type the salary of the "<<(i+1)<<"° empregated: ";                                                                std::cin >> array[1][i];                                }

	//sort
	for(i=0;i<4;i++) {

	try {
		eleito = stoi(array[1][i]);
		pos = i+1;
		menor = stoi(array[1][pos]);

		std::string seleito = array[1][i];
		std::string neleito = array[0][i];

		for(j = i+2; j < 5; j++)
		{
			if(stoi(array[1][j]) < menor)
			{
				menor = stoi(array[1][j]);
				pos = j;
			}

			if(menor < eleito) {

				array[1][i] = array[1][pos];
				array[0][i] = array[0][pos];

				array[0][pos] = neleito;
				array[1][pos] = seleito;
			}
		}
	
	} catch(std::invalid_argument a) {

		std::cout << "Error " << std::endl;
	}
	}

	std::cout << "\n===CLIENT INFO===\n" << std::endl;                                                                              for(i=0; i<5; i++) {
                                                                                std::cout << "Name: "<< array[0][i] << std::endl;                                                                               std::cout << "Salary: R$ "<< array[1][i] << std::endl;
        }

	return 0;
}
