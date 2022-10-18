import java.util.ArrayList;
import java.util.Iterator;
import java.util.Stack;

/**
 * In this class, I implement the NavigableSet interface by using Skip List.
 */
public class navigableSkipList<E extends Comparable <E>>{
    
    private SkipList<E> data = new SkipList<>();

    /**
     * I insert the elements.
     */
    public boolean add(E item){

        for(E element:data){
            if(element.compareTo(item) == 0){
                return false;
            }
        }
        
        data.add(item);
        return true;
    }

    /**
     * I delete the elements.
     */
    public E remove(E item){

        return data.remove(item);
    }

    public String toString(){

        return data.toString();
    }
    
    /**
     * I descend the elements by using iterator in Skip List. 
     */
    public Iterator<E> descendingIterator(){
        Stack<E> stack = new Stack<>();
        ArrayList<E> descending = new ArrayList<>(); 
        for(E element:data){
            stack.push(element);

        }

        while(!stack.isEmpty()){
            descending.add(stack.pop());
        }
        
        return descending.iterator();
    }
    
    


}


