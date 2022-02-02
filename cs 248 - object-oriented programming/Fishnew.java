public class Fishnew extends Animal
{
	int fins;
	
	public Fishnew(String n, String s, String c, int f)
	{
		super(n,s,c); //calls the Animal constructor
		fins=f;
	}
	
	public int getFins() { return fins; }
	
	public String toString()
	{
		return super.toString()+" # of fins+"+fins;
	}
}