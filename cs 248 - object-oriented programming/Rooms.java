import java.util.*;

public class Rooms
{
	int roomCount;
	int currentRoom;
	int adjRoom1, adjRoom2, adjRoom3;
	String roomDescription;
	
	//constructor
	/** @param n the number of rooms
		@param c the current rooom
		@param a1 adjacent room 1
		@param a2 adjacent room 2
		@param a3 adjacent room 3
		@param d the room description **/
	public Rooms(int c,int a1,int a2,int a3, String d)
	{
		currentRoom=c;
		adjRoom1=a1;
		adjRoom2=a2;
		adjRoom3=a3;
		roomDescription=d;
	}
	
	public Rooms(Scanner info)
	{
		currentRoom=info.nextInt();
		adjRoom1=info.nextInt();
		adjRoom2=info.nextInt();
		adjRoom3=info.nextInt();
		roomDescription=info.nextLine();
		roomDescription=info.nextLine();
	}
	
	public void print()
	{
		System.out.println("You are in room "+currentRoom+"\n"+roomDescription+"\n"+
			"There are tunnels to rooms "+adjRoom1+", "+adjRoom2+", and"+adjRoom3+".");
	}
}