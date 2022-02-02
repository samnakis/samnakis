import java.io.*;
import java.util.*;

class guessinggame
{
	public static String insult()
	{
		//creating random insults
		int insultnum = (int)(1+5*Math.random());
		String insult = "";
		
		if(insultnum==1)
		{
			insult = "silly goose!";
		}
		
		if(insultnum==2)
		{
			insult = "bozo!";
		}
		
		if(insultnum==3)
		{
			insult = "dummy!";
		}
		
		if(insultnum==4)
		{
			insult = "dork!";
		}
		
		if(insultnum==5)
		{
			insult = "peanut head!";
		}
		
		return insult;
	}
	
	public static void main(String [] args)
	{
		char again='y';

		//do while loop for when the user wants to continue playing
	do{
		int number;
		//choosing a random number
		number = (int)(1+100*Math.random());
		
		//welcome the user to the program and ask them to enter their guess
		System.out.println("Hi, Welcome to the Guessing Game!\nPlease enter a whole number 1-100:");
		
		//create a scanner to read the number they input
		Scanner cin=new Scanner(System.in);
		int guess=cin.nextInt();
		
		//create the loop if the guess is incorrect
		while(guess!=number)
		{
			if(guess>number)
			{
				System.out.println("Yikes! Your guess is too high, " + insult() + "\n\nPlease guess again:");
				guess=cin.nextInt();
			}
			
			else
			{
				System.out.println("Oh no! Your guess is too low, " + insult() + "\n\nPlease guess again:");
				guess=cin.nextInt();
			}
		}
		
		//when they correctly guess
		if(guess==number)
		{
			System.out.println("Congrats! You guessed correctly!\n");
			
			
			System.out.println("Would you like to play again? Enter 'Y' for yes and 'N' for no.");
			again=cin.next().charAt(0);
		}
	}while (again=='Y' || again=='y');
	}
}