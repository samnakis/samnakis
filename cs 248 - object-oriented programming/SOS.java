import java.io.*;
import java.util.*;

class SOS
{
	public static void main(String [] args) throws IOException
	{
		//prompts user to enter their list size and reads in response
		System.out.println("Please enter the size of list you want to sort: ");
		Scanner cin=new Scanner(System.in);
		int size=cin.nextInt();
		
		//fills array with random numbers
		Integer [] list;
		list=new Integer[size];
		for(int i=0; i<list.length; i++)
			{ list[i]=new Integer((int)(list.length*Math.random())); }
		
		//prints out array if there are less than 100 numbers
		if(size<=100)
		{
			System.out.println("Random array: ");
			for(int i=0; i<list.length; i++)
				{ System.out.print(list[i]+" "); }
			System.out.println();
		}
				
		//declaring variables for run time
		long timeBefore=0;
		long timeAfter=0;
		long runTime=0;
			
		//bubble sort
		//copies array
		Integer [] listCopy;
		listCopy=new Integer[size];
		for(int i=0; i<list.length; i++)
			{ listCopy[i]=list[i]; }
		
		//calls running time, sorts, then checks running time agter
		System.out.println("\n* Bubble Sort *");
		timeBefore=System.currentTimeMillis();
		Sorts.bubble(listCopy);
		timeAfter=System.currentTimeMillis();
		//subtracts time after and before to find running time
		runTime=timeAfter-timeBefore;
		System.out.println("Run time: "+runTime);
		
		//prints sorted array if less than 100 numbers
		if(size<=100)
		{
			for(int i=0; i<listCopy.length; i++)
				{ System.out.print(listCopy[i]+" "); }
			System.out.println();
		}
		//notes for all sorts are the same
		
		//insertion
		Integer [] listCopy2;
		listCopy2=new Integer[size];
		for(int i=0; i<list.length; i++)
			{ listCopy2[i]=list[i]; }
		
		System.out.println("\n* Insertion Sort *");
		timeBefore=System.currentTimeMillis();
		Sorts.insertion(listCopy2);
		timeAfter=System.currentTimeMillis();
		runTime=timeAfter-timeBefore;
		System.out.println("Run time: "+runTime);
		
		if(size<=100)
		{
			for(int i=0; i<listCopy2.length; i++)
				{ System.out.print(listCopy2[i]+" "); }
			System.out.println();
		}
		
		//selection
		Integer [] listCopy3;
		listCopy3=new Integer[size];
		for(int i=0; i<list.length; i++)
			{ listCopy3[i]=list[i]; }
		
		System.out.println("\n* Selection Sort *");
		timeBefore=System.currentTimeMillis();
		Sorts.selection(listCopy3);
		timeAfter=System.currentTimeMillis();
		runTime=timeAfter-timeBefore;
		System.out.println("Run time: "+runTime);
		
		if(size<=100)
		{
			for(int i=0; i<listCopy3.length; i++)
				{ System.out.print(listCopy3[i]+" "); }
			System.out.println();
		}
		
		//quick
		Integer [] listCopy4;
		listCopy4=new Integer[size];
		for(int i=0; i<list.length; i++)
			{ listCopy4[i]=list[i]; }
		
		System.out.println("\n* Quick Sort *");
		timeBefore=System.currentTimeMillis();
		Sorts.quick(listCopy4);
		timeAfter=System.currentTimeMillis();
		runTime=timeAfter-timeBefore;
		System.out.println("Run time: "+runTime);
		
		if(size<=100)
		{
			for(int i=0; i<listCopy4.length; i++)
				{ System.out.print(listCopy4[i]+" "); }
			System.out.println();
		}
		
		//shell
		Integer [] listCopy5;
		listCopy5=new Integer[size];
		for(int i=0; i<list.length; i++)
			{ listCopy5[i]=list[i]; }
		
		System.out.println("\n* Shell Sort *");
		timeBefore=System.currentTimeMillis();
		Sorts.shell(listCopy5);
		timeAfter=System.currentTimeMillis();
		runTime=timeAfter-timeBefore;
		System.out.println("Run time: "+runTime);
		
		if(size<=100)
		{
			for(int i=0; i<listCopy5.length; i++)
				{ System.out.print(listCopy5[i]+" "); }
			System.out.println();
		}
	}
}