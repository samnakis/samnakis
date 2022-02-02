#include <iostream>

int main ()
{
	std::cout << "Welcome to Sam's Area Calculation Program!" << "\n";
	std::cout << "\n";
	
	std::cout << "****Rectangle Area****" << "\n";
	double recLength(0), recWidth(0), recArea(0);
	std::cout << "Please enter the length: ";
	std::cin >> recLength;
	std::cout << "\n";
	std::cout << "Please enter the width: ";
	std::cin >> recWidth;
	std::cout << "\n";
	std::cout << "The area of the rectangle is: ";
	recArea = recLength * recWidth;
	std::cout << recArea << "\n" << "\n";
		
	
	std::cout << "****Square Area****" << "\n";
	double sqSide(0), sqArea(0);
	std::cout << "Please enter the side: ";
	std::cin >> sqSide;
	std::cout << "\n";
	std::cout << "The area of the square is: ";
	sqArea = sqSide * sqSide;
	std::cout << sqArea << "\n" << "\n";
	
	
	std::cout << "****Triangle Area****" << "\n";
	double triBase(0), triHeight(0), triArea(0);
	std::cout << "Please enter the base: ";
	std::cin >> triBase;
	std::cout << "\n";
	std::cout << "Please enter the height: ";
	std::cin >> triHeight;
	std::cout << "\n";
	std::cout << "The area of the triangle is: ";
	triArea = (triBase * triHeight) / 2;
	std::cout << triArea << "\n" << "\n";
	
	
	std::cout << "Thank you! Goodbye!" << "\n";
	
	
	return 0;
}


// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// snakis