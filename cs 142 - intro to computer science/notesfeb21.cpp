#include <iostream>

int main()
{
	/*
	int number = 10;
	int value = 2 * (number++);
	std::cout << value << "\n";
	std::cout << number << "\n";
	*/
	//prints 11 and 20

	int number = 10;
	int value = 2 * (++number);
	std::cout << value << "\n";
	std::cout << number << "\n";
	//prints out 11 and 22

	return 0;
}