import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * In this class, the transactions made by the customers are provided.
 */
public class customer extends store implements Icostumer{

    private List<product>tmp = new ArrayList<product>();        
    public int upper;
    public int lower;
    public customer(String password, long ID){
        super(password,ID);
    }

    /**
     * In this method, you can enter the name of the trader to see all the products the trader has.
     * @param trader
     * @throws IOException
     */
    public void showProduct(String trader) throws IOException{
        List<String>temp = new ArrayList<String>();
        String line ="";
        BufferedReader reader = new BufferedReader(new FileReader("product.txt"));

        while((line = reader.readLine()) != null){
            
                temp.add(line);
        }
        
        reader.close();
        
        for(int i = temp.size()-1;i>=0;i--){
            
            if(temp.get(i).contains(trader)){
            
                for(int j =i;j<i+7;j++){
                    System.out.println(temp.get(j));
                }
            }
        }
    }


    /**
     * In this method, you can print orders by writing all the features of the product in the orders.txt file.
     * @param ID
     * @param name
     * @param category
     * @param price
     * @param discounted
     * @param description
     * @param trader
     * @throws IOException
     */
    public void orderProduct(String ID, String name,String category,int price,int discounted,String description,String trader) throws IOException{
        
        
        BufferedWriter writer = new BufferedWriter(new FileWriter("orders.txt",true));
        
        writer.write("\nId: "+ID+"\n");
        writer.write("Name: "+name+"\n");
        writer.write("Category: "+category+"\n");
        writer.write("Price: "+price+"\n");
        writer.write("Discounted: "+discounted+"\n");
        writer.write("Description: "+description+"\n");
        writer.write("Trader: "+trader+"\n");
        writer.write("Situation: "+"NOT CHECKED \n");


        writer.close();

    }

    /**
     * In this method, we can search for any word in the file and return products with that word.
     * @param product
     * @throws IOException
     */
    public void searchQuery(String product) throws IOException{
        
        String line = "";
        BufferedReader reader3 = new BufferedReader(new FileReader("product.txt"));//ID genel

        

        while((line = reader3.readLine()) != null){ //ID yi okuyacak
            if(line.contains("Id: ")){
                String [] array = reader3.readLine().split(": "); //name okuyor
                String [] array2 = reader3.readLine().split(": "); //category okuyor 
                String [] array3 = reader3.readLine().split(": "); //price
                String [] array4 = reader3.readLine().split(": "); //discounted
                String [] array5 = reader3.readLine().split(": "); //description 
                String [] array6 = reader3.readLine().split(": "); //trader
                

                if(array[1].contains(product) || array5[1].contains(product)){
                    tmp.add(new product(line, array[1], array2[1], Integer.parseInt(array3[1]), Integer.parseInt(array4[1]), array5[1], array6[1]));
                   
                }
                
            }
                
        }   
                
                sortNameA_Z();
                System.out.println(tmp);

            reader3.close();
                
    }
    

    /**
     * In this method, I sorting product name from A to Z.
     * @param tmp
     * @throws IOException
     */
    private void sortNameA_Z(List<product> tmp) throws IOException{
        product temp;

        for(int i=0;i<tmp.size();i++){
            for(int j= i+1;j<tmp.size();j++){
                if(tmp.get(i).getName().compareToIgnoreCase(tmp.get(j).getName())>0){
                    temp = tmp.get(i);
                    tmp.set(i,tmp.get(j));
                    tmp.set(j,temp);
                }
            }
        }
            
    }
    
    /**
     * In this method, I sorting product name from A to Z.
     */
    public void sortNameA_Z() throws IOException{
        sortNameA_Z(tmp);
        System.out.println(tmp);
    }
    
    /**
     * In this method, I sorting product's prices increasing order.
     * @param tmp
     * @throws IOException
     */
    private void sortPrice_Inc(List<product>tmp)throws IOException{
        
        for (int i = 0; i<tmp.size()-1;i++) {
            int index = i;
    
            //find the smaller number in remaining sub array.
            for (int j = i+1; j<tmp.size();j++){
                if (tmp.get(j).getPrice() < tmp.get(index).getPrice()){
                    index = j;
                }
            }
    
            //swap the smallest number in remaining sub array.
            product smallerNumber = tmp.get(index);
            tmp.set(index,tmp.get(i));
            tmp.set(i,smallerNumber);
        }
    
    }
    
