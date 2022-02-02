#include <iostream>
#include <fstream>
#include <string>

char letter;
//function declaration
void calculateLetterGrade(double, char&);

int main()
{
	double score(0);
	double num(0);
	
	char letterGrade;
	
	std::string string1, string2, string3, string4;
	std::string fileInput, fileOutput;
	
	std::ifstream inFile;
	
	std::cout << "Welcome to Sam's Grade Calculator!" << "\n" << "\n";
	
	std::cout << "Please enter the file you wish to open: ";
	std::cin >> fileInput;
	std::cout << "\n";
	
	double assignmentScore(0);
	double participationScore(0);
	double midtermScore(0);
	double finalScore(0);
	
	//open the input stream
	inFile.open(fileInput.c_str());
	if(inFile.is_open())
	{			
		//reading in the name of the section and number	
		inFile >> string1 >> num;
								
		double value(0);
				
		for(int i = 0; i < num; i++)
		{
			inFile >> value;
			assignmentScore = assignmentScore + value;
		}		
		//calculating the percentage it accounts for (repeated below)
		assignmentScore = assignmentScore / num * .5;
				
		inFile >> string2 >> num >> participationScore;
		participationScore = participationScore * .1;
		
		inFile >> string3 >> num >> midtermScore;
		midtermScore = midtermScore * .2;
		
		inFile >> string4 >> num >> finalScore;
		finalScore = finalScore * .2;
		
		//calculating the total score
		score = assignmentScore + participationScore + midtermScore + finalScore;
	}
	
	//if the file doesn't open
	else
	{
		std::cout << "Unable to open file" << "\n";
	}	
	//closing the input stream	
	inFile.close();
	
	//run the function to find the letter grade
	calculateLetterGrade(score, letterGrade);

	std::cout << "Reading from file " << fileInput << "..." << "\n" << "\n";

	std::cout << "Calculating grades..." << "\n" << "\n";

	std::cout << "Save To (Filename): ";
	std::cin >> fileOutput;
	std::cout << "\n";
	
	//open the output stream and put the grade and letter on to it
	std::ofstream outFile;
	outFile.open(fileOutput.c_str());
	outFile << score << "\t" << letterGrade << "\n";

	std::cout << "Score & Letter Grade written to file: " << fileOutput << "\n" << "\n";

	std::cout << "Thank you for using my program - good bye!" << "\n";
	
	//close the output stream
	outFile.close();
}

//function definition
void calculateLetterGrade(double score, char& letter)
{
	if(score >= 90)
	{
		letter = 'A';
	}
	
	else if(score >= 80 && score <=89)
	{
		letter = 'B';
	}
	
	else if(score >= 70 && score <=79)
	{
		letter = 'C';
	}
	
	else if(score >= 60 && score <=69)
	{
		letter = 'D';
	}
	
	else if(score >= 0 && score <= 59)
	{
		letter = 'F';
	}
	
	else
	{
		
	}
}

// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// snakis