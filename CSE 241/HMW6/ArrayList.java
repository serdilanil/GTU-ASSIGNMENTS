
public class ArrayList<T> implements List<T> {


    /** Represents an ArrayList.
     * @author Serdil Anil Unlu
     * @author www.LoweWriter.com
     * @version 1.0
     *
     */

    protected Object []elements;
    protected Integer limit;


    /**
     * Set the limit of the elements existing on this Collection.
     * @param limit Collection's limit to be set
     */

    @Override
    public void setLimit(Integer limit){this.limit = limit;}

    /**
     * Gets the limit of the elements existing on this Collection.
     * @return Integer Collection's current limit
     */
    @Override
    public Integer getLimit(){return limit;}

    /**
     * This method inserts an element to specified index
     * @param elem  Element to be inserted
     * @param indexAt  Index of the element
     */
    @Override
    public void insertAt(T elem,int indexAt){
        System.arraycopy(elements, indexAt , elements, indexAt+1, elements.length - 1- indexAt);
        elements[indexAt] = elem;
        setLimit(limit+1);
    }


    /**
     * This method adds an element to the Collection
     * If there is no space left, it allocates a larger array
     * @param elem  Element to be added
     */
    @Override
    public void add(T elem){

        if(elements.length==limit) {
            Object[] temp = new Object[elements.length+100];

            for(int i = 0;i<elements.length;++i)
                temp[i] = elements[i];

            elements = temp;
        }
            this.elements[limit] = elem;
            this.limit++;
    }


    /**
     * Default Constructor
     */
    public ArrayList() {
        this.elements = new Object[100];
        this.limit = 0;


    }

    /**
     * Constructor with a specified size
     * @param size array size to initialize
     */
    public ArrayList(int size) {
        this.elements = new Object[size];
        this.limit = 0;

    }

    /**
     * Copy Constructor, copies the elements from other Collection
     * @param other , Collection to be copied from
     */
    public ArrayList(ArrayList<T> other) {
        int otherSize = other.size()>100?other.size():100;
        this.elements = new Object[otherSize];
        Iterator otherIt = other.iterator();
        while(otherIt.hasNext())
            this.add((T)otherIt.next());


    }


    /**
     * returns an Iterator for the Collection
     */
    @Override
    public Iterator iterator(){
        return new Iterator(this,this.elements);
    }

    /**
     * Adds all the elements from other Collection to current Collection
     * @param other other Collection to be copied from
     *
     */
    @Override
    public void addAll(Collection<T> other){
        Iterator it = other.iterator();
        while(it.hasNext())
            this.add((T)it.next());

    }

    /**
     * Clears all the elements on this Collection
     *
     */
    @Override
    public void clear(){
        elements = null;
        elements = new Object[100];
        limit = 0;
    }


    /**
     * Checks if a specified element exists on this Collection
     * @param elem element to be checked
     * @return boolean  if contains returns true. if not, false
     */
    @Override
    public boolean contains(T elem){

        for(int count = 0;count<limit;++count) {
            if (elements[count]!=null && elements[count].equals(elem))
                return true;
        }
        return false;
    }


    /**
     * Checks if all the elements of other Collection exist on this Collection
     * @param other Collection to be checked
     * @return boolean if all elements exist returns true. if not, false
     */

    @Override
    public boolean containsAll(Collection<T> other){
        if(other.size()>this.size())
            return false;

        Iterator otherIt = other.iterator();

        while(otherIt.hasNext()){
            if(!this.contains((T)otherIt.next()))
                return false;
        }

        return true;
    }
    /**
     * Checks if this Collection empty
     * @return boolean returns true if the Collection is empty. If not, false
     */
    @Override
    public boolean isEmpty(){
        return limit==0?true:false;
    }


    /**
     * removes a specified element from the Collection
     * @param elem element to be checked
     */

    @Override
    public boolean remove(T elem){

        for(int foundIndex = 0; foundIndex<limit; foundIndex++) {
            if (elements[foundIndex] != null && elements[foundIndex].equals(elem)) {
                System.arraycopy(elements, foundIndex + 1, elements, foundIndex, elements.length - 1 - foundIndex);
                limit--;
                return true;
            }
        }
        return false;


    }

    /**
     * removes all elements of another Collection from this Collection
     * @param other Collection whose elements will be removed
     */
    @Override
    public void removeAll(Collection<T> other) {

        Object[] temp = new Object[elements.length];
        int tempIndex = 0;

        Iterator thisIt = this.iterator();

        while (thisIt.hasNext()) {
            T elem = (T)thisIt.next();
            if (!other.contains(elem)) {
                System.out.println("added in removed = "+elem);
                temp[tempIndex++] = elem;

            }
        }

        this.elements = temp;
        this.limit = tempIndex;
    }



    /**
     * retains all elements of this Collection which also exists other Collection
     * @param other Collection whose elements will be checked for equality
     */
    @Override
    public void retainAll(Collection<T> other){

        Object[] temp = new Object[elements.length];
        int tempIndex = 0;

        Iterator thisIt = this.iterator();

        while (thisIt.hasNext()) {
            T elem = (T)thisIt.next();
            if (other.contains(elem)) {
                System.out.println("added in retained = "+elem);
                temp[tempIndex++] = elem;

            }
        }

        this.elements = temp;
        this.limit = tempIndex;
    }

    /**
     * returns the number of the elements on this Collection
     * @return Integer number of elements on this Collection
     */
    @Override
    public Integer size(){
        return limit;
    }


}
