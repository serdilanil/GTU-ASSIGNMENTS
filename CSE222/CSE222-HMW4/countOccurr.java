/**
 * 
 * @param <E>
 */
public class countOccurr<E extends Comparable<E>> implements Comparable<countOccurr<E>>{

    private E value;
    private int occurr;

    /**
     * Constructor
     * @param val
     */
    public countOccurr(E val){

        this.value = val;
        this.occurr = 1;
    }
    /**
     * Constructor
     * @param val
     * @param o
     */
    public countOccurr(E val,int o){

        this.value = val;
        this.occurr = o;
    }

    /**
     *Return the value of item.
     * @return value.
     */
   public E getValue(){
       return value;
   }

    /**
     * Return the number of occurrence
     * @return occurrence
     */
    public int getOccur(){
        return occurr;
    }

    /**
     * Return the increased occurrence
     * @return increased occurrence
     */
    public int incOccurr(){

        return ++occurr;

    }

    /**
     * Return decreased occurrence
     * @return decreased occurrence
     */
    public int decOccurr(){

        return --occurr;

    }

   /**
    * Return compareTo method for comparing value.
    * @return compareTo method for comparing value.
    */
    public int compareTo(countOccurr<E> o){
        
        return this.value.compareTo(o.getValue());
    }



    @Override
    public String toString(){
        return value+ "," + occurr;
    }

}