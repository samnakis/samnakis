#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream inStream;
	
	inStream.open("myTestFile.txt");
	
	int num(0);
	std::string myString;
	
	inStream >> myString;
	
	std::cout << myString << "\n";
	
	num = 15;
	
	std::ofstream outStream;
	
	outStream.open("myTestFile.txt");
	
	outStream << num;
	
	return 0;
}