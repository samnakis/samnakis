import java.io.*;
import java.util.*;

class Fileread
{
	public static void main(String [] args) throws IOException
	{
		Scanner g;
		g=new Scanner(new FileReader("file.txt"));
		
		String line1;
		int a,b;
		
		line1=g.nextLine();
		a=g.nextInt();
		b=g.nextInt();
		
		System.out.println(line1+"\n"+a+" "+b);
	}
}