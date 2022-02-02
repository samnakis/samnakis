class Heap implements PQ
{
  Comparable [] h;
  int last;

  public Heap(int maxsize)
  {
    h=new Comparable[maxsize+1];
    last=0;
  }

  public Heap() { this(100); }

  private int parent(int pos) { return pos/2; }
  private int left(int pos) { return 2*pos; }
  private int right(int pos) { return 2*pos+1; }
  private void swap(int a, int b)
  {
    Comparable tmp=h[a];  h[a]=h[b]; h[b]=tmp;
  }

  public void enqueue(Comparable x)
  {
    if(isFull()) return;
    // add the item in the last position
    h[++last]=x;
    bubbleup(last);
  }

  private void bubbleup(int pos)
  {
    // base cases
    if(pos==1) return;
    if(h[parent(pos)].compareTo(h[pos])<=0) return;
    // recursive case
    swap(pos,parent(pos));
    bubbleup(parent(pos));
  }

  public Comparable dequeue()
  {
    if(isEmpty()) return null;
    Comparable root=h[1];
    h[1]=h[last--];
    bubbledown(1);
    return root;
  }

  private void bubbledown(int pos)
  {
    // base cases
    // no children
    if(left(pos)>last) // we have no children
      return;
    // find the smallest child
    int runt=left(pos);
    if(right(pos)<=last) // the right child exists
    {
      if(h[right(pos)].compareTo(h[left(pos)])<0)
        runt=right(pos);
    }
    if(h[pos].compareTo(h[runt])<=0) return; // parent is smaller
    swap(pos,runt);
    bubbledown(runt);
  }

  public Comparable getFront()
  {
    if(isEmpty()) return null;
    else return h[1];
  }

  public int size() { return last; };
  public boolean isEmpty() { return (last<=0); }
  public boolean isFull() { return (last>=h.length-1); }
  public void makeEmpty() { last=0; }

}