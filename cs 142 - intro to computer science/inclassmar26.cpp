#include <iostream>

void swap(int& value1, int& value2);

int main()
{
	int x(0);
	int y(0);
	
	std::cout << "enter an integer: ";
	std::cin >> x;
	
	std::cout << "\n" << "enter another integer: ";
	std::cin >> y;
	
	std::cout << "pre-swap" << "\n";
	std::cout << "x: " << x << "\n";
	std::cout << "y: " << y << "\n" << "\n";
	
	swap (x, y);
	
	std::cout << "post-swap" << "\n";
	std::cout << "x: " << x << "\n";
	std::cout << "y: " << y << "\n";
	
	return 0;
}

void swap(int& value1, int& value2)
{
	int change(0);
	
	change = value1;
	value1 = value2;
	value2 = change;
}