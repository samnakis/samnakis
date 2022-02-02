import java.io.*;
import java.util.*;

class LaFood
{
	public static void main(String [] args) throws IOException
	{
		//welcomes user
		System.out.println("*** Welcome to the La Food Restaurant Simulator ***\n");
		
		//prompts user to enter the name of the file and reads it in
		System.out.println("Please enter the name of the data file: ");
		Scanner cin=new Scanner(System.in);
		String file=cin.next();
		System.out.print("\n");
		
		//creates a scanner
		Scanner info;
		info=new Scanner(new FileReader(file));
		
		Queue q=new QueueLL();
		
		char command='x';
		double totalPeople=0;
		double totalMinutes=0;
		
		//runs this loop while the commmand is not the end of the program
		while(command!='Q')
		{
			//reads in what the command is
			command=info.next().charAt(0);
			
			//if the command is that a party arrives
			if(command=='A')
			{
				//creates party and puts them in the queue
				Party p=new Party(info);
				q.enqueue(p);
				System.out.println("Please wait at the bar, ");
				System.out.println("  party"+p.getName()+" of "+p.getPeople()+" people. (time="+p.getArrival()+")");
			}
		
			//if the command is that a table is ready
			if(command=='T')
			{
				//seats party and takes them out of the queue
				int time=info.nextInt();
				Party p=(Party)q.dequeue();
				System.out.println("Table for"+p.getName()+"! (time="+time+")");
				
				//calculates total people and total minutes to use for average
				int partySize=p.getPeople();
				totalPeople=totalPeople+partySize;
				int toa=p.getArrival();
				totalMinutes=totalMinutes+partySize*(time-toa);
			}
		}
		
		System.out.println("** Simulation Terminated **\n");
		
		//calculates average wait time
		double avg=0;
		avg=totalMinutes/totalPeople;
		System.out.println("The average waiting time was: "+avg);
		
		//dequeues parties that were never sat and prints them out
		System.out.println("The following parties were never seated:");
		while(!q.isEmpty())
			{ ((Party)q.dequeue()).print(); }
		
		System.out.println("\nHave a nice meal!");
	}
}