#include <iostream>

int main()
{
	int array[5];
	
	for(int x=0; x < 5; x++)
	{
		std::cout << "Please enter an integer: ";
		std::cin >> array[x];
	}
	
	int count = 0;
	
	while (count < 5)
	{
		std::cout << array[count] << "\n";
		count ++;
	}
	
	return 0;
}