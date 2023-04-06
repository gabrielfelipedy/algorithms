#include <iostream>
#include <string.h>
#include <stdlib.h>

int main() {

	std::string array[2][5];
	int i, j;

	for(i=0; i<5; i++) {

                std::cout << "Type de name of the "<<(i+1)<<"° empregated: ";                                                                   std::cin >> array[0][i];
                std::cout << "Type the salary of the "<<(i+1)<<"° empregated: ";                                                                std::cin >> array[1][i];                                }

	for(i=1;i<5;i++) {

	try {
		int eleito = stoi(array[1][i]);

		std::string seleito = array[1][i];
		std::string neleito = array[0][i];
		j = i-1;
		
		while(j >= 0 && stoi(array[1][j]) > eleito)
		{
			array[1][j+1] = array[1][j];
			array[0][j+1] = array[0][j];
			j--;
		}

		array[1][j+1] = seleito;
		array[0][j+1] = neleito;
	
	} catch(std::invalid_argument a) {

		std::cout << "Error " << std::endl;
	}
	}

	std::cout << "\n===CLIENT INFO===\n" << std::endl;                                                                              for(i=0; i<5; i++) {
                                                                                std::cout << "Name: "<< array[0][i] << std::endl;                                                                               std::cout << "Salary: R$ "<< array[1][i] << std::endl;
        }

	return 0;
}
