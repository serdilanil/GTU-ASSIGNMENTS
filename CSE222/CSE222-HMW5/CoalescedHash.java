/** Hash table implementation using open addressing. */
public class CoalescedHash<K, V> implements KWHashMap<K, V> {
    
    
    private static class Entry<K, V> {

        private K key;
        private V value;
        public Integer next;
        //private Entry<K,V>prev;

        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }
            /** Retrieves the key.
            @return The key
            */
            public K getKey() {
                return key;
            }
            /** Retrieves the value.
            @return The value
            */
            public V getValue() {
                return value;
            }
            /** Sets the value.
            @param val The new value
            @return The old value
            */
            public V setValue(V val) {
                V oldVal = value;
                value = val;
                return oldVal;
            }

    }
    
    // Insert inner class Entry<K, V> here.
    // Data Fields
    private Entry<K, V>[] table;
    private static final int START_CAPACITY = 10;


    private double LOAD_THRESHOLD = 0.75;
    private int numKeys;
    private int numDeletes;
    private final Entry<K, V> DELETED =  new Entry<>(null, null);
   
    
    
    // Constructor
    @SuppressWarnings("unchecked")
    public CoalescedHash(){
        table = new Entry[START_CAPACITY];
    }

    /**
     * Returns true/false depending on whether the hash-table is empty
    */
     public boolean isEmpty() {
        return numKeys == 0;
    }


    /**
     *  Returns the number of keys currently inside the hash-table.
     */ 
    public int size() {
        return numKeys;
    }
    
    /**
     * In this method calculate the starting index an Increment index until an empty slot 
     * or the key is found
     * @param key
     */
    private int find(Object key) {
        // Calculate the starting index.
        int index = key.hashCode() % table.length;
        if (index < 0)
        index += table.length;
        // Make it positive.
        // Increment index until an empty slot is reached
        // or the key is found.
        while ((table[index] != null)
        && (!key.equals(table[index].getKey()))) {
        index++;
        // Check for wraparound.
        if (index >= table.length)
        index = 0;
        // Wrap around.
        }
        return index;
        }

    /**
     * Find the first table element that is empty
     * or contains the key which the table element.
     * @param key
     */
    @Override
    public V get(Object key) {
    // Find the first table element that is empty
    // or the table element that contains the key.
    int index = find(key);
    // If the search is successful, return the value.
    if (table[index] != null)
        return table[index].getValue();
    else
        return null; // key not found.
    }


    /**
     * In this method add value to the available key,
     * if loadFactor bigger than Threshold I use rehash()
     * also, I use quadratic probing.
     * @param key,value
     */
    public V put(K key, V value){
        int index = key.hashCode() % table.length;
        int probe = 1;
    
    
        if(table[index] == null){
            table[index] = new Entry<>(key,value);
            numKeys++;
            double loadFactor = (double) (numKeys + numDeletes) / table.length;

            if (loadFactor > LOAD_THRESHOLD)
                rehash();

            return null;
        }
    
        int nextIndex = index;
        
        while(table[nextIndex] != null && table[nextIndex].next != null){
        
            if(table[nextIndex].key.equals(key)){
                return table[nextIndex].setValue(value);
            }
            
            if(probe > table.length){
                return null;
            }
            System.out.println(table[nextIndex].next.intValue());
            nextIndex = table[nextIndex].next.intValue();
            probe++;
            
            
        } 
        
        while(table[nextIndex] != null){
            nextIndex = (index+(probe*probe) % table.length);
            probe++;
        }
        
        table[nextIndex] = new Entry<K, V>(key, value);


        numKeys++;
        double loadFactor = (double) (numKeys + numDeletes) / table.length;
        if (loadFactor > LOAD_THRESHOLD)
            rehash();
        return value;
    }
    
    /**
     * this method printed the ordered shape index, key and next.
     */
    public String toString(){

        StringBuilder temp = new StringBuilder();
        temp.append("index  key     next   \n ");
        for(int i=0;i<table.length;i++){
            temp.append("  " + i).append("\t");    
        
            if(table[i] == null){
                temp.append("null").append("\tnull\n");

            }
            else{
                temp.append(table[i].getKey()).append("\t").append(table[i].next).append("\n");
            }
        
        }
        return temp.toString();
    }

    /**
     * This method extend the table also save the old table
     */
    @SuppressWarnings("unchecked")
    private void rehash() {
        // Save a reference to oldTable.
        Entry<K, V>[] oldTable = table;
        // Double capacity of this table.
        table = new Entry[2 * oldTable.length + 1];
        // Reinsert all items in oldTable into expanded table.
        numKeys = 0;
        numDeletes = 0;
        for (int i = 0; i < oldTable.length; i++) {
            if ((oldTable[i] != null) && (oldTable[i] != DELETED)) {
            // Insert entry in expanded table
                put(oldTable[i].getKey(), oldTable[i].getValue());
            }
        }
    }

    public V remove(Object key) {
        /*Entry<K,V> tab[] = table;
        int hash = key.hashCode();
        int index = hashCode() % tab.length;
        Entry<K,V> e = (Entry<K,V>)tab[index];
        
        for(Entry<K,V> prev = null ; e != null ; prev = e, e = e.next) {
            if ((e.hashCode() == hash) && e.key.equals(key)) {
                if (prev != null) {
                    prev.next = e.next;
                } 
                else {
                    tab[index] = e.next;
                }
                
                numKeys--;
                V oldValue = e.value;
                e.value = null;
                return oldValue;
            }
        }*/
        return null;
    }

}