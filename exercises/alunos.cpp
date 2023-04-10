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
	std::cout << "Nota 1: " << aluno[NOTA1] << std::endl;
	std::cout << "Nota 2: " << aluno[NOTA2] << std::endl;
	std::cout << "Media: " << media << std::endl;
}

void printReprovados(std::string alunos[3][3])
{
	int i, j;
	for(i=0;i<3;i++) {
                for(j=0;j<2;j++) {

                        int index = 0;
                        while(true) {

                        int s1 = tolower(alunos[j][NOME].at(index));
                        int s2 = tolower(alunos[j+1][NOME].at(index));

                        if(s1 > s2) {

                                std::string aux[3];
				std::copy(alunos[j], alunos[j]+3, aux);

				std::copy(alunos[j+1], alunos[j+1]+3, alunos[j]);
				std::copy(aux, aux+3, alunos[j+1]);

                                break;

                        } else if(s1 == s2) {

                                index++;
                                continue;
                        } else
                                break;
                        }
                }
        }	

	std::cout << "\n===REPROVED===\n";
	j = 0;
	while(j < 3)
	{
		if(calculaMedia(alunos[j][NOTA1], alunos[j][NOTA2])< 7)
		{
			printAluno(alunos[j]);
		}
		j++;
	}
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
	std::cout << "\n===MEDIA ORDENATION===\n";
	for(i=0; i < QTDE; i++)
		printAluno(alunos[i]);

	//sort
	for(i=0; i < QTDE; i++) {

		for(j=0; j < QTDE - 1; j++) {

			if(stoi(alunos[j][NOTA1]) > stoi(alunos[j+1][NOTA1])) {

				std::string aux[3];
				std::copy(alunos[j], alunos[j] + 3, aux);
				std::copy(alunos[j+1], alunos[j+1]+3, alunos[j]);
				std::copy(aux, aux+3, alunos[j+1]);
					}
		}
	}

	//print
	std::cout << "\n===1st NOTE ORDENATION===\n";
	for(i=0; i < QTDE; i++)
		printAluno(alunos[i]);

	//print reproved
	printReprovados(alunos);

	return 0;
}
