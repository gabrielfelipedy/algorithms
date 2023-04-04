#include <iostream>

int main()
{
	int array[5];
	int i, j, eleito;

	for(i = 0; i < 5; i++)
	{
		std::cout << "Type the " << (i+1) << "° number: ";
		std::cin >> array[i];
	}	

	//sort
	for(i = 1; i < 5; i++)
	{
		eleito = array[i];
		j = i - 1;
		while(j >=0 && array[j] > eleito)
		{
			array[j+1] = array[j];
			j--;
		}

		array[j+1] = eleito;
	}

	//print
	for(i = 0; i < 5; i++)
	{
		std::cout << (i+1) << "° Element: " << array[i] << std::endl;
	}

	return 0;
}
