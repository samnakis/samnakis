import java.io.*;
import java.util.*;

class SortMain
{
	
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

                Sorts.merge(school);
		System.out.println("\nSorting...\n");
		
		for(int i=0; i<school.length; i++)
		{
			school[i].print();
		}
		
		Integer [] list;
		list=new Integer[100];
		for(int i=0; i<list.length; i++)
			list[i]=new Integer((int)(list.length*Math.random()));
		Sorts.quick(list);
		for(int i=0; i<list.length; i++)
			System.out.print(list[i]+" ");
		System.out.println();
	}
}