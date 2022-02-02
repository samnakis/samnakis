import java.io.*;
import java.util.*;

class Fishmain2
{
	public static Comparable max(Comparable [] list)
	{
		Comparable maxsofar=list[0];
		for(int i=1; i<list.length; i++)
		{
			if(list[i].compareTo(maxsofar)>0)
			{ maxsofar=list[i]; }
		}
		return maxsofar;
	}
	
	public static final int FRENZYSIZE=20;
	static void feedingfrenzy(Fish [] A)
	{
		for(int i=0; i<FRENZYSIZE; i++)
		{
			int target=(int)(A.length*Math.random());
			A[target].sharkAttack();
		}
	}
	
	public static void main(String [] args) throws IOException
	{
		Scanner ff=new Scanner(new FileReader("fishfile.txt"));
		int fishcount;
		fishcount=ff.nextInt();
		
		Fish [] school;
		school=new Fish[fishcount];
		
		for(int i=0; i<school.length; i++)
		{
			school[i]=new Fish(ff);
		}
		
		for(int i=0; i<school.length; i++)
		{
			school[i].print();
		}
		System.out.println("Oh no! Sharks!");
		feedingfrenzy(school);
		for(int i=0; i<school.length; i++)
		{
			school[i].print();
		}
		
		Fish big;
		big=(Fish)max(school);
		big.print();
	}
}