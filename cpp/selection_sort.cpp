#include <iostream>

int main() {

	int array[5];
	int i, j, menor, pos, eleito;

	for(i = 0; i < 5; i++)
	{
		std::cout << "Type the " << (i+1) << "° element: ";
		std::cin >> array[i];
	}

	//sort
	for(i = 0; i < 4; i++)
	{
		eleito = array[i];

		menor = array[i + 1];
		pos = i+1;

		for(j=i+1; j < 5; j++)
		{
			if(array[j] < menor)
			{
				menor = array[j];
				pos = j;
			}
		}

		if(menor < eleito)
		{
			array[i] = array[pos];
			array[pos] = eleito;
		}
	}

	//print
	for(i = 0; i < 5; i++)
	{
		std::cout << (i+1) << "° element: " << array[i] << std::endl;
	}

	return 0;
}
