import java.util.NoSuchElementException;

/**
* This class includes the additions and subtractions made by the manager. 
*/
public class Branch{

    HybridList<Furniture> theData = new HybridList<Furniture>();
    
    /** 
    *Thanks to HybridList, I can hide how many pieces of furniture.
    */     
    public int getStock(String stock){

     
        switch(stock){


            case "chair":
            return theData.get(0).getTotal();
            
            
            case "desk":
            return theData.get(1).getTotal();
            
            
            case "table":
            return theData.get(2).getTotal();
            
            
            case "bookcase":
            return theData.get(3).getTotal();
        
            
            case "cabinet":
            return theData.get(4).getTotal();
            
        
            default:
                throw new NoSuchElementException();
        }
    }
    /** 
    *For the selection of model, color, type and number when ordering and I use HybridList.
    */
    public void decrease(int type,int model,int color,int count){
        theData.get(type).decrease(model, color, count);
    }
    
    /** 
    *Here I use the 3D array to downsize to a single dimension, 
    *and here I use HybridList for the insertion process.
    */
    public Branch(int [][][] arrayStock){
        
        
        if(arrayStock.length > 5 || arrayStock == null)
            throw new IllegalStateException();

            theData = new HybridList<Furniture>();

        
            theData.add(new officeDesk(arrayStock[0]));
               
                
             
            theData.add(new officeBookcase(arrayStock[1]));
                
                
            theData.add(new officeChair(arrayStock[2]));
                
               
            theData.add(new officeCabinet(arrayStock[3]));
                   
                
            theData.add(new officeTable(arrayStock[4])); 
                          
        
        
    }   

    

}