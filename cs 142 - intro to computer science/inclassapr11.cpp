#include <iostream>

void sort(int myArray[], int size);

int main()
{
	int myArray[5] = {15, 10, 7, 75, 10};
	
	sort(myArray, 5);
	
	std::cout << myArray << "\n";
	
	return 0;
}

void sort(int myArray[], int size)
{
	for(int i=0; i < size; i++)
	{
		if(myArray[i] > myArray[i+1])
		{
			int temp(0);
			temp = myArray[i];
			myArray[i] = myArray[i+1];
			myArray[i+1] = temp;
		}
	}
}