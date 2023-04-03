#include <iostream>

int main()
{
	int array[5], i, n, aux, troca;

	//Getting data into the array

	for(i = 0; i < 5; i++)
	{
		std::cout << "Digite o " << (i+1) << "° número: ";
		std::cin >> array[i];
	}

	//sorting
	n = 1;
	troca = 1;

	while(n <= 5 && troca == 1)
	{
		troca = 0;
		for(i = 0; i < 4; i++)
		{
			if(array[i] < array[i+1])
			{
			troca = 1;
			aux = array[i];
			array[i] = array[i+1];
			array[i+1] = aux;
			}
		}
		n++;
	}

	//print
	for(i = 0; i < 5; i++)
	{
		std::cout << (i+1) << "° Element: " << array[i] << std::endl;
	}

	return 0;
}
