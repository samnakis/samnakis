#include <iostream>
//used later to make money values only go to two decimal places
#include <iomanip>

int main()
{
	std::cout << "Welcome to Sam's Menu Order System" << "\n" << "\n";
	
	//declare variables for ordering food
	int selection(0);
	double total(0);
	
	int hamburger(0);
	int cheeseburger(0);
	int fries(0);
	int drink(0);
	int cake(0);
	int food(0);
	
	//do while loop for ordering from the menu
	do
	{
	std::cout << "What would you like to order?" << "\n" << "\n";
	
	std::cout << "1.	Hamburger 		$1.50" << "\n";
	std::cout << "2.	Cheeseburger 		$2.00" << "\n";
	std::cout << "3.	French Fries		$1.00" << "\n";
	std::cout << "4.	Soft Drink 		$1.00" << "\n";
	std::cout << "5.	Piece of Cake 		$1.25" << "\n";
	std::cout << "6.	Complete Order" << "\n" << "\n";
	
	std::cout << "Please enter your selection: ";
	std::cin >> selection;
	
	//if and else if statements for each food item
	if(selection == 1)
	{
		std::cout << "You have selected a Hamburger" << "\n" << "\n";
		total += 1.50;
		hamburger++;
		food++;
	}
	
	else if(selection == 2)
	{
		std::cout << "You have selected a Cheeseburger" << "\n" << "\n";
		total += 2.00;
		cheeseburger++;
		food++;
	}
	
	else if(selection == 3)
	{
		std::cout << "You have selected French Fries" << "\n" << "\n";
		total += 1.00;
		fries++;
		food++;
	}
	
	else if(selection == 4)
	{
		std::cout << "You have selected a Soft Drink" << "\n" << "\n";
		total += 1.00;
		drink++;
		food++;
	}
	
	else if(selection == 5)
	{
		std::cout << "You have selected a Piece of Cake" << "\n" << "\n";
		total += 1.25;
		cake++;
		food++;
	}
	
	else if(selection == 6)
	{
		std::cout << "You have selected to complete your order." << "\n" << "\n";
	}
	
	else
	{
		std::cout << "Invalid Selection! Please enter a valid selection." << "\n" << "\n";
	}
	}while(selection != 6);
	
	//while loop to display what food and how much the user ordered
	while(food > 0)
	{
		
	if(hamburger > 0)
	{
		std::cout << "You have ordered ";
		std::cout << hamburger;
		std::cout << " hamburger(s)" << "\n";
		food -= hamburger;
		hamburger = 0;
	}
		
	else if(cheeseburger > 0)
	{
		std::cout << "You have ordered ";
		std::cout << cheeseburger;
		std::cout << " cheeseburger(s)" << "\n";
		food -= cheeseburger;
		cheeseburger = 0;
	}
		
	else if(fries > 0)
	{
		std::cout << "You have ordered ";
		std::cout << fries;
		std::cout << " french fries" << "\n";
		food -= fries;
		fries = 0;
	}
		
	else if(drink > 0)
	{
		std::cout << "You have ordered ";
		std::cout << drink;
		std::cout << " drink(s)" << "\n";
		food -= drink;
		drink = 0;
	}
		
	else if(cake > 0)
	{
		std::cout << "You have ordered ";
		std::cout << cake;
		std::cout << " piece(s) of cake" << "\n";
		food -= cake;
		cake = 0;
	}
	}
	
	//adds tax to the total cost
	total = total * 1.07;
	
	//next two lines make money values only go to two decimal places
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cout << "\n" << "Your total is: $" << total << "\n" << "\n";
	
	//declare variables for the money the user inputs and change
	double money(0);
	double change(0);
	
	std::cout << "Enter the amount tendered: $";
	std::cin >> money;
	std::cout << "\n";
	
	//set up a while loop for if the user did not enter enough money
	while(money < total)
	{
		std::cout << "You have not entered enough money to purchase your items!" << "\n";
		std::cout << "Please enter an amount great than or equal to: $" << total << "\n" << "\n";
		std::cout << "Enter the amount tendered: $";
		std::cin >> money;
	}
	
	//displays how much change the user gets
	change = money - total;
	std::cout << "\n" << "Your change is: $" << change << "\n" << "\n";
	std::cout << "Thank you! Enjoy your meal!" << "\n";
	
	
	return 0;
}


// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// snakis