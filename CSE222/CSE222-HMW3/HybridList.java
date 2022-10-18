import java.util.AbstractList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.AbstractSequentialList;
import java.util.ArrayList;
import java.util.ListIterator;
import java.util.NoSuchElementException;
import java.util.List;

/*
*In this class I keep a LinkedList as a component
*and the elements stored in the LinkedListare Arraylists.
*/


public class HybridList<E>{

    KWLinkedList<KWArrayList<E>>storage= new KWLinkedList<KWArrayList<E>>();
    int MAX_NUMBER=10;
    int size = 0;
    
    /*
    *add the end of the linkArray.
    */
    public void add(E obj){
        
        
        if(size==0){
            storage.add(size/MAX_NUMBER,new KWArrayList<E>());
        }


        ListIterator<KWArrayList<E>> linkArray =storage.listIterator();
        KWArrayList<E> temp = linkArray.next();
        
    

        while(linkArray.hasNext()){
            temp = linkArray.next();
        }
        /*
        *The number of elements in each ArrayList should be less than MAX_NUMBER. 
        */
        if(MAX_NUMBER == temp.size()){
            storage.add(size/MAX_NUMBER,new KWArrayList<E>());
        
            linkArray = storage.listIterator();
            temp = linkArray.next();
            
            while(linkArray.hasNext()){
                temp = linkArray.next();
            }
            
        }
    
        temp.add(obj);
        size++;
    }


    public E get(int index) {
        
        int x,y;

        x = index / MAX_NUMBER;
        y = index % MAX_NUMBER;
        
        ListIterator<KWArrayList<E>> linkArray =storage.listIterator();
        KWArrayList<E> temp = linkArray.next();

        
        if (index < 0 || index >= size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        
        for(int i=0;i<x;i++){
            temp = linkArray.next();
            
        }
        
        return temp.get(y);
    }
        

    public E set(int index, E newValue) {
        
        int x,y;

        x = index / MAX_NUMBER;
        y = index % MAX_NUMBER;
        
        ListIterator<KWArrayList<E>> linkArray =storage.listIterator();
        KWArrayList<E> temp = linkArray.next();

        
        if (index < 0 || index >= size) {
            throw new ArrayIndexOutOfBoundsException(index);
        }
        
        for(int i=0;i<x;i++){
            temp = linkArray.next();
            
        }

        return temp.set(y,newValue);
    }
   

}