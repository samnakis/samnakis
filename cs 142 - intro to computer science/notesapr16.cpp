#include <iostream>

int main()
{
	int * ptrMyFirstPointer;
	
	int x(0);
	
	x = 15;
	
	ptrMyFirstPointer = &x;
	
	std::cout << *ptrMyFirstPointer << "\n";
	
	int myArray[5] = { 15, 10, 7, 10, 7 };
	
	int * ptrArray = myArray;
	
	std::cout << *ptrArray << "\n";
		
	std::cout << *ptrArray++ << "\n";
		
		
	return 0;
}