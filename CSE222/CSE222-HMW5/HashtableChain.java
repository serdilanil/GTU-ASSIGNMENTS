import java.util.*;

/**
* In this class we use the chaining technique for hashing by using linked lists.
*/
public class HashtableChain<K, V> implements KWHashMap<K, V> {
    // Insert inner class Entry<K, V> here.
    /** The table */
    private LinkedList<Entry<K, V>>[] table;
    /** The number of keys */
    private int numKeys;
    /** The capacity */
    private static final int CAPACITY = 10;
    /** The maximum load factor */
    private static final double LOAD_THRESHOLD = 3.0;
    // Constructor
    
    
    /** Contains key-value pairs for a hash table. */
    private static class Entry<K, V> implements Map.Entry<K, V> {

        /** The key */
        private K key;
        /** The value */
        private V value;

        /**
         * Creates a new key-value pair.
         * @param key The key
         * @param value The value
         */
        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }

        /**
         * Retrieves the key.
         * @return The key
         */
        @Override
        public K getKey() {
            return key;
        }

        /**
         * Retrieves the value.
         * @return The value
         */
        @Override
        public V getValue() {
            return value;
        }

        /**
         * Sets the value.
         * @param val The new value
         * @return The old value
         */
        @Override
        public V setValue(V val) {
            V oldVal = value;
            value = val;
            return oldVal;
        }
        
        /**
         * Returns a string representation of the Entry.
         * @return The string in format "key=value"
         
        public String toString() {
            return key + "=" + value;
        }*/

    
    
    }
    
    /**
     * Constructor
     */
    @SuppressWarnings("unchecked")
    public HashtableChain() {
        table = new LinkedList[CAPACITY];
    }


    @Override
    public V get(Object key) {
    int index = key.hashCode() % table.length;
    
    if (index < 0)
    index += table.length;
    
    if (table[index] == null)
    return null; // key is not in the table.
    // Search the list at table[index] to find the key.
    for (Entry<K, V> nextItem : table[index]) {
        if (nextItem.getKey().equals(key))
        return nextItem.getValue();
    }
    
    // assert: key is not in the table.
        return null;
    }

    @SuppressWarnings("unchecked")
    private void rehash() {
        LinkedList<Entry<K,V>>[] oldTable = table;
        table = new LinkedList[oldTable.length * 2 + 1];
        numKeys = 0;
        for (LinkedList<Entry<K, V>> list : oldTable) {
            if (list != null) {
                for (Entry<K,V> entry : list) {
                    put(entry.getKey(), entry.getValue());
                    numKeys++;
                }
            }
        }
    }

    /**
     * In this method, searched list if finded available place, this method add value to key,
     * and if key is not in the table, add new item.
     */
    @Override
    public V put(K key, V value) {
        int index = key.hashCode() % table.length;
        
        if (index < 0)
            index += table.length;
        
        if (table[index] == null) {
            // Create a new linked list at table[index].
            table[index] = new LinkedList<>();
        }
        
        // Search the list at table[index] to find the key.
        for (Entry<K, V> nextItem : table[index]) {
            // If the search is successful, replace the old value.
            if (nextItem.getKey().equals(key)) {
                // Replace value for this key.
                V oldVal = nextItem.getValue();
                nextItem.setValue(value);
                return oldVal;
            }
        }
        // assert: key is not in the table, add new item.
        table[index].addFirst(new Entry<>(key, value));
        numKeys++;
        if (numKeys > (LOAD_THRESHOLD * table.length))
        rehash();
        return null;
    }


    /** Returns true if empty */
    public boolean isEmpty() {
        return numKeys == 0;
    }

    /**
     * return number of keys.
     */
    @Override
    public int size() {
        return numKeys;
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
                temp.append(table[i].get(0).key).append("\t").append(table[i].get(0).value).append("\n");
            }
        
        }
        return temp.toString();
    }

    /**
     * This method remove the determined key in the table.
     * if key is not in the table it would returned null.
     */
    @Override
    public V remove(Object key) {
        int index = key.hashCode() % table.length;
        
        if (index < 0) {
            index += table.length;
        }
        
        if (table[index] == null) {
            return null; // key is not in table
        }
        
        for (Entry<K, V> entry : table[index]) {
            if (entry.getKey().equals(key)) {
                V value = entry.getValue();
                table[index].remove(entry);
                numKeys--;
                if (table[index].isEmpty()) {
                    table[index] = null;
                }
                return value;
            }
        }
        return null;
    }



}