import java.io.*;
import java.util.*;

class Pi
{
	static int getlimit()
	{
		System.out.print("Please enter a limit: ");
		
		//make a Scanner and connect to the keyboard
		Scanner cin=new Scanner(System.in);
		//do the read
		int limit=cin.nextInt();
		
		return limit;
	}
	
	public static void main(String [] args)
	{
		//ask user for the limit
		int limit; //declare an integer variable
		
		limit=getlimit();
		
		//make sure input is valid/makes sense
		if(limit<=0)
		{
			System.out.println("A positive limit please.");
			return; //exit the main function
		}
		
		System.out.println(limit);
		
		double S=0;
		for(int i=1; i<=limit; i++)
		{
			S=S+1.0/(1.0*i*i);
		}
		
		//System.out.println("S="+S);
		
		double pi;
		pi=Math.sqrt(6*S);
		System.out.println("Pi="+pi);
	}
}