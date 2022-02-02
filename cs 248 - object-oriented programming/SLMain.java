class SLMain
{
	public static void main(String [] args) throws IOException
	{
		Scanner ff=new Scanner(new FileReader("fishfile.txt"));
		int fishcount;
		fishcount=ff.nextInt();
		
		SortedList fist=new SortedListLL();
		
		for(int i=0; i<fishcount; i++)
		{
			S.insert(new Fish(ff));
		}
		
		for(int i=0; i<fist.size(); i++)
			System.out.println(fist.get(i));
		
		fist.reset();
		while(fist.hasNext())
		{
			Fish f=(Fish) fist.getNext();
			f.print();
		}
	}
}