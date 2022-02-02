#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string name;
	int num(0);
	
	std::ifstream inputFile("myTextFile.text");
	
	if(inputFile.is_open())
	{
		inputFile >> name >> num;
			
		std::cout << name << "\t" << num << "\n";
		
		std::ofstream outputFile;
		
		outputFile.open("numFile.txt");
		
		outputFile << num << "\n";
		
		outputFile.close();
	}
	
	return 0;
}