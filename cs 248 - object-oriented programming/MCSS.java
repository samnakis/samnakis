import java.util.*;

class MCSS
{
	static int alg1(int [] list)
	{
		int maxsofar=0;
		for(int start=0; start<list.length; start++)
		{
			for(int stop=start; stop<list.length; stop++)
			{
				int sum=0;
				for(int i=start; i<=stop; i++)
					{ sum=sum+list[i]; }
				if(sum>maxsofar) maxsofar=sum;
			}
		}
		return maxsofar;
	}
	
	static int alg2(int [] list)
	{
		int maxsofar=0;
		for(int start=0; start<list.length; start++)
		{
			int sum=0;
			for(int stop=start; stop<list.length; stop++)
			{
				sum=sum+list[stop];
				if(sum>maxsofar) maxsofar=sum;
			}
		}
		return maxsofar;
	}
	
	static int alg3(int [] list)
	{
		//compute prefix sum
		int [] pink=new int[list.length];
		pink[0]=list[0];
		for(int i=1; i<list.length; i++)
		{
			pink[i]=pink[i-1]+list[i];
		}
		//compute smallest pink number to the left
		int [] blue=new int[list.length];
		blue[0]=0;
		for(int i=1; i<list.length; i++)
		{
			blue[i]=blue[i-1];
			if(pink[i-1]<blue[i-1]) blue[i]=pink[i-1];
		}
		
		//best subsequence sum ending at each position
		int [] red=new int[list.length];
		for(int i=0; i<list.length; i++)
		{
			red[i]=pink[i]-blue[i];
		}
		
		//largest red number is the answer
		int max=red[0];
		for(int i=1; i<list.length; i++)
		{
			if(max<red[i]) max=red[i];
		}
		return max;
	}
	
	static int [] makeRandomList(int size, int range)
	{
		int [] list=new int[size];
		for(int i=0; i<size; i++)
		{
			list[i]= -range+(int)((2*range+1)*Math.random());
		}
		return list;
	}
	
	public static void main(String [] args)
	{
		int [] list; //={1,-3, -4, 7, 8, -2, 5};
		int size, range;
		Scanner cin=new Scanner(System.in);
		System.out.print("Enter the size and range please: ");
		size=cin.nextInt();
		range=cin.nextInt();
		list=makeRandomList(size,range);
		/*
		for(int i=0; i<size; i++)
		{
			System.out.print(list[i]+" ");
		}
		*/
		System.out.println("\n Alg3 3="+alg3(list));
		System.out.println("\n Alg2 2="+alg2(list));
		System.out.println("\n Alg1 1="+alg1(list));
	}
}