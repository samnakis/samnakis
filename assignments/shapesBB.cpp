#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>


int main()

{
	std::cout << "Welcome to Sam's Area Calculation Program! (Part Two)" << "\n";
	std::cout << "\n";


	std::cout << "****Circle Area****" << "\n";
	double cirRadius(0), cirArea(0);
	std::cout << "Please enter the radius: ";
	std::cin >> cirRadius;
	std::cout << "\n";
	std::cout << "The area of the circle is: ";
	cirArea = M_PI * (cirRadius * cirRadius);
	std::cout << cirArea << "\n" << "\n";
	
	

	std::cout << "****Trapezoid Area****" << "\n";
	double trapBaseOne(0), trapBaseTwo(0), trapHeight(0), trapArea(0);
	std::cout << "Please enter the first base: ";
	std::cin >> trapBaseOne;
	std::cout << "\n";
	std::cout << "Please enter the second base: ";
	std::cin >> trapBaseTwo;
	std::cout << "\n";
	std::cout << "Please enter the height: ";
	std::cin >> trapHeight;
	std::cout << "\n";
	std::cout << "The area of the trapezoid is: ";
	trapArea = (trapBaseOne + trapBaseTwo) / 2 * trapHeight;
	std::cout << trapArea << "\n" << "\n";
	

	std::cout << "****Hexagon Area****" << "\n";
	double hexSide(0), hexArea(0);
	std::cout << "Please enter the side: ";
	std::cin >> hexSide;
	std::cout << "\n";
	std::cout << "The area of the hexagon is: ";
	hexArea = (( 3 * sqrt (3)) / 2 ) * (hexSide * hexSide);
	std::cout << hexArea << "\n" << "\n";
	
	
	std::cout << "Thank you! Goodbye!" << "\n";
	
	
	return 0;
}



// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// snakis