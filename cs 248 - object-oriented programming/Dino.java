public class Dino extends Fishnew
{
	//int horns; use the fins variable
	
	public Dino(String n, String s, String c, int h)
	{
		super(n,s,c,h);
	}
	
	public int getHorns() { return fins; }
	public int getFins() { return 0; }
	
	public toString()
	{
		return super.toString()+" # of horns="+fins;
	}
}