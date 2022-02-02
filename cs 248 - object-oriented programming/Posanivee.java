import java.io.*;
import java.util.*;

class Posanivee
{
	public static void main(String [] args) throws IOException
	{
		//welcomes user
		System.out.println("Welcome to Camp Posanivee!!\n");
		
		//creates a scanner
		Scanner info;
		info=new Scanner(new FileReader("camp.txt"));
		
		//creates command character and new bst		
		char command='x';		
		BST tree=new BST();
				
		//runs this loop while the commmand is not the end of the program
		while(command!='Q')
		{
			//reads in what the command is
			command=info.next().charAt(0);
			System.out.print("Command: "+command);
			
			//if the command is to print out list of commands
			if(command=='H')
			{
				System.out.println("\nAvailable Commands: ");
				System.out.println("'H' = Help: prints a list of commands");
				System.out.println("'E name age diet' = Enroll a new camper");
				System.out.println("'W name' = Withdraw a camper");
				System.out.println("'D name' = Display the age and diet of a camper");
				System.out.println("'A' = Print the average age of the campers");
				System.out.println("'L' = List all campers names in alphabetical order");
				System.out.println("'V' = Print the number of vegan campers");
				System.out.println("'P' = List all the campers names in preorder");
				System.out.println("'Q' = Quit\n");
			}
			
			//if the command is to enroll a new camper
			if(command=='E')
			{
				//creates a new camper and inserts them into the tree
				Camper c=new Camper(info);
				tree.insert(c);
				System.out.print(c);
				System.out.println("\nNew camper added.\n");
			}
		
			//if the command is to withdraw a camper
			if(command=='W')
			{
				//creates a "dummy" character and deletes it from the tree
				Camper c=new Camper(info.next(),0,' ');
				Camper found=(Camper) tree.delete(c);
				System.out.print(" "+(found.getName()));
				System.out.println("\nCamper withdrawn.\n");
			}
			
			//if the command is to display age and diet of a camper
			if(command=='D')
			{
				//finds the camper
				Camper c=new Camper(info.next(),0,' ');
				Camper found=(Camper) tree.lookup(c);
				System.out.print(" "+(found.getName()));
				//if the camper is found, their info is printed out
				if(found!=null)
				{
					System.out.println("\n  Name: "+(found.getName()));
					System.out.println("  Age: "+(found.getAge()));
					System.out.println("  Diet: "+(found.getDiet())+"\n");
			 	}
				//in case the camper isn't found
				else
					System.out.println("Uh oh! That camper doesn't exist!");
			}
			
			//if the command is to print the average age of the campers
			if(command=='A')
			{	
				double sum=0;
				tree.reset(BST.POSTORDER);
				//adds age to sum variable
				while(tree.hasNext())
				{
					sum+=((Camper)tree.getNext()).getAge();
				}
				
				//deals with the case when the tree is empty
				if(tree.isEmpty())
				{
					System.out.println("\nThere are no campers.\n");
				}
				
				//calculates and prints out average age
				else
				{
					System.out.println("\nAverage age = "+(sum/tree.count)+"\n");
				}
			}
			
			//if the command is to list all campers' names in alphabetical order
			if(command=='L')
			{
				System.out.println("\nAlphabetical List of Campers:");
				tree.reset(BST.INORDER);
				while(tree.hasNext()) { System.out.println(((Camper)tree.getNext()).getName()); }
				System.out.print("\n");
			}
			
			//if the command is to print the number of vegan campers
			if(command=='V')
			{
				int vCount=0;
				tree.reset(BST.POSTORDER);
				//adds one to the count for every vegan camper
				while(tree.hasNext())
				{
					if(((Camper)tree.getNext()).getDiet()=='V')
					{
						vCount++;
					}
				}
				
				//deals with the case when the tree is empty
				if(tree.isEmpty())
				{
					System.out.println("\nThere are no campers.\n");
				}
				
				//prints out number of vegans
				else
				{
					System.out.println("\nNumber of vegan campers: "+vCount+"\n");
				}
			}
			
			//if the command is to list all campers names in preorder
			if(command=='P')
			{
				System.out.println("\nPreorder traversal:");
				tree.reset(BST.PREORDER);
				while(tree.hasNext()) { System.out.println(((Camper)tree.getNext()).getName()); }
				System.out.print("\n");
			}
		}
		
		//end of program message
		System.out.println("\nEnd of program.\nBring plenty of calomine!");
	}
}