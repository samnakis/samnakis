#include <iostream>

//function declaration
double calculateArea (int width, double length);

int main()
{
	int w(0);
	double l(0), total(0);
	
	std::cout << "Please enter a length: ";
	std::cin >> l;
	std::cout << "\n";
	
	std::cout << "Please enter a width: ";
	std::cin >> w;
	std::cout << "\n";
	
	//function call
	total = calculateArea (w, l);
	
	std::cout << "Your total is " << total << "\n";
	
	return 0;
}

//function definition (header/body)
double calculateArea (int width, double length)
{
	double area(0);
	
	area = length * width;
	
	return area;
}