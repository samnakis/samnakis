import java.io.*;

class Filewrite
{
	public static void main(String [] args) throws IOException
	{
		String filename="file.txt";
		PrintWriter f=new PrintWriter(new FileWriter(filename));
		f.println("Hello class!");
		f.println(45+" "+3);
		f.close();
	}
}