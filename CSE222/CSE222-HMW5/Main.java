import java.util.ArrayList;
import java.util.Random;

public class Main{

    public static void main(String[] args) {
        
        MyHashMap<Integer, String> hashmap = new MyHashMap<>();
        
        
        System.out.println("********** PART1 ************");
        System.out.println();
        
        hashmap.put(11,"Value1");
        hashmap.put(22,"Value2");
        hashmap.put(33,"Value3");
        hashmap.put(44,"Value4");
        hashmap.put(66,"Value5");
        hashmap.put(53,"Value6");
        hashmap.put(523,"Value7");
        hashmap.put(51,"Value8");
        hashmap.put(57,"Value9");
        hashmap.put(76,"Value9");
        hashmap.put(83,"Value9");

        System.out.println("********* Next() method testing *********");
        System.out.println();
        System.out.println("The keys and values are: " + hashmap);
        System.out.println();
        
        MyHashMap<Integer,String>.MapIterator iter = hashmap.iterator();
        
        System.out.println("Next(): " + iter.next());
        System.out.println("Next(): " + iter.next());
        System.out.println("Next(): " + iter.next());
        System.out.println("Next(): " + iter.next());
        System.out.println("Next(): " + iter.next());
        System.out.println();
        System.out.println("******** Next() method with hasNext() method testing : *********");
        System.out.println();
        System.out.println("The keys and values are: " + hashmap);

        MyHashMap<Integer,String>.MapIterator iterat = hashmap.iterator();

        while(iterat.hasNext()){
            System.out.println(iterat.next());
        }

        
        

        MyHashMap<Integer,String>.MapIterator it = hashmap.iterator();

        MyHashMap<Integer,String>.MapIterator itr = hashmap.iterator(66);
        System.out.println();   
        System.out.println("********** prev() method testing **********");
        System.out.println("I started the prev() method from number 66:");
        System.out.println();
        System.out.println("Keys and Values are in Map : "+hashmap);
        System.out.println("prev() for 66: "+itr.prev());
        System.out.println("prev() for 33: "+itr.prev());
        System.out.println("prev() for 76: "+itr.prev());
        System.out.println("prev() for 44: "+itr.prev());
        System.out.println("prev() for 523:"+itr.prev());
        System.out.println("prev() for 11: "+itr.prev());
        System.out.println("prev() for 57: "+itr.prev());

        

        MyHashMap<Integer,String>.MapIterator itr2 = hashmap.iterator(33);
        System.out.println();

        System.out.println("************* MapIterator Testing: ***********");

        while(itr2.hasNext()){
            System.out.println("Constructor: "+ itr2.next());
        }
        System.out.println();

        while(it.hasNext()){
            System.out.println("Zero constructor iterator: "+ it.next());
        }
        


        System.out.println();
        System.out.println();
        System.out.println("////////////////////////////////////////////");
        System.out.println();
        System.out.println("*************** PART2 *****************");
        System.out.println();

        HashtableChain<Integer,String> tableChain = new HashtableChain<>();
        System.out.println("********* testing put() method in chaining technique for hashing by using linked lists **********");
        long calculate3 = System.nanoTime();
        tableChain.put(0,"a");
        tableChain.put(1,"b");
        tableChain.put(2,"c");
        tableChain.put(3,"d");
        tableChain.put(4,"e");
        tableChain.put(5,"f");
        tableChain.put(6,"g");
        tableChain.put(7,"h");
        tableChain.put(8,"k");
        tableChain.put(9,"m");
        
        long calculate4 = System.nanoTime();
        System.out.println();
        System.out.println("********* After put the key,value: ***********");
        System.out.println(tableChain);
        System.out.println("The time taken for put method for hashing by using linked list for small size: "+(calculate4-calculate3)+" nanosecond");
        


        System.out.println();
        System.out.println("********* After using remove() method: *********");
        long calculate5 = System.nanoTime();
        tableChain.remove(1);
        tableChain.remove(2);
        tableChain.remove(5);
        tableChain.remove(9);
        long calculate6 = System.nanoTime();
        System.out.println(tableChain);
        System.out.println("The time taken for remove() method for hashing linked list for small size: "+(calculate6-calculate5)+" nanosecond");
        System.out.println();


        Random random = new Random();
        ArrayList<Integer> array = new ArrayList<Integer>();
        long calculator1 = System.nanoTime();
        for(int i=0;i<50;i++){
            array.add(random.nextInt(5000)+1);
            tableChain.remove(array.get(i));
        }
        long calculator2 = System.nanoTime();
        System.out.println();
        System.out.println("The taken for the hashing by using linked list for remove method for Medium size : "+(calculator2-calculator1)+" nanosecond");



        Random random2 = new Random();
        ArrayList<Integer> array2 = new ArrayList<Integer>();
        long calculator3 = System.nanoTime();
        for(int i=0;i<100;i++){
            array2.add(random2.nextInt(5000)+1);
            tableChain.remove(array2.get(i));
        }
        long calculator4 = System.nanoTime();
        System.out.println();
        System.out.println("The taken for the hashing by using linked list for remove method for Large size : "+(calculator4-calculator3)+" nanosecond");






        System.out.println();

        Random rand2 = new Random();
        ArrayList<Integer> arr2 = new ArrayList<Integer>();
        long calculate15 = System.nanoTime();
        for(int i=0;i<100;i++){
            arr2.add(rand2.nextInt(5000)+1);
            tableChain.put(arr2.get(i),"a");
        }
        long calculate16 = System.nanoTime();
        System.out.println();
        System.out.println("The taken for the hashing by using linked list for put method for Medium size : "+(calculate16-calculate15)+" nanosecond");





        Random rand3 = new Random();
        ArrayList<Integer> arr3 = new ArrayList<Integer>();
        long calculate17 = System.nanoTime();
        for(int i=0;i<1000;i++){
            arr3.add(rand3.nextInt(5000)+1);
            tableChain.put(arr3.get(i),"a");
        }
        long calculate18 = System.nanoTime();
        System.out.println();
        System.out.println("The taken for the hashing by using linked list for put method for Large size : "+(calculate18-calculate17)+" nanosecond");


        System.out.println();



        System.out.println("//////////////////////////////////////////////////////////////////////");
        System.out.println();
        
        
        //////////////////////////////////////////////////////////////////////////////////////////
        
        
        HashtableChainTreeSet<Integer,String> hashtableChainTreeSet = new HashtableChainTreeSet<>();
        long calculate = System.nanoTime();



        System.out.println("********* testing put() method in chaining technique for hashing by using TreeSet **********");
        System.out.println();
    
        hashtableChainTreeSet.put(0,"a");
        hashtableChainTreeSet.put(1,"b");
        hashtableChainTreeSet.put(2,"c");
        hashtableChainTreeSet.put(3,"d");
        hashtableChainTreeSet.put(4,"e");
        hashtableChainTreeSet.put(5,"f");
        hashtableChainTreeSet.put(6,"g");
        hashtableChainTreeSet.put(7,"h");
        hashtableChainTreeSet.put(8,"k");
        hashtableChainTreeSet.put(9,"m");
        
        System.out.println("********* After using put method for TreeSet: ");
        System.out.println();
        System.out.println(hashtableChainTreeSet);
        System.out.println();
        long calculate2 = System.nanoTime();
        System.out.println("The time taken for the hashing by using TreeSet for put() method for small size: "+ (calculate2-calculate)+" nanosecond");
        System.out.println();




        System.out.println();
        System.out.println("After using remove method for TreeSet:");
        System.out.println();
        long calculate7 = System.nanoTime();
        hashtableChainTreeSet.remove(1);
        hashtableChainTreeSet.remove(2);
        hashtableChainTreeSet.remove(5);
        hashtableChainTreeSet.remove(9);
        long calculate8 = System.nanoTime();
        System.out.println(hashtableChainTreeSet);
        System.out.println("The time taken for remove method for hashing TreeSet for small size: "+(calculate8-calculate7)+" nanosecond");
        System.out.println();


        Random random3 = new Random();
        ArrayList<Integer> array3 = new ArrayList<Integer>();
        long calculator5 = System.nanoTime();
        for(int i=0;i<50;i++){
            array3.add(random3.nextInt(5000)+1);
            hashtableChainTreeSet.remove(array3.get(i));
        }
        long calculator6 = System.nanoTime();
        System.out.println();
        System.out.println("The taken for the hashing by using linked list for remove method for Medium size : "+(calculator6-calculator5)+" nanosecond");



        Random random4 = new Random();
        ArrayList<Integer> array4 = new ArrayList<Integer>();
        long calculator7 = System.nanoTime();
        for(int i=0;i<100;i++){
            array4.add(random4.nextInt(5000)+1);
            hashtableChainTreeSet.remove(array4.get(i));
        }
        long calculator8 = System.nanoTime();
        System.out.println();
        System.out.println("The taken for the hashing by using linked list for remove method for Large size : "+(calculator8-calculator7)+" nanosecond");




        System.out.println();

        Random rand = new Random();
        ArrayList<Integer> arr = new ArrayList<Integer>();
        long calculate11 = System.nanoTime();
        for(int i=0;i<100;i++){
            arr.add(rand.nextInt(5000)+1);
            hashtableChainTreeSet.put(arr.get(i),"a");
        }
        long calculate12 = System.nanoTime();
        System.out.println();
        System.out.println("The taken for the hashing by using TreeSet for put method for Medium size : "+(calculate12-calculate11)+" nanosecond");



        long calculate13 = System.nanoTime();
        for(int i=0;i<1000;i++){
            arr.add(rand.nextInt(5000)+1);
            hashtableChainTreeSet.put(arr.get(i),"a");
        }
        long calculate14 = System.nanoTime();

        System.out.println("The taken for the hashing by using TreeSet for put method for Large size : "+(calculate14-calculate13)+" nanosecond");
        System.out.println();


        System.out.println("//////////////////////////////////////////////////////////////////////////////////////");
        System.out.println();
        
        
        ///////////////////////////////////////////////////////////////////////////////
        
        
        System.out.println("testing put method for hashing Coalesced hashing technique: ");
        System.out.println();
        CoalescedHash<Integer,String> hashCoalesced = new CoalescedHash<>();
        long calculate9 = System.nanoTime();

        hashCoalesced.put(0,"a");
        hashCoalesced.put(1,"b");
        hashCoalesced.put(2,"c");
        hashCoalesced.put(3,"d");
        hashCoalesced.put(4,"e");
        hashCoalesced.put(5,"f");
        hashCoalesced.put(6,"g");
        hashCoalesced.put(7,"h");
        hashCoalesced.put(8,"k");
        hashCoalesced.put(9,"m");
        long calculate10 = System.nanoTime();
        System.out.println(hashCoalesced);
        System.out.println();
        System.out.println("The time taken for hashing Coalesced for put() method for small size: "+ (calculate10-calculate9)+" nanosecond");
        System.out.println();

        try{
            Random random5 = new Random();
            ArrayList<Integer> array5 = new ArrayList<Integer>();
            long calculator9 = System.nanoTime();
            for(int i=0;i<15;i++){
                array5.add(random5.nextInt(10000)+1);
                hashCoalesced.put(array5.get(i),"a");
            }
            long calculator10 = System.nanoTime();
            System.out.println("The taken for the hashing by using Coalesced for put method for Medium size : "+(calculator10-calculator9)+" nanosecond");


            System.out.println();
            Random random6 = new Random();
            ArrayList<Integer> array6 = new ArrayList<Integer>();
            long calculator11 = System.nanoTime();
            for(int i=0;i<20;i++){
                array6.add(random6.nextInt(100000)+1);
                hashCoalesced.put(array6.get(i),"a");
            }
            long calculator12 = System.nanoTime();
            System.out.println("The taken for the hashing by using Coalesced for put() method for Large size : "+(calculator12-calculator11)+" nanosecond");

        }catch(Exception e){
            System.out.println(e.getMessage());

        }

    }
}