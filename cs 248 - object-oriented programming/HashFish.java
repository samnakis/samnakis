import java.io.*;
import java.util.*;

class HashFish
{
	
	public static void main(String [] args) throws IOException
	{
		Scanner ff=new Scanner(new FileReader("fishfile.txt"));
		int fishcount;
		fishcount=ff.nextInt();
		
		HashMap<String,Fish> horrible;
		horrible=new HashMap<String,Fish>();
		
		for(int i=0; i<fishcount; i++)
		{
			Fish f=new Fish(ff);
			horrible.put(f.getName(),f);
		}
		
		Fish f2=new Fish("Mittens","black","catfish",8);
		horrible.put(f2.getName(),f2);

		System.out.println(horrible.get("Nemo"));

	}
}