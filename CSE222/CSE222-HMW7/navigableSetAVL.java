import java.util.ArrayList;
import java.util.Iterator;
/**
 * In this class, I implements of NavigableSet interface using Avl Tree.
 */
public class navigableSetAVL <E extends Comparable<E>>{

    private AVLTree<E> value = new AVLTree<>();
    
    /**
     * Inserting element in NavigableSet interface.
     * @param item
     */
    public boolean insert(E item){

        if(item != null)
            return value.add(item);

        return false;
    }

    /**
     * I traverse the AVL tree for print the element in the tree on the screen.
     * @param value
     */
    public void printInorder(BinaryTree.Node<E> value){

        if (value == null)
            return;
 
        /* first recur on left child */
        printInorder(value.left);
 
        /* then print the data of value */
        System.out.print(value.data + " ");
 
        /* now recur on right child */
        printInorder(value.right);

    }

    public void printInorder(){

        printInorder(value.root);
    }


    public String toString(){

        return value.toString();
    }


    /**
     * Iterating the elements.
     */
    public AvlIterator iterator(){

       return new AvlIterator();
    }

    /**
     * In this method, I record the array elements in the tree.
     * @param node
     */
    private void itrArray(BinaryTree.Node<E> node){
        
        if(node == null){
            return;
        }

        itrArray(node.left);

        arr2.add(node.data);
        itrArray(node.right);
        
    }
   

    ArrayList<E> arr2 = new ArrayList<>();
    /**
     * In this method, I make the headSet in the array by Avl Tree elements.
     * @param headElement
     * @return temp array
     */
    public ArrayList<E> headSet(E headElement){
        
        itrArray(value.root);
        ArrayList<E> temp = new ArrayList<>();

        for(int i = 0;i<arr2.size();i++){
            
            if(headElement.compareTo(arr2.get(i)) > 0){
                temp.add(arr2.get(i));
            }
        }
    
            return temp;
    }


    
    /**
     * In this method, I make the tailSet in the array by Avl Tree elements.
     * @param tailElement
     * @return temp2 array.
     */
    public ArrayList<E> tailSet(E tailElement){
        
        itrArray(value.root);
        ArrayList<E> temp2 = new ArrayList<>();

        for(int i = 0;i<arr2.size();i++){
            
            if(tailElement.compareTo(arr2.get(i)) <= 0){
                temp2.add(arr2.get(i));
            }
        }
    
            return temp2;
    }



    /**
     * In this class, I iterate the elements in the Avl tree.
     */
    public class AvlIterator implements Iterator<E>{
        
        int current =0;

        int last = -1;


        ArrayList<E> arr = new ArrayList<>();

        AvlIterator(){
            
            itrArray(value.root);
            
            
        }
        
        /**
         * ı record to the array ,elements in the Avl tree.
         * @param node
         */
        private void itrArray(BinaryTree.Node<E> node){
        
            if(node == null){
                return;
            }
    
            itrArray(node.left);
    
            arr.add(node.data);
            itrArray(node.right);
    
            
        }
    

        @Override
        public boolean hasNext() {
            return arr.size() != current;
            
        }




        @Override
        public E next() {
            
            current++;
           return arr.get(++last);
        }
    }

}