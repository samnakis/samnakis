#include <iostream>

int main()
{
	int present(0);
	bool grade;
	bool learn;
	
	present++;
	learn = true;
	grade = false;
	
	if(present > 0)
	{
		std::cout << "You are present in the class." << "\n";
		
		if(learn == true)
		{
			std::cout << "You paid attention and learned." << "\n";
		
			if(grade == true)
			{
				std::cout << "You got a good grade." << "\n";
			}
			
			else
			{
				std::cout << "You got a bad grade." << "\n";
			}
		}
					
		else
		{
			std::cout << "You did not pay attention." << "\n";
		}
	}
		
	else
	{
		std::cout << "You are not present in the class." << "\n";
	}
	
	
	
	return 0;
}