#include <iostream>

int main()
{
	std::cout << "Welcome to Sam's Wage Calculator!" << "\n" << "\n";
	
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
	
	//calculation if they did not work overtime
	if(hours <= 40 && hours >= 0 && rate >= 0)
	{
		wage = rate * hours;
	}
	
	//calculation if they did work overtime and make less than or 	//equal to $25 an hour
	else if(hours > 40 && rate <= 25 && rate >= 0)
	{
		wage = (rate * 40) + (rate * 2 ) * (hours - 40);
	}
	
	//calculation if they did work overtime and make over $25 an hour
	else if(hours > 40 && rate > 25)
	{
		wage = (rate * 40) + (rate * 1.5) * (hours - 40);
	}
	
	//if the user enters something invalid
	else
	{
		std::cout << "Please try again. ";
	}
	
	//outputs the wage
	std::cout << "Your wage is: $" << wage << "\n" << "\n";
	std::cout << "Thank you for using my program - Goodbye!" << "\n";
	
	return 0;
}


// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// snakis