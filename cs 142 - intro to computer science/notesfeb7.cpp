#include <iostream>

int main ()
{
	int score(0);
	char letterGrade;
	int extraCredit(0);
	bool attendance;
	attendance = false;
	
	extraCredit = 40;
	
	std::cout << "Please enter your score: ";
	std::cin >> score;
	std::cout << "\n";
	
	if((score >= 70 || extraCredit > 50) && attendance == true)
	{
		letterGrade = 'P';
	}
	
	else
	{
		letterGrade = 'F';
	}
	
	std::cout << "Your letter grade is: " << letterGrade;
	

	return 0;
}