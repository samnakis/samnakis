import java.io.*;
import java.util.*;

class esp
{
	//creating method to calculate the min
	public static int min(int [] grades)
	{
		int min = 100;
		for(int i=0; i<grades.length; i++)
		{
			if(min > grades[i])
			{
				min = grades[i];
			}
		}
		return min;
	}
	
	//creating method to calculate the max
	public static int max(int [] grades)
	{
		int max = 0;
		for(int i=0; i<grades.length; i++)
		{
			if(max < grades[i])
			{
				max = grades[i];
			}
		}
		return max;
	}
	
	public static void main(String [] args) throws IOException
	{
		//welcome the user to the program and prompt them to enter the file name
		System.out.println("Welcome to the Exam Statistics Program!\n");
		
		System.out.println("Please enter the name of your data file: ");
		Scanner cin=new Scanner(System.in);
		String file=cin.next();
		
		//create scanner to read in the scores from the file and put them in an array
		Scanner scorelist;
		scorelist=new Scanner(new FileReader(file));	
		int scorecount;
		scorecount=scorelist.nextInt();
		
		int[] list=new int[scorecount];
		
		for(int i=0; i<scorecount; i++)
		{
			list[i] = scorelist.nextInt();
		}
		
		//run the min and max methods and print them out
		System.out.println("\nMinimum score: " + min(list));
		
		System.out.println("Maximum score: " + max(list));
		
		//calculate the average and print it out
		double sum = 0;
		double avg = 0;
		
		for(int i=0; i<scorecount; i++)
		{
			sum += list[i];
		}
		
		avg = sum/scorecount;
		System.out.println("Average score: " + avg + "\n");
		
		//create counters for each letter grade
		int numA=0;
		int numB=0;
		int numC=0;
		int numD=0;
		int numF=0;
		
		//run each score through the loop to see which letter grade it is
		for(int i=0; i<list.length; i++)
		{
			if(list[i]<=100 && list[i]>=90)
			{
				numA++;
			}
			
			else if(list[i]<90 && list[i]>=80)
			{
				numB++;
			}
			
			else if(list[i]<80 && list[i]>=70)
			{
				numC++;
			}
			
			else if(list[i]<70 && list[i]>=60)
			{
				numD++;
			}
			
			else if(list[i]<60)
			{
				numF++;
			}
		}
		
		//print out the letter grade totals and total number of scores
		System.out.println("Number of scores by letter grade:");
		System.out.println("\tA: " + numA);
		System.out.println("\tB: " + numB);
		System.out.println("\tC: " + numC);
		System.out.println("\tD: " + numD);
		System.out.println("\tF: " + numF);
		System.out.println("There are " + scorecount + " scores.");
	}
}