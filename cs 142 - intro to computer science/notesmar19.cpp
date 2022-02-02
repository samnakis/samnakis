#include <iostream>

int addOne(int num);

int main()
{
	int number(0);
	int result(0);
	
	std::cin >> number;
	
	result = addOne(number);
	
	addOne(number);
	
	std::cout << result << "\n";
	std::cout << number << "\n";
	
	return 0;
}

int addOne(int num)
{
	num = num + 1;
	
	return num++;
	
	//return num;
}