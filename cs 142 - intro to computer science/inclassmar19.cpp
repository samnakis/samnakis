#include <iostream>

int area(int x, int y);

int main()
{
	int height(0);
	int base(0);
	double triangle(0);
	
	std::cout << "Please enter the height: ";
	std::cin >> height;
	
	std::cout << "Please enter the base: ";
	std::cin >> base;
	
	triangle = area(height, base);
	
	std::cout << "The area is " << triangle << "\n";
	
	
	return 0;
}

int area(int x, int y)
{
	return x * y * 0.5;
}