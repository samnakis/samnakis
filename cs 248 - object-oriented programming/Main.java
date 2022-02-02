class Main
{
	static void fun(Animal a)
	{
		System.out.println(a);
	}
	
	public static void main (String [] args)
	{
		Animal a;
		a=new Animal("Ellie","elasmosaur","blue");
		
		Fishnew f;
		f=new Fishnew("Polly","parrotfish","purple",6);
		
		Dino d;
		d=new Dino("Cera","Triceratops","brown",3);
		
		System.out.println(a+"\n"+f+"\n"+d);
		
		fun(a);
		fun(f);
	}
}