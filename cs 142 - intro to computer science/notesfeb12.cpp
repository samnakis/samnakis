#include <iostream>

int main()
{
	int count(0);
	
	std::cout << "Please enter a number: ";
	std::cin >> count;
	
	while(count > 0 && count < 1000)
	{
		std::cout << count << "\n";
		count = count - 1;
	}
	
	std::cout << "blast off!!" << "\n";
	
	return 0;
}