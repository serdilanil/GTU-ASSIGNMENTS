import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;

/**
 * Concrete class of heap data structure.
 * @param <E> type
 */
public class MaxHeapStructure<E extends Comparable<E> > implements MaxHeapInterface<E>,Comparable <MaxHeapStructure<E>> {

    /**
     * List of data.
     */
    protected ArrayList<E> theData;

    /**
     * Comparator.
     */
    Comparator<E> comparator = null;

    public char[] ints;

    
    @Override
    public int compareTo(MaxHeapStructure<E> obj) {
        if(obj == null)
            return 0;

          return(this.theData.get(0).compareTo(obj.theData.get(0)));

    }


    /**
     * 
     * @param parentIndex
     * @return left child index.
     */
    protected int getLeftChildIndex( int parentIndex ) {
        return 2 * parentIndex + 1;
    }

    /**
     * 
     * @param parentIndex
     * @return right child index.
     */
    protected int getRightChildIndex( int parentIndex ) {
        return 2 * parentIndex + 2;
    }

    /**
     * 
     * @param childIndex
     * @return parent index
     */
    protected int getParentIndex( int childIndex ) {
        return ( childIndex - 1 ) / 2;
    }

    /**
     * 
     * @param index
     * @return left child index
     */
    protected boolean hasLeftChild( int index ) {
        return getLeftChildIndex( index ) < theData.size();
    }

    /**
     * 
     * @param index
     * @return compare right index.
     */
    protected boolean hasRightChild( int index ) {
        return getRightChildIndex( index ) < theData.size();
    }

    /**
     * 
     * @param index
     * @return compare parent index.
     */
    protected boolean hasParent( int index ) {
        return getParentIndex( index ) >= 0;
    }

   
    protected E leftChild( int index ) {
        return theData.get( getLeftChildIndex( index ) );
    }

    
    protected E rightChild( int index ) {
        return theData.get( getRightChildIndex( index ) );
    }

   
    protected E parent( int index ) {
        return theData.get( getParentIndex( index ) );
    }

    /**
     * compare the left and right data of heap.
     * @param left
     * @param right
     * @return compareTo method.
     */
    protected int compare( E left  , E right ) {

        if( comparator != null ) {
            return comparator.compare( left ,right );
        } else {
            return left.compareTo( right );
        }

    }

    public int size() {
        return theData.size();
    }
    

    protected void swap( int i , int  j ) {

        if ( i < 0 || j < 0 || (i > theData.size() - 1)
                || (j > theData.size() - 1) ) {
            throw new IndexOutOfBoundsException();
        }

        E tempData = theData.get(i);
        theData.set( i , theData.get(j) );
        theData.set( j , tempData );

    }

    /**
     * Heapify throughout up in tree design.
     */
    protected void heapifyUp() {

        int index = theData.size() - 1;

        while ( hasParent( index ) && ( compare( parent( index ) , theData.get( index ) ) < 0 ) ) {
            swap( getParentIndex( index ) , index );
            index = getParentIndex( index );
        }

    }

    /**
     * Heapify throughout down in tree design.
     */
    protected void heapifyDown() {
        heapifyDown( 0 );
    }

    /**
     * Heapify down helper method.
     * @param index index
     */
    protected void heapifyDown( int index ) {

        while ( hasLeftChild( index ) ) {
            int smallerChildIndex = getLeftChildIndex( index );

            if( hasRightChild( index ) && ( compare(rightChild( index ), leftChild( index )) > 0 )  ) {
                smallerChildIndex = getRightChildIndex( index );
            }

            if( compare( theData.get( index ), theData.get( smallerChildIndex )) > 0 ) {
                break;
            } else {
                swap( index , smallerChildIndex );
            }

            index = smallerChildIndex;
        }
    }

    /**
     * Update the current status of Heap.
     */
    protected void updateHeap() {
        MaxHeapStructure<E> newHeap;

        if( comparator != null ) {
            newHeap = new MaxHeapStructure<>( comparator );
            for (E theDatum : theData) {
                newHeap.add( theDatum );
            }

            theData = newHeap.theData;
        }
    }

    /**
     * No parameter constructor.
     */
    public MaxHeapStructure() {
        theData = new ArrayList<E>();
    }

    /**
     * Initiate a heap with given comparator.
     * @param comp Comparator.
     */
    public MaxHeapStructure( Comparator<E> comp ) {
        this();
        comparator = comp;
    }

