public interface SortedListLL extends SortedList
{
	private class node
	{
		public Comparable data;
		public node next;
	}
	node head;
	int count;
	
	public SortedListLL()
	{
		head=null; count=0;
	}
	
	public void insert(Comparable x)
	{
		node before,after;
		after=head; before=null;
		//while(after.data<x)
		while(after.data.compareTo(x)<0)
		{
			before=after;
			after=after.next;
		}
		node newnode=new node();
		newnode.data=x;
		newnode.next=after;
		if(before==null) //we're inserting at the front
			head=newnode;
		else
			before.next=newnode;
		count++;
	}
	public Comparable get(int pos)
	{
		if(!(pos>=0 && pos<count)) return null;
		node p;
		p=head;
		for(int i=0; i<pos; i++)
			p=p.next;
		return p.data;
	}
	public Comparable delete(int pos)
	{
		if(!(pos>=0 && pos<count)) return null;
		node before=head;
		for(int i=0; i<pos-1; i++)
			before=before.next;
		Comparable saveditem;
		saveditem=before.next.data;
		
		return saveditem;
	}
	
	public int size() { return count; }
	public boolean isEmpty() { return count<=0; }
	public boolean isFull() { return false; }
	public void makeEmpty()
	{
		head=null; count=0;
	}
	
	private node here;
	public void reset() { here=head; }
	public Comparable getNext()
	{
		if(here=null) return null;
		Comparable item=here.data;
		here=here.next;
		return item;
	}
	public boolean hasNext()
	{
		return here!=null;
	}
	
}