class StackLL implements Stack
{
	private class node
	{
		public Object data;
		public node next;
	}
	
	node top;
	int count;
	
	public StackLL()
	{
		top=null; count=0;
	}
	
	public void push(Object x)
	{
		node newnode=new node();
		newnode.data=x;
		newnode.next=top;
		top=newnode;
		count++;
	}
	
	public Object pop()
	{
		if(isEmpty()) return null;
		Object saveditem=top.data;
		count--;
		top=top.next;
		return saveditem;
	}
	
	public Object getTop()
	{
		if(isEmpty()) return null;
		else return top.data;
	}
	
	public int size() { return count; }
	public boolean isEmpty() { return count<=0; }
	public boolean isFull() { return false; }
	public void makeEmpty() { top=null; count=0; }
}