    public MaxHeapStructure(E data){
        theData = new ArrayList<E>();
        theData.add(data);
    }

    /**
    *Take the highest of the heap. 
    * @return theData
    */
    @Override
    public E peek() {
        if( theData.size() == 0 ) {
            throw new IllegalStateException();
        }

        return theData.get( 0 );
    }

    /**
    *@return removed which highest item. 
    */
    @Override
    public E poll() {
        if( theData.size() == 0 ) {
            throw new IllegalStateException();
        }

        E item = theData.get( 0 );
        theData.set( 0 , theData.get( theData.size() - 1 ));
        theData.remove( theData.size() - 1 );
        heapifyDown();

        return item;
    }

    /**
     * Search item which we searched if we  find return item
     * if we don't return null
     * @return item which we searched
     * @param item
     */
    @Override
    public E find( E  item ) {

        for (E theDatum : theData) {
            if ( theDatum.compareTo( item ) == 0 ) {
                return theDatum;
            }
        }

        return null;
    }

    
    @Override
    public void add( E item ) {
        theData.add( item );
        heapifyUp();
    }

    /**
     * * we determine a value to remove and we search it.
     * if we remove the item return true otherwise false or throw exception.
     * @param item
     * @return true if item removed.
     */
    @Override
    public boolean remove(E item) {
        
        if( theData.size() == 0 ) {
            throw new IllegalStateException();
        }
        
        int index = theData.indexOf( find( item ) );
        
        if( index == -1 ) {
            return false;
        }

        swap( index , theData.size() - 1 );
        theData.remove( theData.size() - 1 );
        heapifyDown( index );

        return true;
    }

    
    @Override
    public String toString() {
        return theData.toString();
    }

    public heapIterator iterator(){
        return new heapIterator();
    }


    /**  
    * Find largest of node and its children
    */
    public void maxHeapify(int[] arr, int n,int i)                                     
    {
        
        if (i >= n) {
            return;
        }
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int max;
        if (l < n && arr[l] > arr[i]) {
            max = l;
        }
        else
            max = i;
        if (r < n && arr[r] > arr[max]) {
            max = r;
        }
          
        /**  Put maximum value at root and
        * recur for the child with the maximum value
        */
        if (max != i) {
            int temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;
            maxHeapify(arr, n, max);
        }
    }
      

    /**  Merges max heaps a[] and b[] into merged[]
    */
    public void mergeHeaps(int[] arr, int[] a,int[] b, int n, int m)         
    {
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }
        for (int i = 0; i < m; i++) {
            arr[n + i] = b[i];
        }
        n = n + m;
  
        // Builds a max heap of given arr[0..n-1]
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, n, i);
        }
    }


    /** 
    * This function removed the Kth largest element with arraylist in Max heap.
    */
    public E kthLargestElement(int k){
        E temp=null;
        ArrayList<E> arrayList = new ArrayList<>();

        if(k != 0){
            for(int i=0;i<k;i++){
                arrayList.add(poll());

            }
            
            temp = arrayList.remove(arrayList.size()-1);

            for(int i=0;i<arrayList.size();i++){
                add(arrayList.get(i));
            }
        }
        return temp;
    }
    
    /** 
    * I use the Iterator for set the element to heap structure.
    *There is set,get,remove,hasNext,next and remove method for iterator.
    */
    public class heapIterator implements Iterator<E>{
        
        
        private int current = 0;
        private int theSize = theData.size();

        public int size() {
            return theSize;
        }
        
        /**
         * This method put the new element which we determined by iterator.
         * @param newVal
         * @return old.
         */
        public E set(E newVal) {
            E old = theData.get(current);
            theData.set(current,newVal);
            return old;
        }

        /** 
        * In this method I traverse lineer all of the arraylist and put new item to determined place.
        *@return removeItem.
        *@param index which in item.
        */
        public E remove(int index) {
            E removeItem = theData.get(index);
            for (int i = index; i < size() - 1; i++) {
                theData.set(i,theData.get(i + 1));
            }
            theSize--;
            return removeItem;
        }
    
            /**
             * I move the through the ArrayList.
             * @return current
             */
            public boolean hasNext() {
                return current < size();
            }

            /**
             * * This functin can traverse end of the array.
             * @return theData.get(current++)
             */
            public E next() {
                if (!hasNext()) throw new java.util.NoSuchElementException();
                return theData.get(current++);
            }
            /**
             * I removed the item by using recursive.
             */
            public void remove() {
                heapIterator.this.remove(--current); 
            }

    }


}