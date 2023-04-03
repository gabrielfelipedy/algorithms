#include <iostream>

int main()
{
	int array[5], i, n, aux;

	//Getting data into the array

	for(i = 0; i < 5; i++)
	{
		std::cout << "Digite o " << (i+1) << "° número: ";
		std::cin >> array[i];
	}

	//sorting
	
	for(n = 1; n <= 5; n++)
	{
		for(i = 0; i < 4; i++)
		{
			if(array[i] > array[i+1])
			{
			aux = array[i];
			array[i] = array[i+1];
			array[i+1] = aux;
			}
		}
	}

	//print
	for(i = 0; i < 5; i++)
	{
		std::cout << (i+1) << "° Element: " << array[i] << std::endl;
	}

	return 0;
}
