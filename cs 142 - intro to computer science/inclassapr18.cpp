#include <iostream>

int factorial(int num);

int main()
{		
	int value(0);
	std::cout << "enter a number: ";
	std::cin >> value;
	
	std::cout << value << "! = " << factorial(value) << "\n";
	
	return 0;
}

int factorial(int num)
{
	int result(0);
	
	if(num <= 1)
	{
		return 1;
	}
	
	else
	{
		return num * factorial(num - 1);
	}
}