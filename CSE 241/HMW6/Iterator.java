import java.util.NoSuchElementException;

public class Iterator<T> {


    /** Represents an ArrayList.
     * @author Serdil Anil Unlu
     * @author www.LoweWriter.com
     * @version 1.0
     *
     */


    Object []elements;
    int currentIndex = 0;
    int size = 0;
    Collection<T> collection;
    public Iterator(Collection<T> collection,Object[] elements){
        this.collection = collection;
        this.elements = elements;
        this.size = collection.getLimit();
    }


    /**
     * This method gets the next element of the Collection
     * @throw NoSuchElementException If there is no element
     * @return T element to be returned
     */
    T next() throws NoSuchElementException {
        if(currentIndex>=size)
            throw new NoSuchElementException();
        return (T)elements[currentIndex++];
    }



    /**
     * This method checks if there is still an element on the Collection
     * @return boolean if there is element return true else false
     */

    boolean hasNext(){
        return currentIndex<size ?true:false;
    }



    /**
     * This method removes Removes from the underlying collection the last element returned
     * by this iterator.
     * @throw NoSuchElementException If there is no element
     * @throw UnsupportedOperationException If this method is called from Queue
     * @return T element to be returned
     */
    boolean remove() throws NoSuchElementException,UnsupportedOperationException {

        if(this.collection instanceof Queue){
            throw new UnsupportedOperationException();
        }

        if(currentIndex<=0){
            throw new NoSuchElementException();
        }

        int lastIndex = --currentIndex;


        System.arraycopy(elements, lastIndex + 1, elements, lastIndex, elements.length - 1 - lastIndex);

        this.collection.setLimit(--size);
        return true;
    }



}
