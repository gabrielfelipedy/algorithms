#include <iostream>
#include <stdbool.h>

int main() {

	int array[10], i, n; 	
	bool achou;

	for(i=0;i<10;i++)
	{
		array[i] = i+1;
	}

	std::cout << "\nType the number to look for: ";
	std::cin >> n;

	i=0;
	achou = false;
	while(!achou && i < 10 && array[i] <= n) {

		if(array[i] == n)
			achou = true;
		else
			i++;
	}

	if(achou)
		std::cout << "Number founded at position " << (i+1) << std::endl;
	else
		std::cout << "Number not found" << std::endl;

	return 0;
}
