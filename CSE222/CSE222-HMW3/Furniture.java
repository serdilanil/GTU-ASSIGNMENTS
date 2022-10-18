import java.util.*;

    /** 
    *In this class, I wrote the getTotal method for the total number of furniture 
    *and filled the 3D furniture array by making a binary array with 5 subclasses here.
    */

public class Furniture{

    private int[][] stock;

    public int getTotal(){
        
        int sum=0;

        for(int i=0;i<stock.length;i++){
            for(int j=0;j<stock[i].length;j++){
                sum += stock[i][j];
            }
        }
    
        return sum;
    }


    public Furniture(int[][] array){

        assignSpeacial(array);
    }

    
    
    public void assignSpeacial(int array[][]){
    
        stock = array;
        
    }
    //model and color special of furniture and I keep the this information in this indexes.
    public void decrease(int model,int color,int count){

        if(stock[model][color]-count >= 0){
            stock[model][color] -=count;
        }
        
    }

}

class officeDesk extends Furniture{

        public officeDesk(int[][] array){

            super(array);
        }
        
} 

class officeBookcase extends Furniture{

    public officeBookcase(int[][] array){

        super(array);
    }

} 

class officeChair extends Furniture{

    public officeChair(int[][] array){

        super(array);
    }

} 
class officeCabinet extends Furniture{

    public officeCabinet(int[][] array){

        super(array);
    }

} 

class officeTable extends Furniture{

    public officeTable(int[][] array){

        super(array);
    }

} 
