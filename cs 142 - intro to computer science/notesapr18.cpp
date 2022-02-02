#include <iostream>

int main()
{
	int * ptrMyPointer;
	
	int x(0);
	x = 12;
		
	std::cout << *ptrMyPointer << "\n";
	std::cout << &ptrMyPointer << "\n";
	
	/*int * ptrArray = myArray;
	
	std::cout << *ptrArray << "\n";
	
	int size(0);
	
	size = myArray.length;
	
	std::cout << size << "\n" 
	
	for(int i=0; i <= 5, i++);
	{
		int temp(0);
		temp++;
		
		*(ptrArray++) = temp;
		
		std::cout << *(ptrArray++) << "\n";
	}
	*/

	return 0;
}