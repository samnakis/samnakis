import java.io.*;
import java.util.*;

class HTW
{
	//global variables
	static int roomCount;
	static int currentRoom=1;
	static int adjRoom1;
	static int adjRoom2;
	static int adjRoom3;
	static Rooms [] cave;
	static int wumpus=1;
	static int arrows=3;
	static char action;
	static Scanner cin;
	static int play;
	static int wumpusRoom;
	static int spiderRoom;
	static int pitRoom;
	
	
	public static void main(String [] args) throws IOException
	{
		//reading in the text file of cave layout
		Scanner wumptext;
		wumptext=new Scanner(new FileReader("Wumpus.txt"));
		
		//allows person to type into program
		cin=new Scanner(System.in);
		
		roomCount=wumptext.nextInt();
		cave=new Rooms[roomCount];
		
		//picking trap rooms
		wumpusRoom=(int)(2+(roomCount-1)*Math.random());
		spiderRoom=(int)(2+(roomCount-1)*Math.random());
		pitRoom=(int)(2+(roomCount-1)*Math.random());
		
		//solving the problem if the trap rooms are the same
		if(spiderRoom==wumpusRoom || spiderRoom==pitRoom)
		{
			spiderRoom=(int)(2+(roomCount-1)*Math.random());
		}
		
		else if(pitRoom==wumpusRoom || pitRoom==spiderRoom)
		{
			pitRoom=(int)(2+(roomCount-1)*Math.random());
		}
		
		//loads room info into array
		for(int i=0;i<cave.length;i++)
		{
			cave[i]=new Rooms(wumptext);
		}
		
		adjRoom1=cave[currentRoom-1].adjRoom1;
		adjRoom2=cave[currentRoom-1].adjRoom2;
		adjRoom3=cave[currentRoom-1].adjRoom3;
		
		//program intro
		System.out.println("Welcome to **Hunt The Wumpus!**\n");
		System.out.println("You are a mighty warrior, and armed with your trusty bow" 
			+" and 3 arrows, you enter The Caves in search of the mighty Wumpus. If you" 
			+" shoot the Wumpus, you are victorious and the masses will praise you, but" 
			+" if you stumble upon the Wumpus unawares, it will eat you! Also, beware of" 
			+" the webs of the giant poisonous spiders and the bottomless pits!\n");
		System.out.println("Your senses of smell and hearing will aid you on your quest," 
			+" for the Wumpus does not bathe and can be smelled one room away. Also, the" 
			+" clicking mandibles of the poisonous spiders can be heard one room away," 
			+" and the foul odor of a bottomless pit can be smelled one room away.");
		
		play=Gameplay();
	}
	
	public static int Gameplay()
	{
		//loop makes game continue to run until the user runs out of arrows or 		wumpus dies
		do
		{
			//telling user the logistics of their locoation/stats
			System.out.println("\nYou are in room "+currentRoom+".");
			System.out.println("You have "+arrows+" arrows left.");
			System.out.println(cave[currentRoom-1].roomDescription);
			System.out.println("There are tunnels leading to rooms "
				+cave[currentRoom-1].adjRoom1+", "+cave[currentRoom-1].adjRoom2+", and "
				+cave[currentRoom-1].adjRoom3+".");
			
			//asking user what their next move is
			System.out.println("Would you like to (M)ove or (S)hoot?");
			action=cin.next().charAt(0);
			
			//calls movement method if that's what the user chose to do
			if(action=='M' || action=='m')
			{
				int move=Movement();
				currentRoom=move;
			}
			
			//calls shooting method if that's what the user chose to do
			else if(action=='S' || action=='s')
			{
				int shoot=Shooting();
				if(shoot==1) {return 0;}
			}
			
			//prints error message if user enters anything else
			else
			{
				System.out.println("Oh no! Please enter either 'M' to move or" 
					+" 'S' to shoot!");
			}
		}while(wumpus==1 && arrows!=0);
		
		//if wumpus is dead (win)
		if(wumpus==0)
		{
			System.out.println("You shot the stinky Wumpus! *You win!**");	
		}	
		
		//if wumpus is alive and you have no arrows	(loss)
		if(wumpus==1 && arrows==0)
		{
			System.out.println("You are out of arrows and so the smelly Wumpus lives" 
				+" to see another day... **You lost the game.**");
		}
		
		return 0;	
	}	
	
	//movement
	public static int Movement()
	{
		System.out.println("Which room are you traveling to?");
		int choice=cin.nextInt();
		//System.out.println(choice!=cave[currentRoom-1].adjRoom1);
		//System.out.println(choice!=cave[currentRoom-1].adjRoom2);
		//System.out.println(choice!=cave[currentRoom-1].adjRoom3);
		
		
		//for invalid room choices
		if(choice!=cave[currentRoom-1].adjRoom1 && choice!=cave[currentRoom-1].adjRoom2
			&& choice!=cave[currentRoom-1].adjRoom3)
		{
			System.out.println("Silly, that's not an option!");
			return currentRoom;
		}
		
		if(choice==cave[currentRoom-1].adjRoom1 || 
			choice==cave[currentRoom-1].adjRoom2 || 
			choice==cave[currentRoom-1].adjRoom3)
		{
			//close to wumpus warning
			if(cave[choice-1].adjRoom1==wumpusRoom ||
				cave[choice-1].adjRoom2==wumpusRoom ||
				cave[choice-1].adjRoom3==wumpusRoom)
			{
				System.out.println("You smell something stinky! The Wumpus is close.");
			}
			
			//close to spiders warning
			if(cave[choice-1].adjRoom1==spiderRoom ||
				cave[choice-1].adjRoom2==spiderRoom ||
				cave[choice-1].adjRoom3==spiderRoom)
			{
				System.out.println("You hear a faint clicking sound... spiders are near.");
			}
			
			//close to pit warning
			if(cave[choice-1].adjRoom1==pitRoom ||
				cave[choice-1].adjRoom2==pitRoom ||
				cave[choice-1].adjRoom3==pitRoom)
			{
				System.out.println("You hear screams echoing from a nearby pit.");
			}
			
			//wumpus death
			if(choice==wumpusRoom)
			{
				System.out.println("The stupid smelly Wumpus ate you... **You"
					+" lost the game.**");
				System.exit(0);
			}
			
			//spider death
			else if(choice==spiderRoom)
			{
				System.out.println("Eek! You found the spiders! **You lost the game.**");
				System.exit(0);
			}
			
			//pit death
			else if(choice==pitRoom)
			{
				System.out.println("Yikes! You tumbled into the pit! **You lost the game.**");
				System.exit(0);
			}
			return choice;
		}
		return choice;
	}
	
	//shooting
	public static int Shooting()
	{
		System.out.println("Which room are you shooting your arrow into?");
		int choice=cin.nextInt();
		
		//for invalid room choices
		if(choice!=cave[currentRoom-1].adjRoom1 && choice!=cave[currentRoom-1].adjRoom2
			&& choice!=cave[currentRoom-1].adjRoom3)
		{
			System.out.println("You can't shoot there!");
			return arrows;
		}
		
		//correct choice
		if(choice==wumpusRoom)
		{
			wumpus=0;
			System.out.println("You shot the stinky Wumpus! **You win!**");
			return 1;	
		}
		
		//incorrect choice
		else if(choice!=wumpusRoom)
		{
			System.out.println("Oof, you missed. The Wumpus is still alive and stinky.");
			arrows--;	
		}
		return 0;
	}
}