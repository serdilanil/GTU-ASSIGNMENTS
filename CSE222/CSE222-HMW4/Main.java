import java.util.Random;

public class Main{

    public static void main(String[] args) {
        
       
        System.out.println();
        System.out.println("Heap Structure testing");
        System.out.println("=================================\n");
        System.out.println("*********** PART1 **********");
        MaxHeapStructure<Integer> numberHeap = new MaxHeapStructure<Integer>();
       
        System.out.println();

        System.out.println("Adding numbers to Heap.");
        System.out.println("- add((10)");
        System.out.println("- add((20)");
        System.out.println("- add((5)");
        System.out.println("- add((15)");
        System.out.println("- add((10)");
        System.out.println("- add((9)");
        System.out.println("- add((25)");
        System.out.println("- add((16)");
        System.out.println("- add((18)");
        System.out.println("- add((20)");
        System.out.println("- add((9)");
        System.out.println("- add((9)");

        numberHeap.add(10);
        numberHeap.add(20);
        numberHeap.add(5);
        numberHeap.add(15);
        numberHeap.add(10);
        numberHeap.add(9);
        numberHeap.add(25);
        numberHeap.add(16);
        numberHeap.add(18);
        numberHeap.add(20);
        numberHeap.add(9);
        numberHeap.add(9);
        System.out.println("--------------");
        System.out.println("Current Heap as a Sort: ");
        System.out.println(numberHeap);
        System.out.println();
        
        System.out.println("*********SEARCH OPERATION:************");
        System.out.println();
        System.out.println("- find(10)).toString() ");
        if( numberHeap.find(10) == null ) {
            System.out.println("Given item has not been found in heap.");
        } else {
            System.out.println( numberHeap.find(10).toString() );
        }
        System.out.println();

        System.out.println("- find((18).toString() ");
        if( numberHeap.find(18) == null ) {
            System.out.println("Given item has not been found in heap.");
        } else {
            System.out.println( numberHeap.find(18).toString() );
        }
        System.out.println();

        System.out.println("- find( (7).toString() ");
        if( numberHeap.find(7) == null ) {
            System.out.println("Given item has not been found in heap.");
        } else {
            System.out.println( numberHeap.find(7).toString() );
        }
        System.out.println();

        System.out.println("******** MERGE HEAP OPERATION ********");
        System.out.println("First Heap:");
        System.out.println("19,12,23,92,34,16,56");
        System.out.println();
        System.out.println("Second Heap:");
        System.out.println("43,39,21,83,26,65,9,11");
        System.out.println();
        int[] a = {19,12, 23, 92,34,16,56};
        int[] b = {43, 39,21,83,26,65,9,11};
        int n = a.length;
        int m = b.length;
  
        int[] merged = new int[m + n];
  
        numberHeap.mergeHeaps(merged, a, b, n, m);
        System.out.println("Merged of two heaps are:");
        for (int i = 0; i < m + n; i++)
            System.out.print(merged[i] + " ");
        
        System.out.println();
        System.out.println();
        
        System.out.println("*****KTh largest element delete operation******");
        System.out.println();
        System.out.println("Heap items are : "+ numberHeap);
        System.out.println("Fourth number is deleted :");
        System.out.println("Fourth element is : " + numberHeap.kthLargestElement(4));
        System.out.println("New Heap items are : "+numberHeap);
        System.out.println();
        
        System.out.println("******* SET BY ITERATOR OPERATION :********");
        System.out.println();
        
        MaxHeapStructure<Integer>.heapIterator itr = numberHeap.iterator();
        System.out.println("Current Heap: " +numberHeap);
        System.out.println("itr.next():"+itr.next());
        System.out.println("itr.next():"+itr.next());
        System.out.println("I put number 6 with next() function");
        itr.set(6);
        
        System.out.println("numberHeap elements are " + numberHeap);
        System.out.println();

        System.out.println("******************** PART2: *******************");

        System.out.println();

        BSTHeapTree<Integer> tree = new BSTHeapTree<>();

        System.out.println("I INSERT 3000 NUMBER RANDOMLY :  ");
        System.out.println();
        Random rand = new Random();
        
        int []arr = new int[3000];

        for(int i=0;i<3000;i++){
            arr[i] = rand.nextInt(5000)+1;
            tree.add(arr[i]);
        }

        System.out.println();
        
        System.out.println("*********  FIND METHOD TO SEARCH THE OCCURRENCE OF NUMBERS :***********");
        System.out.println();
        
        for(int i=0;i<100;i++){
            System.out.println(arr[i*10]+" number occurrence is: " + tree.find(arr[i*10]));
        }
        
        System.out.println();
        System.out.println("********* I SEARCH THE 10 NUMBERS NOT IN THE ARRAY: *********");
        System.out.println();
        System.out.println("6000 Occurence is because it doesn't exist : " +tree.find(6000));
        System.out.println("6400 Occurence is because it doesn't exist : " +tree.find(6400));
        System.out.println("67777 Occurence is because it doesn't exist : " +tree.find(67777));
        System.out.println("232323 Occurence is because it doesn't exist : " +tree.find(232323));
        System.out.println("123232 Occurence is because it doesn't exist : " +tree.find(123232));
        System.out.println("145452 Occurence is because it doesn't exist : " +tree.find(145452));
        System.out.println("134342 Occurence is because it doesn't exist : " +tree.find(134342));
        System.out.println("123434 Occurence is because it doesn't exist : " +tree.find(123434));
        System.out.println("123443 Occurence is because it doesn't exist : " +tree.find(123443));
        System.out.println("1234434 Occurence is because it doesn't exist : " +tree.find(1234434));
        System.out.println();

        System.out.println("Mode of Binary Search Tree is: " + tree.find_mode());
        System.out.println();
        System.out.println("********* I REMOVED 100 ELEMENTS WHICH DETERMINED FROM REMOVE METHOD: *********");
        
        for(int i=0;i<100;i++){
            System.out.println(arr[i*10]+ " OCCURRENCE AFTER REMOVE : " + tree.remove(arr[i*10]));
        }

        System.out.println();
        System.out.println("********* I REMOVED OCCURRENCE OF NUMBER NOT IN ARRAY *********** : ");
        System.out.println();
        System.out.println("6000 Occurence is not removed because this number doesn't exist : " +tree.remove(6000));
        System.out.println("6400 Occurence is not removed because this number doesn't exist: " +tree.remove(6400));
        System.out.println("67777 Occurence is not removed because this number doesn't exist: " +tree.remove(67777));
        System.out.println("232323 Occurence is not removed because this number doesn't exist: " +tree.remove(232323));
        System.out.println("123232 Occurence is not removed because this number doesn't exist: " +tree.remove(123232));
        System.out.println("145452 Occurence is not removed because this number doesn't exist: " +tree.remove(145452));
        System.out.println("134342 Occurence is not removed because this number doesn't exist: " +tree.remove(134342));
        System.out.println("123434 Occurence is not removed because this number doesn't exist: " +tree.remove(123434));
        System.out.println("123443 Occurence is not removed because this number doesn't exist: " +tree.remove(123443));
        System.out.println("1234434 Occurence is not removed because this number doesn't exist: " +tree.remove(1234434));
        
       
    
    }   

    
}

