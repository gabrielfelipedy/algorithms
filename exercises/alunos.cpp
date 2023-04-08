#include <iostream>	
#include <cstring>

const int NOME = 0;
const int NOTA1 = 1;
const int NOTA2 = 2;

void printAluno(std::string aluno[]) {

	std::cout << "Nome: " << aluno[NOME] << std::endl;
	std::cout << "Nota 2: " << aluno[NOTA1] << std::endl;
	std::cout << "Nota 1: " << aluno[NOTA2] << std::endl;
}

int main() {

	const int QTDE = 3;

	std::string alunos[QTDE][3];
	int i;

	for(i=0; i < QTDE; i++)
	{
		std::cout << "Nome: ";
		std::cin >> alunos[i][NOME];
		std::cout << "Nota 1: ";
		std::cin >> alunos[i][NOTA1];
		std::cout << "Nota 2: ";
		std::cin >> alunos[i][NOTA2];
	}

	for(i=0; i < QTDE; i++)
		printAluno(alunos[i]);

	return 0;
}
