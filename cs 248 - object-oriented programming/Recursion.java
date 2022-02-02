class Recursion
{
	int factorial(int n)
	{
		if(n==0) return 1; //base case
		else return factorial(n-1)*n; //recursive case
	}
	
	static void printback(int n)
	{
		if(n<10)
			System.out.print(n);
		else
		{
			int last=n%10;
			int rest=n/10;
			System.out.print(last);
			printback(rest);
		}
	}
	
	public static void main (String [] args)
	{
		System.out.println(factorial(4));
		//System.out.println(factorial(-1));
		printback(8675309);
		System.out.println()
	}
}