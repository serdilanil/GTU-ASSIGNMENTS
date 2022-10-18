import java.util.AbstractSequentialList;
import java.util.ListIterator;
import java.util.NoSuchElementException;
import java.util.List;



public class KWLinkedList<E>{
    // Data Fields
    /** A reference to the head of the list. */
    private Node<E> head = null;
    /** A reference to the end of the list. */
    private Node<E> tail = null;
    /** The size of the list. */
    private int size = 0;
    private int j;
    
    private static class Node<E>{

        private E val;
        private Node<E> next;
        private Node<E> prev;
        public Node(E data){
            val = data;
        }
    }
    
    
    public KWLinkedList(){
        this.head = null;
        this.tail = null;
        this.size = 0;
    }


    public KWListIter listIterator(){
        return new KWListIter(0);
    }
    
    public KWListIter listIterator(int i){
        return new KWListIter(i);
    }
    
    /** Add an item at position index.
    @param index The position at which the object is to be
    inserted
    @param obj The object to be inserted
    @throws IndexOutOfBoundsException if the index is out
    of range (i < 0 || i > size())
    */
    public void add(int index, E obj) {
        listIterator(index).add(obj);
    }

    

    /** Get the element at position index.
    @param index Position of item to be retrieved
    @return The item at index
    */
    public E get(int index) {
        return listIterator(index).next();
    }


    public int size(){
        return this.size;
    }



    
    private class KWListIter implements ListIterator<E>{
        /** A reference to the next item. */
        private Node<E> nextItem;
        /** A reference to the last item returned. */
        private Node<E> lastItemReturned;
        /** The index of the current item. */
        private int index = 0;
        /** Construct a KWListIter that will reference the ith item.
        @param i The index of the item to be referenced
        */
        public KWListIter(int i) {
        // Validate i parameter.
        if (i < 0 || i > size) {
            throw new IndexOutOfBoundsException("Invalid index " + i);
        }
        lastItemReturned = null; // No item returned yet.
        // Special case of last item.
        if (i == size) {
            index = size;
            nextItem = null;
        } 
        
        else { // Start at the beginning
            nextItem = head;
            for (index = 0; index < i; index++) {
            nextItem = nextItem.next;
            }
        }
        }
        
        

        public void set(E newVAlue){
            if(lastItemReturned == null){
                throw new IllegalStateException();
            }
        
            lastItemReturned.val = newVAlue;
            
        }

        public boolean hasNext() {
            return nextItem != null;
        }
        

        /** Move the iterator forward and return the next item.
        @return The next item in the list
        @throws NoSuchElementException if there is no such object
        */
        public E next() {
            
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
                lastItemReturned = nextItem;
                nextItem = nextItem.next;
                index++;
                return lastItemReturned.val;
        }



        public boolean hasPrevious() { 
            return (nextItem == null && size != 0)
            || nextItem.prev != null;
        }
    
            
        public E previous() {
            if(!hasPrevious()){
                throw new NoSuchElementException();
            }
            
            if (nextItem == null) { // Iterator is past the last element
                nextItem = tail;
            } 
            else {
                nextItem = nextItem.prev;
            }
            
            lastItemReturned = nextItem;
            index--;
            return lastItemReturned.val;
        }
    
    
            public void add(E obj){
                
            if(head == null){ // Add to an empty list.
                head = new Node<>(obj);
                tail = head;
            } 
            
            else if(nextItem == head) 
            { // Insert at head.
                // Create a new node.
                Node<E> newNode = new Node<>(obj);
                // Link it to the nextItem.
                newNode.next = nextItem; // Step 1
                // Link nextItem to the new node.
                nextItem.prev = newNode; // 
                // The new node is now the head.
                head = newNode;
            } 
            
            else if (nextItem == null) 
            { // Insert at tail.
                // Create a new node.
                Node<E> newNode = new Node<>(obj);
                // Link the tail to the new node.
                tail.next = newNode; // 
                // Link the new node to the tail.
                newNode.prev = tail; // 
                // The new node is the new tail.
                tail = newNode;
                // 
            } 
            
            else 
            { // Insert into the middle.
                // Create a new node.
                Node<E> newNode = new Node<>(obj);
                // Link it to nextItem.prev.
                newNode.prev = nextItem.prev; // 
                nextItem.prev.next = newNode; // 
                // Link it to the nextItem.
                newNode.next = nextItem; // 
                nextItem.prev = newNode; // 
            }
                size++;
                index++;
                lastItemReturned = null;
            }   // End of method add.


            @Override
            public int nextIndex(){
                return index;
                
            }


            @Override
            public int previousIndex(){

                return index-1;
            }


            @Override
            public void remove(){
                if(lastItemReturned == null)
                    throw new NoSuchElementException();
                
                if(lastItemReturned == null)
                    throw new NoSuchElementException();

                lastItemReturned.prev.next = lastItemReturned.next;
                lastItemReturned = null;
                size = size-1;
                                    
            }
    }



    public E remove(int index){
        
        KWListIter rem;
        rem = new KWListIter(index);
        if(size==0 && index<0)
            throw new NoSuchElementException();

        E retVal;

        if(index == size-1){
            
            retVal = tail.val;
            tail = tail.prev;
            tail.next = null;
        }

        else if(index==0){
            retVal = head.val;
            rem.remove();
        }
        
        else{
            Node<E>node = head;
            for(int i=0;i<index-1;++i){
                node = node.next;
            }
            retVal = node.val;
            node.next = node.next.next;
            node.next.prev = node;
        }
        
        size--;
        return retVal;
    }

}