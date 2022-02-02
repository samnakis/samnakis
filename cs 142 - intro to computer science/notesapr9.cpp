#include <iostream>

int main()
{
	int myArray[100];
	
	for(int i=0; i <= 100; i++)
	{
		myArray[i] = i;
	}
	
	int count = 0;
	
	while (count <= 100)
	{
		std::cout << myArray[count] << "\n";
		count ++;
	}
	
	return 0;
}