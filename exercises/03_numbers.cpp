#include <iostream>

const int QTDE = 5;

void print(int num[]) {

	std::cout << "\n===SHOW===\n" << std::endl;

	for(int i = 0; i < QTDE; i++)
	{
		std::cout << num[i] << std::endl;
	}
}

void ordena(int num[]) {

	int i, j, menor, pos, eleito;
	for(i=0;i<QTDE-1;i++)
	{
		eleito = num[i];
		pos = i+1;
		menor = num[pos];

		for(j=i+2; j < QTDE; j++)
		{
			if(num[j] < menor)
			{
				menor = num[j];
				pos = j;
			}
		}

		if(menor < eleito)
		{
			num[i] = num[pos];
			num[pos] = eleito;
		}
	}
}

int search(int np, int num[])
{
	int i, inicio, fim, meio;

	inicio = 0;
	fim = QTDE - 1;
	meio = (inicio + fim) / 2;

	while(inicio <= fim)
	{
		if(num[meio] == np) return meio;
		else{
			if(num[meio] > np)
				fim = meio - 1;
			else
				inicio = meio + 1;

			meio = (inicio + fim) / 2;
		}
	}
	return 0;
}

int main() {

	int num[QTDE];		

	for(int i=0; i < QTDE; i++)
	{
		std::cout << "Type a number: ";
		std::cin >> num[i];
	}

	ordena(num);
	print(num);

	int np;
	std::cout << "\nType a number to look for: ";
	std::cin >> np;

	int achou = search(np, num);
	if(achou)
		std::cout << "Number found at position " << achou+1 << std::endl;
	else
		std::cout << "404 not found" << std::endl;

	return 0;
}
