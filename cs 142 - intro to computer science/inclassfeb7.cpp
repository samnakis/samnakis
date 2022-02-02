#include <iostream>

int main ()
{
	std::string firstName;
	std::string lastName;
	
	std::cout << "Please enter your first name: ";
	std::cin >> firstName;
	std::cout << "\n";
	std::cout << "Please enter your last name: ";
	std::cin >> lastName;
	std::cout << "\n";
	std::cout << firstName << lastName << "\n" << "\n";
	
	
	std::cout << "****Addition****" << "\n";
	int add1(0), add2(0), add(0);
	std::cout << "Please enter your first number: ";
	std::cin >> add1;
	std::cout << "\n";
	std::cout << "Please enter your second number: ";
	std::cin >> add2;
	std::cout << "\n";
	add = add1 + add2;
	std::cout << "The sum of the numbers is: ";
	std::cout << add << "\n" << "\n";
	
	
	std::cout << "****Division****" << "\n";
	double divi1(0), divi2(0), divi(0);
	std::cout << "Please enter your first number: ";
	std::cin >> divi1;
	std::cout << "\n";
	std::cout << "Please enter the number to divide by: ";
	std::cin >> divi2;
	std::cout << "\n";
	divi = divi1 / divi2;
	std::cout << "The quotient of the numbers is: ";
	std::cout << divi << "\n" << "\n";
	
	
	std::cout << "****Subtraction****" << "\n";
	int sub1(0);
	double sub2(0), sub(0);
	std::cout << "Please enter your first number: ";
	std::cin >> sub1;
	std::cout << "\n";
	std::cout << "Please enter the number to subtract from the first: ";
	std::cin >> sub2;
	std::cout << "\n";
	sub = sub1 - sub2;
	std::cout << "The difference of the numbers is: ";
	std::cout << sub << "\n" << "\n";
	
	
	std::cout << "****Multiplication****" << "\n";
	float mult1(0), mult2(0), mult(0);
	std::cout << "Please enter your first number: ";
	std::cin >> mult1;
	std::cout << "\n";
	std::cout << "Please enter your second number: ";
	std::cin >> mult2;
	std::cout << "\n";
	mult = mult1 * mult2;
	std::cout << "The product of the numbers is: ";
	std::cout << mult << "\n" << "\n";
	
	
	std::cout << "****Modulus****" << "\n";
	int mod1(0), mod2(0), mod(0);
	std::cout << "Please enter your percentage number: ";
	std::cin >> mod1;
	std::cout << "\n";
	std::cout << "Please enter your total number: ";
	std::cin >> mod2;
	std::cout << "\n";
	mod = mod1 % mod2;
	std::cout << "The percentage of the numbers is: ";
	std::cout << mod << "\n" << "\n";
	
	
	std::cout << "Thank you! Goodbye!" << "\n";
	

	return 0;
}