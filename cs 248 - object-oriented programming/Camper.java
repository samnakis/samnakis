import java.util.*;
/** @author sam */

public class Camper implements Comparable
{
	//data members
	String name;
	int age;
	char diet;
	
	//methods
	
	//constructor
	/** @param n The name of the camper
		@param a The age of the camper
		@param d The diet of the camper **/
	public Camper(String n,int a,char d)
	{
		name=n;
		age=a;
		diet=d;
	}
	
	public Camper(Scanner info)
	{
		name=info.next();
		age=info.nextInt();
		diet=info.next().charAt(0);
	}
	
	//observers
	public String getName()
		{ return name; }
	
	public int getAge()
		{ return age; }
	
	public char getDiet()
		{ return diet; }
	
	//compareTo function
	public int compareTo(Object x)
	{
		//is it really a camper?
		if(x instanceof Camper)
		{
			Camper c=(Camper)x;
			/*int check=this.name.compareTo(c.name);
			if(check<0)
				return -1;
			if(check>1)
				return 1;
			return 0;*/
			return name.compareTo(c.getName());
		}
		else
		{
			System.out.println("Error: you can only compare to Campers!");
			System.exit(1); //terminates the program
		}
		return 0; //to make the compiler happy
	}
	
	public String toString()
	{
		return " "+name+" "+age+" "+diet;
	}
}