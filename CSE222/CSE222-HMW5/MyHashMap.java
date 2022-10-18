import java.util.HashMap;

/**
 * In this class I extend the HashMap
 * And I create the MapIterator class as a inner class.
 */
public class MyHashMap<K,V> extends HashMap<K,V>{
  
    /**
     * Iterate with zero constructor.
     */
    public MapIterator iterator(){
        return new MapIterator();

    }

    /**
     * Iterate with constructor.
     */
    public MapIterator iterator(K key){
        return new MapIterator(key);

    }


    /**
     * In this class I use HashMap library in java.
     */
    public class MapIterator{

        @SuppressWarnings("unchecked")
        private K[] Kvalue = (K[]) keySet().toArray(); 
        private int counter;
        private int index;
        private int start;
        
        /**
         * this method returns True if there are still not-iterated key/s in the Map, otherwise returns False.
         * @return boolean
         */
        public boolean hasNext() {
            return counter != Kvalue.length;
        }

        /**
         * 
         * @return start
         */
        public int getStart() {
            return start;
        }

        public void setStart(int start) {
            this.start = start;
        }

        //zero constructor
        public MapIterator(){
            counter = 0;
            index = -1;
            setStart(counter);
        }
        //constructor
        public MapIterator(K key){
            counter = 0;
            index = getIndex(key);
            setStart(getIndex(key));
        
        }

        /**
         * This metod compare the key and index.
         * @param key
         */
        private int getIndex(K key){

            for(int i=0;i<Kvalue.length;i++){
                if(Kvalue[i].equals(key))
                    return i;
            }
        
            return -1;
        }

        /**
         * This method returns the next key in the Map. It returns the first key when there is no
         * not-iterated key in the Map.
         * @return K.
         */
        public K next(){
            
            if(!hasNext()){
                index = counter;
                counter = 0; //Burada counter = 0 dı.
            }
            
            else{
                index = (index +1) % Kvalue.length;
                counter++;
            }
            
            return Kvalue[index];
            
        }
    
        /**
         * This method points to the previous key.
         * @return K
         */
        public K prev(){
         
        index = (index - 1 + Kvalue.length) % Kvalue.length;
        counter++;

        
        return Kvalue[index]; 
        }

    
    }

    
}