    /**
     * In this method, I sorting product's prices increasing order.
     */
    public void sortPrice_Inc() throws IOException{
        sortPrice_Inc(tmp);
        System.out.println(tmp);
    }

    /**
     * In this method, I sorting product discount increasing order.
     * @param tmp
     * @throws IOException
     */
    private void sortDiscount_Inc(List<product>tmp)throws IOException{
        
        for (int interval = tmp.size() / 2; interval > 0; interval /= 2) {
            for (int i = interval; i < tmp.size(); i += 1) {
            product temp = tmp.get(i);
            int j;
            for (j = i; j >= interval && tmp.get(j - interval).getDiscounted() > temp.getDiscounted(); j -= interval) {
              tmp.set(j,tmp.get(j - interval));
            }
                tmp.set(j,temp);
            }
          }
          
    }
    
    /**
     * In this method, I sorting product discount increasing order.
     */
    public void sortDiscount_Inc() throws IOException{
        sortDiscount_Inc(tmp);
        System.out.println(tmp);
    }

    /**
     * In this method, I sorting product names form Z to A order.
     * @param tmp
     * @throws IOException
     */
    private void sortNameZ_A(List<product> tmp) throws IOException{
        product temp;

        for(int i=0;i<tmp.size();i++){
            for(int j= i+1;j<tmp.size();j++){
                if(tmp.get(i).getName().compareToIgnoreCase(tmp.get(j).getName())<0){
                    temp = tmp.get(i);
                    tmp.set(i,tmp.get(j));
                    tmp.set(j,temp);
                }
            }
        }
            
    }

    /**
     * In this method, I sorting product names form Z to A order.
     */
    public void sortNameZ_A() throws IOException{
        sortNameZ_A(tmp);
        System.out.println(tmp);
    }

    /**
     * In this method, I sorting product prices decreasing order.
     * @param tmp
     * @throws IOException
     */
    private void sortPrice_Dec(List<product>tmp)throws IOException{
        
        for (int i = 0; i<tmp.size()-1;i++) {
            int index = i;
    
            //find the smaller number in remaining sub array.
            for (int j = i+1; j<tmp.size();j++){
                if (tmp.get(j).getPrice() > tmp.get(index).getPrice()){
                    index = j;
                }
            }
    
            //swap the smallest number in remaining sub array.
            product smallerNumber = tmp.get(index);
            tmp.set(index,tmp.get(i));
            tmp.set(i,smallerNumber);
        }
    
    }

    /**
     * In this method, I sorting product prices decreasing order.
     */
    public void sortPrice_Dec() throws IOException{
        sortPrice_Dec(tmp);
        System.out.println(tmp);
    }

    /**
     * In this method, I sorting product discounts decreasing order.
     * @param tmp
     * @throws IOException
     */
    private void sortDiscount_Dec(List<product>tmp)throws IOException{
        
        for (int interval = tmp.size() / 2; interval > 0; interval /= 2) {
            for (int i = interval; i < tmp.size(); i += 1) {
            product temp = tmp.get(i);
            int j;
            for (j = i; j >= interval && tmp.get(j - interval).getDiscounted() < temp.getDiscounted(); j -= interval) {
              tmp.set(j,tmp.get(j - interval));
            }
                tmp.set(j,temp);
            }
          }
          
    }

    /**
     * In this method, I sorting product discounts decreasing order.
     */
    public void sortDiscount_Dec() throws IOException{
        sortDiscount_Dec(tmp);
        System.out.println(tmp);
    }

    /**
     * In this method, filtered price as lower and upper bound.
     * @param lower
     * @param upper
     */
    public void filterPrice(int lower,int upper){
        for (int i = 0; i<tmp.size();i++) {
            
            if (tmp.get(i).getPrice()<upper && tmp.get(i).getPrice()>lower){

                System.out.println(tmp.get(i));
            }
    
        }
    }

}





