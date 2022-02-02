#include <iostream>

double compute(int x, int y);
double compute(int x);

int main()
{
	std::cout << compute(15, 7) << "\n";
	
	std::cout << compute(10) << "\n";
	
	return 0;
}

double compute(int x, int y)
{
	double answer(0);
	
	answer = x + y;
	
	return answer;
}

double compute(int x)
{
	double answer(0);
	
	answer = x * 5;
	
	return answer;
}