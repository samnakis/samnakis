#include <iostream>

void getInput(int& intValue, double& doubleValue);

int main()
{
	int x(0);
	double y(0);
	
	getInput(x, y);
	
	std::cout << "X: " << x << "\n";
	std::cout << "Y: " << y << "\n";
	
	return 0;
}

void getInput(int& intValue, double& doubleValue)
{
	std::cout << "Please enter an integer value: ";
	std::cin >> intValue;
	
	std::cout << "Please enter a double value: ";
	std::cin >> doubleValue;
}