#include <iostream>

int main()
{
	std::cout << "Please enter your final exam score: ";
	double score(0);
	char letterGrade('I');
	std::cin >> score;
	std::cout << "\n";
	
	if(score >= 90)
	{
		letterGrade = 'A';
	}
	
	else if(score >= 80 && score <=89)
	{
		letterGrade = 'B';
	}
	
	else if(score >= 70 && score <=79)
	{
		letterGrade = 'C';
	}
	
	else if(score >= 60 && score <=69)
	{
		letterGrade = 'D';
	}
	
	else if(score >= 0 && score <= 59)
	{
		letterGrade = 'F';
	}
	
	else
	{
		std::cout << "Error. Please try again.";
	}
	
	switch(letterGrade)
	{
		case 'A':
			std::cout << "You earned an A" << "\n";
			break;
		case 'B':
			std::cout << "You earned a B" << "\n";
			break;
		case 'C':
			std::cout << "You earned a C" << "\n";
			break;
		case 'D':
			std::cout << "You earned a D" << "\n";
			break;
		case 'F':
			std::cout << "You earned an F" << "\n";
			break;
		default:
			std::cout << "Invalid letter grade." << "\n";
			break;
	}

	
	//std::cout << "Your letter grade is: " << letterGrade << "\n";
	
	
	return 0;
}