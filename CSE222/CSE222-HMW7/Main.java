import java.util.ArrayList;
import java.util.Iterator;
import java.util.Random;





public class Main{
    public static <E> void main(String[] args) {

        System.out.println("********************************** PART1 ****************************************");
        System.out.println();
        System.out.println("***************** SkipListSet Testing **************");
        navigableSkipList<Integer> nv = new navigableSkipList<>();
        System.out.println();
       
        
        try {
            ArrayList<Integer> tp = new ArrayList<>();
            tp.add(12);
            tp.add(10);
            tp.add(9);
            tp.add(1);
            tp.add(26);
            tp.add(14);
            tp.add(4);
            tp.add(92);
            tp.add(19);
            tp.add(6);
            tp.add(110);
            tp.add(95);
            tp.add(138);
            tp.add(150);
            tp.add(222);
    
    
            System.out.println("******* Adding ******");
            System.out.println("Elements to Add");
            
            for(int i=0;i<tp.size();i++){
                System.out.print(tp.get(i)+", ");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
       
        System.out.println();
        System.out.println("Before Adding To SkipListSet:");
        System.out.println(nv);

        nv.add(12);
        nv.add(10);
        nv.add(9);
        nv.add(1);
        nv.add(26);
        nv.add(14);
        nv.add(4);
        nv.add(92);
        nv.add(19);
        nv.add(6);
        nv.add(110);
        nv.add(95);
        nv.add(138);
        nv.add(150);
        nv.add(222);
        System.out.println("After Adding To SkipListSet:");
        System.out.println(nv);
        System.out.println();

        System.out.println("************ Removing ************");
        System.out.println("ELEMENT TO REMOVE : 92,14");
        System.out.println("Before Removing: ");
        System.out.println(nv);
        nv.remove(92);
        nv.remove(14);
        System.out.println("After Removing: ");
        System.out.println(nv);
        System.out.println();

    
        System.out.println("********* Descending Iterator: ************");
        Iterator<Integer> x = nv.descendingIterator();

        while (x.hasNext()){
            System.out.print(x.next()+ ", ");
        }

        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println("*************************** AVLTreeSet Tests ***********************************");
        System.out.println();
        System.out.println("********* Adding ***********");
        navigableSetAVL<Integer> na = new navigableSetAVL<>();
        navigableSetAVL<Integer> na2 = new navigableSetAVL<>();

        System.out.println("Elements To Add: ");
        ArrayList<Integer> rec = new ArrayList<>();
    try {
        rec.add(23);
        rec.add(10);
        rec.add(2);
        rec.add(1);
        rec.add(22);
        rec.add(12);
        rec.add(130);
        rec.add(51);
        rec.add(93);
        rec.add(111);
        rec.add(229);
        rec.add(87);
        rec.add(45);
        rec.add(79);
        rec.add(100);

        for(int i=0;i<rec.size();i++){
            System.out.print(rec.get(i)+", ");
        }
        System.out.println();
        System.out.println("Before Adding");
        System.out.println(na);

    } catch (Exception e) {
        System.out.println(e.getMessage());
    }
        
        na.insert(23);
        na.insert(10);
        na.insert(2);
        na.insert(1);
        na.insert(22);
        na.insert(12);
        na.insert(130);
        na.insert(51);
        na.insert(93);
        na.insert(111);
        na.insert(229);
        na.insert(87);
        na.insert(45);
        na.insert(79);
        na.insert(100);
       

        System.out.println("After Adding To AVLTreeSet: ");        
        na.printInorder();
        System.out.println();
        System.out.println();

        navigableSetAVL.AvlIterator it = na.iterator(); 

        System.out.println("ITERATOR: ");
        while(it.hasNext()){
            System.out.print(it.next()+" ");
        }
        
        System.out.println();
        System.out.println();
        System.out.println("********** headSet ***********");
        System.out.println("To Element: 23");
        ArrayList<Integer> arrAvl = na.headSet(23);

        System.out.println(arrAvl);
        

        na2.insert(23);
        na2.insert(10);
        na2.insert(2);
        na2.insert(1);
        na2.insert(22);
        na2.insert(12);
        na2.insert(130);
        na2.insert(51);
        na2.insert(93);
        na2.insert(111);
        na2.insert(229);
        na2.insert(87);
        na2.insert(45);
        na2.insert(79);
        na2.insert(100);
        System.out.println();
        System.out.println();
        System.out.println("********* tailSet ***********");
        System.out.println("From Element: 100");
        ArrayList<Integer> arrAvl2 = na2.tailSet(100);
        System.out.println(arrAvl2);

        System.out.println();
        System.out.println();
        System.out.println("********************************** PART2 *************************************");
        BinarySearchTree<Integer>BST = new BinarySearchTree<Integer>();
        BinarySearchTree<Integer>BST2 = new BinarySearchTree<Integer>();
        BinarySearchTree<Integer>BST3 = new BinarySearchTree<Integer>();
        BinarySearchTree<Integer>BST4 = new BinarySearchTree<Integer>();
        
       
        BST.add(5);
        BST.add(20);
        BST.add(18);
        BST.add(23);
        BST.add(4);
        System.out.println("Binary Tree is :\n"+ BST);
        
        int result = isAvlRedBlack(BST);
        if(result == 1){
            System.out.println("THE TREE ABOVE IS AVL TREE AND Red-Black TREE");
        }

        if(result == 2){
            System.out.println("Red-Black Tree");

        }
        System.out.println();
        System.out.println("***********************");
        BST2.add(12);
        BST2.add(8);
        BST2.add(4);
        BST2.add(5);
        BST2.add(11);
        BST2.add(18);
        BST2.add(17);
        System.out.println("Binary Tree is :\n"+ BST2);
        
        int result2 = isAvlRedBlack(BST2);
        if(result2 == 1){
            System.out.println("THE TREE ABOVE IS AVL TREE AND Red-Black TREE");
        }

        if(result2 == 2){
            System.out.println("Red-Black Tree");

        }

        System.out.println();
        System.out.println("**********************");
        BST3.add(5);
        BST3.add(20);
        BST3.add(18);
        BST3.add(23);
        BST3.add(4);
        BST3.add(6);
        System.out.println("Binary Tree is :\n"+ BST3);
        
        int result3 = isAvlRedBlack(BST3);
        if(result3 == 1){
            System.out.println("THE Tree Above is Avl Tree And Red-Black Tree");
        }

        if(result3 == 2){
            System.out.println("The Tree Above is Red-Black Tree");

        }

        System.out.println();
        System.out.println("*******************");
        BST4.add(12);
        BST4.add(8);
        BST4.add(4);
        BST4.add(5);
        BST4.add(11);
        BST4.add(18);
        BST4.add(17);
        BST4.add(2);
        BST4.add(7);

        System.out.println("Binary Tree is :\n"+ BST4);
        
        int result4 = isAvlRedBlack(BST4);
        if(result4 == 1){
            System.out.println("THE Tree Above is Avl Tree And Red-Black Tree");
        }

        if(result4 == 2){
            System.out.println("The Tree Above is Red-Black Tree");

        }

        else{
            System.out.println("The Above Tree is Neither the Avl Tree nor the Red Black Tree");
        }



        System.out.println();
        System.out.println("******************************* PART3 *********************************");
        long start;
        long end;
        Random random = new Random();
        int extraNumber = -1;
        System.out.println();
        System.out.println("************************* BinarySearchTree-Test ****************************");
        System.out.println();
        
        BinarySearchTree<Integer> [] binarySearchTree10K = new BinarySearchTree[10];
        BinarySearchTree<Integer> [] binarySearchTree20K = new BinarySearchTree[10];
        BinarySearchTree<Integer> [] binarySearchTree40K = new BinarySearchTree[10];
        BinarySearchTree<Integer> [] binarySearchTree80K = new BinarySearchTree[10];
        
        RedBlackTree<Integer> [] redBlackTree10K = new RedBlackTree[10];
        RedBlackTree<Integer> [] redBlackTree20K = new RedBlackTree[10];
        RedBlackTree<Integer> [] redBlackTree40K = new RedBlackTree[10];
        RedBlackTree<Integer> [] redBlackTree80K = new RedBlackTree[10];

        TwoThreeTree<Integer> [] TwoThreeTree10K = new TwoThreeTree[10];
        TwoThreeTree<Integer> [] TwoThreeTree20K = new TwoThreeTree[10];
        TwoThreeTree<Integer> [] TwoThreeTree40K = new TwoThreeTree[10];
        TwoThreeTree<Integer> [] TwoThreeTree80K = new TwoThreeTree[10];

        BTree<Integer> [] bTree10K = new BTree[10];
        BTree<Integer> [] bTree20K = new BTree[10];
        BTree<Integer> [] bTree40K = new BTree[10];
        BTree<Integer> [] bTree80K = new BTree[10];

        SkipList<Integer> [] skipList10K = new SkipList[10];
        SkipList<Integer> [] skipList20K = new SkipList[10];
        SkipList<Integer> [] skipList40K = new SkipList[10];
        SkipList<Integer> [] skipList80K = new SkipList[10];

        long time =0;
        long time2=0;
        long time3=0;
        long time4=0;
        long time5=0;
        long time6=0;
        long time7=0;
        long time8=0;
        long time9=0;
        long time10=0;
        long time11=0;
        long time12=0;
        long time13 =0;
        long time14=0;
        long time15=0;
        long time16=0;
        long time17=0;
        long time18=0;
        long time19=0;
        long time20=0;
        
        for( int i = 0 ; i < 10 ; ++i ){
            binarySearchTree10K[i] = new BinarySearchTree<>();
            for( int j = 0 ; j < 10000 ; ++j ) {
                if(!(binarySearchTree10K[i].contains( extraNumber = random.nextInt() ))){
                    binarySearchTree10K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }

        

        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                binarySearchTree10K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time += (end-start);
        }  
        
        System.out.println("Average time for Binary Search Tree for 10k elements while inserting 100 random elements: "+ time/10+" ns");



        for( int i = 0 ; i < 10 ; ++i ){
            binarySearchTree20K[i] = new RedBlackTree<>();
            for( int j = 0 ; j < 20000 ; ++j ) {
                if(!(binarySearchTree20K[i].contains( extraNumber = random.nextInt() ))){
                    binarySearchTree20K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                binarySearchTree20K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time2 += (end-start);
        }  
        
        System.out.println("Average time for Binary Search Tree for 20k elements while inserting 100 random elements: "+ time2/10+" ns");


        for( int i = 0 ; i < 10 ; ++i ){
            binarySearchTree40K[i] = new RedBlackTree<>();
            for( int j = 0 ; j < 40000 ; ++j ) {
                if(!(binarySearchTree40K[i].contains( extraNumber = random.nextInt() ))){
                    binarySearchTree40K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                binarySearchTree40K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time3 += (end-start);
        }  
        
        System.out.println("Average time for Binary Search Tree for 40k elements while inserting 100 random elements: "+ time3/10+" ns");




        for( int i = 0 ; i < 10 ; ++i ){
            binarySearchTree80K[i] = new RedBlackTree<>();
            for( int j = 0 ; j < 80000 ; ++j ) {
                if(!(binarySearchTree80K[i].contains( extraNumber = random.nextInt() ))){
                    binarySearchTree80K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                binarySearchTree80K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time4 += (end-start);
        }  
        
        System.out.println("Average time for Binary Search Tree for 80k elements while inserting 100 random elements: "+ time4/10+" ns");




        System.out.println();
        System.out.println("**************************** Red-Black Tree-Test **************************************");
        System.out.println();

        for( int i = 0 ; i < 10 ; ++i ){
            redBlackTree10K[i] = new RedBlackTree<>();
            for( int j = 0 ; j < 10000 ; ++j ) {
                if(!(redBlackTree10K[i].contains( extraNumber = random.nextInt() ))){
                    redBlackTree10K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                redBlackTree10K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time5 += (end-start);
        }  
        
        System.out.println("Average time for Red Black Tree for 10k elements while inserting 100 random elements: "+ time5/10+" ns");



        for( int i = 0 ; i < 10 ; ++i ){
            redBlackTree20K[i] = new RedBlackTree<>();
            for( int j = 0 ; j < 20000 ; ++j ) {
                if(!(redBlackTree20K[i].contains( extraNumber = random.nextInt() ))){
                    redBlackTree20K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                redBlackTree20K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time6 += (end-start);
        }  
        
        System.out.println("Average time for Red Black Tree for 20k elements while inserting 100 random elements: "+ time6/10+" ns");




        for( int i = 0 ; i < 10 ; ++i ){
            redBlackTree40K[i] = new RedBlackTree<>();
            for( int j = 0 ; j < 40000 ; ++j ) {
                if(!(redBlackTree40K[i].contains( extraNumber = random.nextInt() ))){
                    redBlackTree40K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                redBlackTree40K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time7 += (end-start);
        }  
        
        System.out.println("Average time for Red Black Tree for 40k elements while inserting 100 random elements: "+ time7/10+" ns");





        for( int i = 0 ; i < 10 ; ++i ){
            redBlackTree80K[i] = new RedBlackTree<>();
            for( int j = 0 ; j < 80000 ; ++j ) {
                if(!(redBlackTree80K[i].contains( extraNumber = random.nextInt() ))){
                    redBlackTree80K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                redBlackTree80K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time8 += (end-start);
        }  
        
        System.out.println("Average time for Red Black Tree for 80k elements while inserting 100 random elements: "+ time8/10+" ns");


        System.out.println();
        System.out.println();
        System.out.println("********************************* Two-Three Tree- Test  ******************************************");
        System.out.println();
        for( int i = 0 ; i < 10 ; ++i ){
            TwoThreeTree10K[i] = new TwoThreeTree<>(3);
            for( int j = 0 ; j < 10000 ; ++j ) {
                if(!(TwoThreeTree10K[i].contains( extraNumber = random.nextInt() ))){
                    TwoThreeTree10K[i].insert( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                TwoThreeTree10K[i].insert(array.get(j));
            }

            end = System.nanoTime();
            time9 += (end-start);
        }  
        
        System.out.println("Average time for TwoThree Tree for 10k elements while inserting 100 random elements: "+ time9/10+" ns");




        for( int i = 0 ; i < 10 ; ++i ){
            TwoThreeTree20K[i] = new TwoThreeTree<>(3);
            for( int j = 0 ; j < 20000 ; ++j ) {
                if(!(TwoThreeTree20K[i].contains( extraNumber = random.nextInt() ))){
                    TwoThreeTree20K[i].insert( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                TwoThreeTree20K[i].insert(array.get(j));
            }

            end = System.nanoTime();
            time10 += (end-start);
        }  
        
        System.out.println("Average time for TwoThree Tree for 20k elements while inserting 100 random elements: "+ time10/10+" ns");




        for( int i = 0 ; i < 10 ; ++i ){
            TwoThreeTree40K[i] = new TwoThreeTree<>(3);
            for( int j = 0 ; j < 40000 ; ++j ) {
                if(!(TwoThreeTree40K[i].contains( extraNumber = random.nextInt() ))){
                    TwoThreeTree40K[i].insert( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                TwoThreeTree40K[i].insert(array.get(j));
            }

            end = System.nanoTime();
            time11 += (end-start);
        }  
        
        System.out.println("Average time for TwoThree Tree for 40k elements while inserting 100 random elements: "+ time11/10+" ns");





        for( int i = 0 ; i < 10 ; ++i ){
            TwoThreeTree80K[i] = new TwoThreeTree<>(3);
            for( int j = 0 ; j < 80000 ; ++j ) {
                if(!(TwoThreeTree80K[i].contains( extraNumber = random.nextInt() ))){
                    TwoThreeTree80K[i].insert( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                TwoThreeTree80K[i].insert(array.get(j));
            }

            end = System.nanoTime();
            time12 += (end-start);
        }  
        
        System.out.println("Average time for TwoThree Tree for 80k elements while inserting 100 random elements: "+ time12/10+" ns");


        System.out.println();
        System.out.println("************************************* B-Tree-Test ************************************");
        System.out.println();
        
        for( int i = 0 ; i < 10 ; ++i ){
            bTree10K[i] = new BTree<>(6);
            for( int j = 0 ; j < 10000 ; ++j ) {
                if(!(bTree10K[i].contains( extraNumber = random.nextInt() ))){
                    bTree10K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                bTree10K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time13 += (end-start);
        }  
        
        System.out.println("Average time for B-Tree for 10k elements while inserting 100 random elements: "+ time13/10+" ns");


        
        for( int i = 0 ; i < 10 ; ++i ){
            bTree20K[i] = new BTree<>(6);
            for( int j = 0 ; j < 20000 ; ++j ) {
                if(!(bTree20K[i].contains( extraNumber = random.nextInt() ))){
                    bTree20K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                bTree20K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time14 += (end-start);
        }  
        
        System.out.println("Average time for B-Tree for 20k elements while inserting 100 random elements: "+ time14/10 +" ns");




         
        for( int i = 0 ; i < 10 ; ++i ){
            bTree40K[i] = new BTree<>(6);
            for( int j = 0 ; j < 40000 ; ++j ) {
                if(!(bTree40K[i].contains( extraNumber = random.nextInt() ))){
                    bTree40K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                bTree40K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time15 += (end-start);
        }  
        
        System.out.println("Average time for B-Tree for 40k elements while inserting 100 random elements: "+ time15/10 +" ns");


          
        for( int i = 0 ; i < 10 ; ++i ){
            bTree80K[i] = new BTree<>(6);
            for( int j = 0 ; j < 80000 ; ++j ) {
                if(!(bTree80K[i].contains( extraNumber = random.nextInt() ))){
                    bTree80K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }


        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                bTree80K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time16 += (end-start);
        }  
        
        System.out.println("Average time for B-Tree for 80k elements while inserting 100 random elements: "+ time16/10 +" ns");

        System.out.println();
        System.out.println();
        System.out.println("*********************************** SkipList-Test ****************************************");
        System.out.println();
        for( int i = 0 ; i < 10 ; ++i ){
            skipList10K[i] = new SkipList<>();
            for( int j = 0 ; j < 10000 ; ++j ) {
                if((skipList10K[i].find( extraNumber = random.nextInt() ) == null )){
                   
                    skipList10K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }

        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                skipList10K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time17 += (end-start);
        }  
        
        System.out.println("Average time for Skip List for 10k elements while inserting 100 random elements: "+ time17/10+" ns");




        for( int i = 0 ; i < 10 ; ++i ){
            skipList20K[i] = new SkipList<>();
            for( int j = 0 ; j < 20000 ; ++j ) {
                if((skipList20K[i].find( extraNumber = random.nextInt() ) == null )){
                   
                    skipList20K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }

        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                skipList20K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time18 += (end-start);
        }  
        
        System.out.println("Average time for Skip List for 20k elements while inserting 100 random elements: "+ time18/10+" ns");


        for( int i = 0 ; i < 10 ; ++i ){
            skipList40K[i] = new SkipList<>();
            for( int j = 0 ; j < 40000 ; ++j ) {
                if((skipList40K[i].find( extraNumber = random.nextInt() ) == null )){
                   
                    skipList40K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }

        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                skipList40K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time19 += (end-start);
        }  
        
        System.out.println("Average time for Skip List for 40k elements while inserting 100 random elements: "+ time19/10+" ns");





        for( int i = 0 ; i < 10 ; ++i ){
            skipList80K[i] = new SkipList<>();
            for( int j = 0 ; j < 80000 ; ++j ) {
                if((skipList80K[i].find( extraNumber = random.nextInt() ) == null )){
                   
                    skipList80K[i].add( extraNumber );
                }
            
                else{
                    j--;
                }
            }
        }

        for(int i=0;i<10;i++){
            ArrayList<Integer>array = new ArrayList<>();

            while(array.size() != 100){
                if(!array.contains(extraNumber = random.nextInt() )){
                    array.add(extraNumber);
                }
            }
            start = System.nanoTime();

            for(int j = 0;j<array.size();j++){
                skipList80K[i].add(array.get(j));
            }

            end = System.nanoTime();
            time20 += (end-start);
        }  
        
        System.out.println("Average time for Skip List for 80k elements while inserting 100 random elements: "+ time20/10+" ns");


    }   

    /**
     * This method gives information about whether the binary search tree 
     * entered as a parameter is Avl tree or red-black tree.
     * @param bst
     */
    public static int isAvlRedBlack(BinarySearchTree<Integer> bst){

        boolean redBlack = isRedBlack(bst.root);
        boolean Avl = isAvlBst(bst.root);

        if(redBlack && Avl){
            return 1;
        }
    
        else if(redBlack){
            return 2;
        }
           
        else if(Avl){

            return 3;
        }


        else{
            return 4;
        }

    }   

    /**
     * This method checks if Binary Search Tree is Red-Black Tree.
     * @param root
     */
    public static boolean isRedBlack(BinaryTree.Node<Integer> root){
        if(root != null){
            int leftHeight = maxHeight(root.left);
            int rightHeight = maxHeight(root.right);

            if(Math.abs(rightHeight-leftHeight)<=2){
               
                if(isAvlBst(root.left)&& isAvlBst(root.right))
                    return true;
            }
                return false;
            
        }
            return true;
    }

    /**
     * This method checks if Binary Search Tree is Red-Black Tree.
     * @param root
     */
    public static boolean isAvlBst(BinaryTree.Node<Integer> root){

        if(root != null){
            int leftHeight = maxHeight(root.left);
            int rightHeight = maxHeight(root.right);

            if(Math.abs(rightHeight-leftHeight)<=1){
               
                if(isAvlBst(root.left)&& isAvlBst(root.right))
                    return true;
            }
                return false;
            
        }
            return true;

    }

    /**
     * Compute the max height the both side.
     * @param root
     */
    public static int maxHeight(BinaryTree.Node<Integer> root){

        
    
        if (root == null)
            return 0;
    
        else {
            
            int lDepth = maxHeight(root.left);
            int rDepth = maxHeight(root.right);

            
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
            return (rDepth + 1);
        }
        
    
    }

    /**
     * Compute the min height the both side.
     * @param root
     */
    public static int minHeight(BinaryTree.Node<Integer> root){

        if (root == null)
            return 0;
    
        else {
            /* compute the depth of each subtree */
            int lDepth = minHeight(root.left);
            int rDepth = minHeight(root.right);

            /* use the smaller one */
            if (lDepth < rDepth)
                return (lDepth + 1);
            else
            return (rDepth + 1);
        }
        
    }


}