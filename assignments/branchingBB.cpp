#include <iostream>

//setting up the wage function
double calculateWage(double r, double h)
{
	double w(0);
	
	if(h <= 40 && h >= 0 && r >= 0)
	{
		w = r * h;
	}
	
	else if(h > 40 && r <= 25 && r >= 0)
	{
		w = (r * 40) + (r * 2 ) * (h - 40);
	}
	
	else if(h > 40 && r > 25)
	{
		w = (r * 40) + (r * 1.5) * (h - 40);
	}
	
	else
	{
		std::cout << "Please try again.";
	}
	
	return w;
}

int main()
{
	std::cout << "Welcome to Sam's Wage Calculator!" << "\n" << "\n";
	
	//user enters their name
	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;
	std::cout << "\n";
	
	//user enters their rate
	std::cout << "Please enter your hourly rate: $";
	double rate(0);
	std::cin >> rate;
	std::cout << "\n";
	
	//user enters their hours
	std::cout << "Please enter your number of hours worked: ";
	double hours(0);
	std::cin >> hours;
	std::cout << "\n";
	
	double wage(0);
	
	//using the wage function to calculate wage
	wage = calculateWage(rate, hours);
	
	//outputs the wage and restates the user's name
	std::cout << name << ", your wage is: $" << wage << "\n" << "\n";
	std::cout << "Thank you for using my program - Goodbye!" << "\n";
	
	return 0;
}


// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// snakis