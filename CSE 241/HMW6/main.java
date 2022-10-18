import java.util.NoSuchElementException;

public class main {


    public static void main(String[] args){
        System.out.println("\n****************LinkedList Integer***********************\n");

        Queue<Integer> q = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        System.out.println("\nAdds 3,6,7,8 to LinkedList 1\n");
        q.add(3);
        q.add(6);
        q.add(7);
        q.add(8);
        System.out.println("\nAdds 6,7 to LinkedList 2\n");
        q2.add(6);
        q2.add(7);

        Iterator it = q.iterator();
        System.out.println("\nLinkedList 1:\n");
        while(it.hasNext())
            System.out.println(it.next());


        //test retainAll
        System.out.println("Contains All = " + q.containsAll(q2));
        q.retainAll(q2);
        System.out.println("Contains All after retain all= " + q.containsAll(q2));

        q.clear();
        q2.clear();
        System.out.println("\nClears Linkedlist1 and 2, Adds 3,6,7,8 to LinkedList 1\n");
        q.add(3);
        q.add(6);
        q.add(7);
        q.add(8);
        System.out.println("\nAdds 6,7 to LinkedList 2\n");
        q2.add(6);
        q2.add(7);

        System.out.println("\nPrinting Linked list 1 with iterator\n");
        it = q.iterator();
        while(it.hasNext())
            System.out.println(it.next());


        //test removeAll
        System.out.println("Contains All = " + q.containsAll(q2));
        q.removeAll(q2);
        System.out.println("Contains All after remove all= " + q.containsAll(q2));

        it = q.iterator();
        System.out.println("\nPrinting Linked list 1 with iterator\n");
        while(it.hasNext())
            System.out.println(it.next());

            
            System.out.println("\n****************LinkedList String***********************\n");

            Queue<String> q3 = new LinkedList<>();
            Queue<String> q4 = new LinkedList<>();
            System.out.println("\nAdds three,six,seven,eight to LinkedList 1\n");
            q3.add("three");
            q3.add("six");
            q3.add("seven");
            q3.add("eight");
            System.out.println("\nAdds six,seven to LinkedList 2\n");
            q4.add("six");
            q4.add("seven");
    
            it = q3.iterator();
            System.out.println("\nLinkedList 1:\n");
            while(it.hasNext())
                System.out.println(it.next());
    
    
            //test retainAll
            System.out.println("Contains All = " + q3.containsAll(q4));
            q3.retainAll(q4);
            System.out.println("Contains All after retain all= " + q3.containsAll(q4));
    
            q3.clear();
            q4.clear();
            System.out.println("\nClears Linkedlist1 and 2, Adds three,six,seven,eight to LinkedList 1\n");
            q3.add("three");
            q3.add("six");
            q3.add("seven");
            q3.add("eight");
            System.out.println("\nAdds six,seven to LinkedList 2\n");
            q4.add("six");
            q4.add("seven");
    
            System.out.println("\nPrinting Linked list 1 with iterator\n");
            it = q3.iterator();
            while(it.hasNext())
                System.out.println(it.next());
    
    
            //test removeAll
            System.out.println("Contains All = " + q3.containsAll(q4));
            q3.removeAll(q4);
            System.out.println("Contains All after remove all= " + q3.containsAll(q4));
    
            it = q.iterator();
            System.out.println("\nPrinting Linked list 1 with iterator\n");
            while(it.hasNext())
                System.out.println(it.next());
            
            
            
            System.out.println("\n****************HashSet Integer***********************\n");
            HashSet<Integer> hSet3 = new HashSet<>();
    
            System.out.println("\nAdds 1, 2, 3, 4 to HashSet Integer 1\n");
            hSet3.add(1);
            hSet3.add(2);
            hSet3.add(3);
            hSet3.add(4);
    
            HashSet<Integer> hSet4 = new HashSet<>();
            System.out.println("\nAdds 1, 2, 3, 4 to HashSet Integer 2\n");
            hSet4.add(1);
            hSet4.add(2);
            hSet4.add(3);
            hSet4.add(4);
            System.out.println("\nAdds all of the HashSet String 2 to HashSet Integer 1\n");
            hSet3.addAll(hSet4);
    
            it = hSet3.iterator();
            System.out.println("\nHashSet Integer 1:\n");
            while (it.hasNext())
                System.out.println(it.next());

        
        
                System.out.println("\n****************HashSet String ***********************\n");
        HashSet<String> hSet = new HashSet<>();

        System.out.println("\nAdds bir, iki, uc, dort to HashSet String 1\n");
        hSet.add("bir");
        hSet.add("iki");
        hSet.add("uc");
        hSet.add("dort");

        HashSet<String> hSet2 = new HashSet<>();
        System.out.println("\nAdds 1bir, 1iki, 1uc, 1dort to HashSet String 2\n");
        hSet2.add("1bir");
        hSet2.add("1iki");
        hSet2.add("1uc");
        hSet2.add("1dort");
        System.out.println("\nAdds all of the HashSet String 2 to HashSet String 1\n");
        hSet.addAll(hSet2);

        it = hSet.iterator();
        System.out.println("\nHashSet String 1:\n");
        while (it.hasNext())
            System.out.println(it.next());

            System.out.println("\n****************Exception Test ***********************\n");
        try{
            System.out.println(it.next());
            it.remove();
        } catch (NoSuchElementException err) {
            System.out.println(err);
        }
        System.out.println("iterate");
        while (it.hasNext())
            System.out.println(it.next());

        hSet.remove("iki");


        it = hSet.iterator();



        System.out.println("\nafter removing iki hasNext?"+it.hasNext()+ " size "+hSet.size());

        while (it.hasNext())
            System.out.println(it.next());

            System.out.println("\n****************ArrayList Integer ***********************\n");
        ArrayList<Integer> aList = new ArrayList<>();

        aList.add(3);
        aList.add(8);

        aList.add(9);
        aList.insertAt(33,1);

        it = aList.iterator();

        System.out.println("Iterate:");
        while (it.hasNext())
            System.out.println(it.next());


        it.remove();
        it.remove();
        System.out.println("Iterate:");
        it = aList.iterator();

        while (it.hasNext())
            System.out.println(it.next());
        System.out.println("Iterate:");
        


        System.out.println("\n****************ArrayList String***********************\n");

        ArrayList<String> alist = new ArrayList<>();


        alist.add("houston");
        alist.add("houston");
        alist.add("Washington");
        alist.add("houston");

        it = alist.iterator();

        while (it.hasNext())
            System.out.println(it.next());

        alist.remove("houston");
        alist.remove("houston");
        alist.remove("Washington");
        alist.remove("Washington");

        it = alist.iterator();
        System.out.println("\nArrayList \n");

        while (it.hasNext())
            System.out.println(it.next());
        
            System.out.println("\n****************ArrayList Integer***********************\n");
        HashSet<Integer> hSetInt = new HashSet<>();
        HashSet<Integer> hSetInt2 = new HashSet<>();
        hSetInt.add(3);
        hSetInt.add(4);
        hSetInt.add(5);
        hSetInt.add(6);

        hSetInt2.add(3);
        hSetInt2.add(4);
        hSetInt2.add(5);
        hSetInt2.add(6);


        System.out.println(hSetInt.contains(3));
        System.out.println(hSetInt.size());

        hSetInt.add(3);

        System.out.println(hSetInt.containsAll(hSetInt2));
        System.out.println(hSetInt2.containsAll(hSetInt));

        System.out.println(hSetInt.size());
        System.out.println(hSetInt2.size());

        System.out.println("contains = " + hSetInt.contains(3));

        hSetInt.clear();
        System.out.println("contains = " + hSetInt.contains(3));

        System.out.println(hSetInt.containsAll(hSetInt2));
        System.out.println(hSetInt.size());
        System.out.println("hSetInt2.size() " + hSetInt2.size());

        //System.out.println(hSetInt2.remove(6));
        System.out.println("hSetInt2.size() " + hSetInt2.size());

        hSetInt.add(3);
        hSetInt.add(5);
        it = hSetInt.iterator();
        System.out.println("contains all " + hSetInt2.containsAll(hSetInt));
        System.out.println("\n************Exception Test ***************\n");
        try{
            HashSet hSetInt3 = new HashSet(hSetInt2);
        }
        catch (NullPointerException err) {
            System.out.println(err);
        }
        HashSet<Integer> hSetInt3 = new HashSet<>(15);

        Iterator it3 = hSetInt3.iterator();
            System.out.println("hSetInt3 = ");
            while(it3.hasNext())
                System.out.println(it3.next());

        hSetInt2.removeAll(hSetInt);

        Iterator it2 = hSetInt2.iterator();


        System.out.println("size after modified "+hSetInt2.size());


        while(it2.hasNext())
            System.out.println(it2.next());

        hSetInt3.retainAll(hSetInt);

        it3 = hSetInt3.iterator();


        System.out.println("size after modified "+hSetInt3.size());

        while(it3.hasNext())
            System.out.println(it3.next());

        

    }
}
