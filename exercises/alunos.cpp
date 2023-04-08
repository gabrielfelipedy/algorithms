#include <iostream>	
#include <cstring>

const int NOME = 0;
const int NOTA1 = 1;
const int NOTA2 = 2;

double calculaMedia(std::string nota1, std::string nota2)
{
	return (stoi(nota1) * 2 + stoi(nota2) * 3) / (2.0 + 3.0);
}

void printAluno(std::string aluno[]) {

	double media = calculaMedia(aluno[NOTA1], aluno[NOTA2]);

	std::cout << "\nNome: " << aluno[NOME] << std::endl;
	std::cout << "Nota 2: " << aluno[NOTA1] << std::endl;
	std::cout << "Nota 1: " << aluno[NOTA2] << std::endl;
	std::cout << "Media: " << media << std::endl;
}

int main() {

	const int QTDE = 3;

	std::string alunos[QTDE][3];
	int i, j;

	for(i=0; i < QTDE; i++)
	{
		std::cout << "\nNome: ";
		std::cin >> alunos[i][NOME];
		std::cout << "Nota 1: ";
		std::cin >> alunos[i][NOTA1];
		std::cout << "Nota 2: ";
		std::cin >> alunos[i][NOTA2];
	}

	//sort
	for(i=0; i < QTDE; i++) {

		for(j=0; j < QTDE - 1; j++) {

			if(calculaMedia(alunos[j][NOTA1], alunos[j][NOTA2]) > calculaMedia(alunos[j+1][NOTA1], alunos[j+1][NOTA2])) {

				std::string aux[3];
				std::copy(alunos[j], alunos[j] + 3, aux);
				std::copy(alunos[j+1], alunos[j+1]+3, alunos[j]);
				std::copy(aux, aux+3, alunos[j+1]);
					}
		}
	}
	
	//print
	std::cout << "\n===CLASS INFO===\n";
	for(i=0; i < QTDE; i++)
		printAluno(alunos[i]);

	return 0;
}
