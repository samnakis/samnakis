#include <iostream>

int main()
{
	int * myArray = new int[4];
	
	*myArray = 15;
	
	std::cout << *myArray << "\n";
	
	//gets rid of memory leaks
	delete myArray;
	
	return 0;
}