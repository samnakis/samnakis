#include <iostream>
#include <string.h>

//function declaration
void reversedWord(char input[], int size);

int main()
{
	//declaring char variables and setting the character limit to 100
	//for the word
	char word[100];
	char choice;
	
	std::cout << "Welcome to Sam's Word Reversal Program!" << "\n";
	
	//setting up a do-while loop while the user wants to continue
	//using the program or enters an incvalid choice
	do
	{
		//user enters a word
		std::cout << "\n";
		std::cout << "Please enter a word (100 Characters or Less): ";
		std::cin >> word;
		std::cout << "\n";
	
		//finding the string length
		int size = strlen(word);
		
		//calling the function
		reversedWord(word, size);
		
		//prints out the word spelled backwards
		std::cout << "Your word spelled backwards is: ";
		for(int i = 0; i < size; i++)
		{
			std::cout << word[i];
		}
		std::cout << "\n" << "\n";
		
		//asks the user if they want to continue
		std::cout << "Would you like to continue (Y|N)? ";
		std::cin >> choice;
		
		//if the user enters an invalid option for continuing or not
		while(choice != 'N' && choice != 'Y')
		{
			std::cout << "\n" << "Invalid Input - Please enter 'Y' or 'N': ";
			std::cin >> choice;
		}
		
	}while(choice == 'Y');
	//ends the do-while loop while the user says yes to continuing
	
	//ends the program if the user says no to continuing
	if(choice == 'N')
	{
		std::cout << "\n" << "Thank you! Goodbye!" << "\n";	
	}	
	
	else
	{
		
	}
	
	return 0;
}

//function definition
void reversedWord(char input[], int size)
{
	//reverses the word
	if(size > 1)
	{
		char temp = input[0];
		input[0] = input[size - 1];
		input[size - 1] = temp;
		
		reversedWord(input + 1, size - 2);
	}
	
	//if the word is only one letter long
	else
	{
		return;
	}
}