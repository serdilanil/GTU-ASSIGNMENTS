import java.util.Iterator;

/**
 * In this class I use the Max heap for Binary Search Tree.
 * @param <E>
 */
public class BSTHeapTree<E extends Comparable<E>>{
    
    E prev = null;
    int count = 1;
    int max = 0;

    private BinarySearchTree<MaxHeapStructure<countOccurr<E>>> theData;
    
    
    private int occurr;

    /**
     * Constructor
     */
    public BSTHeapTree(){
        theData = new BinarySearchTree<>();
    }

    /**
     * Returns the number of occurrences of the item after insertion
     * Also if I add the item  I increased occurrence of the this item.
     * if it doesn't exist I consist item and give 1 occurrence
     * @param item
     * @param localRoot
     * @return localRoot
     */
    private BinaryTree.Node<MaxHeapStructure<countOccurr<E>>> add(E item,BinaryTree.Node<MaxHeapStructure<countOccurr<E>>> localRoot){
        
        if(localRoot == null){
            localRoot = new BinaryTree.Node<>(new MaxHeapStructure<>(new countOccurr<>(item)));
            occurr = localRoot.data.peek().getOccur();
            return localRoot;
        }
        
        else if(localRoot.data.size() < 7){
            countOccurr<E> temp = localRoot.data.find(new countOccurr<>(item));
            
            if(temp != null){
                occurr = temp.incOccurr();
            } 

            else{
                localRoot.data.add(new countOccurr<>(item));
                occurr = 1;
            }
            
            
        }

        else if(localRoot.data.size() == 7){
            countOccurr<E> temp = localRoot.data.find(new countOccurr<>(item));
            
            if(temp != null){
                occurr = temp.incOccurr();
            } 

            else{

                if(localRoot.data.peek().compareTo(new countOccurr<>(item)) > 0){
                    localRoot.left = add(item,localRoot.left);

                }
                
                else{
                    localRoot.right = add(item,localRoot.right);
                }
            
            }

        }

        return localRoot;
    
    }

    /**
     * I call the add method and I apply recursive
     * @param item
     * @return occurrence of item.
     */
    public int add (E item){

        theData.root = add(item,theData.root);

        return occurr;
            
    }

    /**
     * I searched the data by using recursive.
     * @param target
     * @return finding data
     */
    public int find(E target) {
        return find(theData.root,target);
    }
    
    /**
     * Returns the number of occurrences of the item in the BSTHeapTree
     * @param localRoot
     * @param target
     * @return number and number occurrences.
     */
    private int find( BinaryTree.Node<MaxHeapStructure<countOccurr<E>>> localRoot, E target){//return 0. localRoot=0
        if (localRoot == null)
            return 0;
          
    
        countOccurr<E> temp = localRoot.data.find(new countOccurr<>(target));
        if (temp != null){
          return temp.getOccur();
        }
          
        else if (target.compareTo(localRoot.data.peek().getValue())< 0){
            return find(localRoot.left, target);
        }
        
        else
            return find(localRoot.right, target);
    }

    @Override
    public String toString(){
        return theData.toString();
    }


    /**
     * I traverse all of the binary search item and I find the most repetitive number.
     * @param localRoot
     * @param mode
     * @return Mode of the Binary Search Tree.
     */
    @SuppressWarnings("unchecked")
    private countOccurr<E> find_mode(BinaryTree.Node<MaxHeapStructure<countOccurr<E>>> localRoot, countOccurr<E> mode) {
        
        if (localRoot == null) {
            return new countOccurr<>(null,0);
        }
        else {
            countOccurr<E> temp;
            countOccurr<E> theOneToCompare = localRoot.data.peek();
            Iterator<E> iter = (Iterator<E>) localRoot.data.iterator(); 
            
            while(iter.hasNext()){
                temp = (countOccurr<E>) iter.next();
                if(temp.getOccur() > theOneToCompare.getOccur()){
                    theOneToCompare = temp;
                    
                }
            }
            
            countOccurr<E> left = find_mode(localRoot.left, mode);
            countOccurr<E> right = find_mode(localRoot.right, mode);
            mode = theOneToCompare;

            if(mode.getOccur() < left.getOccur()){
                mode = left;
            }
            if(mode.getOccur() < right.getOccur()){
                mode = right;
            }
            
            
            return mode;
        }
    }

    /**
     * I find the mode by using recursive.
     * @return mode of Binary Search Tree.
     */
    public E find_mode(){
        //System.out.println(find_mode(theData.root,new countOccurr<>(null,0)).getOccur());
        return find_mode(theData.root,new countOccurr<>(null,0)).getValue();
    
    }

    /**
     * I take the minimum element When I removed item which up the minimum element 
     * And I replace to removed item.
     * @param localRoot
     * @return minimum element of Binary Search Tree.
     */
    public countOccurr<E> minimumElement(BinaryTree.Node<MaxHeapStructure<countOccurr<E>>> localRoot){
        if(localRoot.left == null){
            return localRoot.data.kthLargestElement(localRoot.data.size());
        }
        
        else{
            return minimumElement(localRoot.left);
        }
        
    }

    /**
     * I remove item which determined and if the number doesn't exist I put the lowest number in its place.
     * And otherwise I return number and it's new occurrence.
     * @param item
     * @param localRoot
     * @return Removed item and it's occurrence
     */
    private BinaryTree.Node<MaxHeapStructure<countOccurr<E>>> remove(E item,BinaryTree.Node<MaxHeapStructure<countOccurr<E>>> localRoot){
        
        if(localRoot == null){
            occurr = 0;
            return localRoot;
        }
        
        
            countOccurr<E> temp = localRoot.data.find(new countOccurr<>(item));
            
            if(temp == null){
                int comp;  
                    try
                    {
                        comp = item.compareTo(localRoot.data.peek().getValue()); 
                    }catch (IllegalStateException e){
                        comp=1;
                    }
                    
                    if(comp < 0){
                        localRoot.left = remove(item, localRoot.left);
                        return localRoot;
                    }
                    
                    else{
                        localRoot.right = remove(item, localRoot.right);
                        return localRoot;
                    }
                
            }
            
            else{

                if(temp.getOccur() == 1){
                    
                    localRoot.data.remove(temp);
                    countOccurr<E> min = minimumElement(localRoot);
                    
                    if(min != null){
                        localRoot.data.add(min);
                        occurr = 0;
                    } 
                }
            
                else{
                    occurr = temp.decOccurr();
                }
            }
            
            if(localRoot.data.size() == 1){
                
                theData.remove(localRoot.data);
            }
            
            
        return localRoot;
        
    }
    /**
     * @param item
     * @return new occurrence of item.
     */
    public int remove (E item){

        theData.root = remove(item,theData.root);

        return occurr;
            
    }

    
}


