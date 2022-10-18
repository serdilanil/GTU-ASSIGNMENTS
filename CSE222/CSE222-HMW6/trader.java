import java.io.*;
import java.util.LinkedList;
import java.util.Random;


/**
 * In this class, the transactions to be made by the trader are carried out..
 */
public class trader extends store{


    public trader(String password, long ID){
        super(password,ID);
    }

    /**
     * In this method, added new product in product.txt file.
     * @param name
     * @param category
     * @param price
     * @param discounted
     * @param description
     * @param trader
     */
    public void addProduct(String name,String category,int price,int discounted,String description,String trader){
        FileWriter fw = null;
        
        String randChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


        StringBuilder salt = new StringBuilder();
        Random rand = new Random();
        
        while(salt.length()<16){
            int index = (int) (rand.nextFloat() * randChars.length());
            salt.append(randChars.charAt(index));
        }

        String saltStr = salt.toString();
        System.out.println();
        System.out.println("THE PRODUCT IS ADDED, YOU CAN SEARCH THIS PRODUCT IN FILE BY THIS ID: "+saltStr);
        
        try{
            fw = new FileWriter("product.txt",true);
            fw.write("\n Id: "+saltStr);
            fw.write("\n Name: "+name);
            fw.write("\n Category: "+category);
            fw.write("\n Price: "+price);
            fw.write("\n Discounted: "+discounted);
            fw.write("\n Description: "+description);
            fw.write("\n Trader: "+trader);
            
            fw.close();

        }catch(IOException ex){
            System.out.println("Error");
        }

    }

    /**
     * In this method, removed the product which in the product.txt file.
     * It is enough to enter the ID of the product you want to delete.
     * @param ID
     * @throws IOException
     */
    public void removeProduct(String ID) throws IOException{
        String line;

        File product = new File("product.txt");
        File temp = new File("deleted.txt");
        temp.createNewFile();
        BufferedReader reader = new BufferedReader(new FileReader("product.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("deleted.txt"));

        while((line = reader.readLine()) != null) {
            if(line.contains(ID)) {
                for(int i=0;i<7;i++){
                    reader.readLine();
                }              
            }
        
            else{
                
                writer.write(line + "\n");
            }
        }

        reader.close();
        writer.close();
        product.delete();
        temp.renameTo(product);

    }

    /**
     * In this method, you can change the name and price of the product you want.
     * @param ID
     * @param name
     * @param price
     * @throws IOException
     */
    public void editProduct(String ID,String name,int price)throws IOException{
        
        String line;
        File product = new File("product.txt");
        File temp = new File("deleted.txt");
        temp.createNewFile();
        BufferedReader reader = new BufferedReader(new FileReader("product.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("deleted.txt"));

        while((line = reader.readLine()) != null){
            if(line.contains(ID)){
        
                writer.write(line + "\n");
                reader.readLine();
                writer.write("Name: "+ name + "\n");
                writer.write(reader.readLine()+"\n");
                reader.readLine();
                writer.write("Price: "+ price + "\n");

            }
            
            else{
                writer.write(line + "\n");
            }
        }

        reader.close();
        writer.close();
        product.delete();
        temp.renameTo(product);
    
    }

    /**
     * In this method, we can see the orders that customers print to the orders.txt file.
     * @throws IOException
     */
    public void showOrders() throws IOException{

        LinkedList<String>record = new LinkedList<String>();
        String line ="";
        BufferedReader br = new BufferedReader(new FileReader("orders.txt"));

        br.readLine();
        
        while((line = br.readLine()) != null ){
        
                record.add(line+"\n");
        }

        br.close();

        System.out.println(record);

    }

    /**
     * In this method, we cancel orders from customers or fulfill that order.
     * @param situation
     * @param ID
     * @throws IOException
     */
    public void confirmOrder(int situation,String ID) throws IOException{

        File orders = new File("orders.txt");
        File temp = new File("deleted.txt");
        String line;
        temp.createNewFile();
        BufferedReader br = new BufferedReader(new FileReader("orders.txt"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("deleted.txt"));

        br.readLine();

        while((line = br.readLine()) != null){
            
            if(situation == 1){
                if(line.contains(ID)){
                    
                
                    writer.write(line + "\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write("Situation: CONFIRM ORDER" + "\n");
                    br.readLine();
                
                }
                
                else{
                    writer.write(line + "\n");
                }
            }
        
            else if(situation == 0){

                if(line.contains(ID)){
                    
                
                    writer.write(line + "\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write(br.readLine()+"\n");
                    writer.write("Situation: CANCELLED ORDER" + "\n");
                    br.readLine();
                
                }
                
                else{
                    writer.write(line + "\n");
                }

            }
        }
        br.close();
        writer.close();
        orders.delete();
        temp.renameTo(orders);
    
    }

}