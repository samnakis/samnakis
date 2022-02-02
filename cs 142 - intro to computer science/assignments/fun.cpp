#include <iostream>

//function declarations
void getInput(double& x, double& y);

double calculateAddition(double x, double y);
double calculateSubtraction(double x, double y);
double calculateMultiplication(double x, double y);
double calculateDivision(double x, double y);
int calculateModulus(int x, int y);

int main()
{
	//print out welcome message
	std::cout << "Welcome to Sam's Calculator!" << "\n" << "\n";
	
	//declaring variables
	double x(0);
	double y(0);
	double answer(0);
	int choice(0);
	
	//do while loop with the options for the calculator
	do
	{
		std::cout << "1. 	Addition (x+y)" << "\n";
		std::cout << "2. 	Subtraction (x-y)" << "\n";
		std::cout << "3. 	Multiplication (x*y)" << "\n";
		std::cout << "4. 	Division (x/y)" << "\n";
		std::cout << "5. 	Modulus (x%y)" << "\n";
		std::cout << "6. 	Quit Program" << "\n" << "\n";
	
		std::cout << "Please enter your choice: ";
		std::cin >> choice;
		std::cout << "\n";
		
		//if, else if, and else statements for each calculator option
		if(choice == 1)
		{
			getInput(x, y);
			answer = calculateAddition(x, y);
		} 
	
		else if(choice == 2)
		{
			getInput(x, y);
			answer = calculateSubtraction(x, y);
		}
	
		else if(choice == 3)
		{
			getInput(x, y);
			answer = calculateMultiplication(x, y);
		}
	
		else if(choice == 4)
		{
			getInput(x, y);
			answer = calculateDivision(x, y);
		}
	
		else if(choice == 5)
		{
			getInput(x, y);
			answer = calculateModulus(x, y);
		}
	
		else if(choice == 6)
		{
			std::cout << "Thank you for using my calculator - goodbye!" << "\n";
		}
	
		else
		{
			std::cout << "Invalid Entry - please select a valid option!" << "\n" << "\n";
		}
	
	}while(choice != 6);
	
	return 0;
}

//function definitions
void getInput(double& x, double& y)
{
	std::cout << "Please enter a value: ";
	std::cin >> x;
	std::cout << "\n" << "Please enter another value: ";
	std::cin >> y;
}

double calculateAddition(double x, double y)
{
	double answer(0);
	
	answer = x + y;
	
	std::cout << x << "+" << y << " = " << answer << "\n" << "\n";
	
	return answer;
}

double calculateSubtraction(double x, double y)
{
	double answer(0);
	
	answer = x - y;
	
	std::cout << x << "-" << y << " = " << answer << "\n" << "\n";
	
	return answer;
}

double calculateMultiplication(double x, double y)
{
	double answer(0);
	
	answer = x * y;
	
	std::cout << x << "*" << y << " = " << answer << "\n" << "\n";
	
	return answer;
}

double calculateDivision(double x, double y)
{
	double answer(0);
	
	if(y == 0)
	{
		std::cout << "The denominator cannot be 0! Please enter a non-zero value: ";
		std::cin >> y;
		answer = x / y;
	}
	
	else
	{
		answer = x / y;
	}
	
	std::cout << x << "/" << y << " = " << answer << "\n" << "\n";
	
	return answer;
}

int calculateModulus(int x, int y)
{
	int answer(0);
	
	if(y == 0)
	{
		std::cout << "The denominator cannot be 0! Please enter a non-zero value: ";
		std::cin >> y;
		answer = x % y;
	}
	
	else
	{
		answer = x % y;	
	}
	
	std::cout << x << "%" << y << " = " << answer << "\n" << "\n";
	
	return answer;
}

// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// snakis