#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>

int main() {

	std::string array[2][5], auxn, auxs;
	int i, j;

	for(i=0; i<5; i++) {

		std::cout << "Type de name of the "<<(i+1)<<"° empregated: ";
		std::cin >> array[0][i];
		std::cout << "Type the salary of the "<<(i+1)<<"° empregated: ";
		std::cin >> array[1][i];
	}

	//sort
	for(i=0;i<5;i++) {
		for(j=0;j<4;j++) {

			int s1 = stoi(array[1][j]);
			int s2 = stoi(array[1][j+1]);

			if(s1 > s2) {
				
				auxn = array[0][j];
				auxs = array[1][j];

				array[0][j] = array[0][j+1];
				array[0][j+1] = auxn;

				array[1][j] = array[1][j+1];
				array[1][j+1] = auxs;
			}
		}
	}

	std::cout << "\n===CLIENT INFO===\n" << std::endl;

	for(i=0; i<5; i++) {

		std::cout << "Name: "<< array[0][i] << std::endl;
		std::cout << "Salary: R$ "<< array[1][i] << std::endl;
	}

	return 0;
}
