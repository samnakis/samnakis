import java.util.*;
/** @author sam */

class Party
{
	//data members
	int timeArrival;
	int people;
	String name;
	int timeWaiting;
	
	//methods
	
	//constructor
	/** @param a The arrival time
		@param p The number of people
		@param n The name of the party
		@param w The time the table becomes available **/
	public Party(int a,int p,String n,int w)
	{
		timeArrival=a;
		people=p;
		name=n;
		timeWaiting=w;
	}
	
	public Party(Scanner info)
	{
		timeArrival=info.nextInt();
		people=info.nextInt();
		name=info.nextLine();
	}
	
	//observers
	public String getName()
		{ return name; }
	
	public int getPeople()
		{ return people; }
	
	public int getArrival()
		{ return timeArrival; }
	
	public int getWaiting()
		{ return timeWaiting; }
	
	public void print()
	{
		System.out.println("  party"+name+" of "+people+" people.");
	}
}