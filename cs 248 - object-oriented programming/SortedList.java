public interface SortedList extends Collection
{
	public void insert(Comparable x);
	public Comparable get(int pos);
	public Comparable delete(int pos);
	
	/* main 3 iterator functions
		public void reset();
		public Comparable getNext();
		public boolean hasNext();
	*/
}