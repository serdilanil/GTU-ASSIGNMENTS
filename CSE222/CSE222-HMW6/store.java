import java.io.*;
import java.util.*;


/**
 * In this class, Readed csv file and then writed product.txt file to product informations
 * And, entered the users information (ID and password).
 */
public class store{

    protected String password;
    long ID;
    String IDtrader;
    public store(String password,long ID){ //Constructor
       
        this.password = password;
        this.ID = ID;
    }

    /**
     * 
     * @return users password
     */
    public String getPassword(){
        return password;
    }
    
    /**
     * 
     * @param password
     */
    public void setPassword(String password){
        this.password = password;
    }

    /**
     * 
     * @return users ID
     */
    public long getID(){
        return ID;
    }
    
    /**
     * 
     * @param ID
     */
    public void setID(long ID){
        this.ID = ID;
    }

    /**
     * In this class I write the main menu.
     */
    public void Welcome(){
        System.out.println();
        System.out.println("******* WELCOME TO THE E-SHOPPING: *********");
        System.out.println("*** PLEASE SELECT THE NUMBER FOR MENU: ***");
        System.out.println(" 1)-Press 1 to If you are not a registered Customer: ");
        System.out.println(" 2)-Press 2 If you are already a registered customer: ");
        System.out.println(" 3)-Press 3 If you are not a registered trader:");
        System.out.println(" 4)-Press 4 If you are already a registered trader: ");
        System.out.println(" 0)-Press 0 If you want to exit the system: "); 
    }

    /**
     * In this method, I register the users.
     * @throws IOException
     */
    public void Register() throws IOException {
        long ID;
        String passW;
        Scanner in = new Scanner(System.in);
        BufferedWriter writer = new BufferedWriter(new FileWriter("costumer_users.txt",true));

        System.out.println("Enter Customer ID:");
        ID = in.nextLong();
        
        System.out.println("Enter Customer Password: ");
        in.nextLine();
        passW = in.nextLine();
        //this.setCustomer(passW,ID);
        writer.write("Id: "+ID+"\n");
        writer.write("Password: "+passW+"\n");
        
        writer.close();
    }           

    /**
     * In this method, I check if customers registered with this method are on file.
     * @param passW
     */
    public boolean checkSign(String passW) throws IOException{
        String line;
        
        BufferedReader reader = new BufferedReader(new FileReader("costumer_users.txt"));
        
        while((line = reader.readLine()) != null) {
            if(line.contains(passW)){
                reader.close();
                return true;
            }
        }
        reader.close();
        return false;
    }
    
    /**
     * In this method, I register traders.
     * @throws IOException
     */
    public void registerTrader() throws IOException {
        String Name;
        String passWord;
        Scanner in = new Scanner(System.in);
        BufferedWriter writer2 = new BufferedWriter(new FileWriter("trader_users.txt",true));

        System.out.println("Enter Trader Name:");
        Name = in.nextLine();

        System.out.println("Enter Trader Password: ");
        passWord = in.nextLine();
        String ID = randomTrader();
        System.out.println("Your ID: "+ ID);
        //this.setCustomer(passWord,Name);
        writer2.write("Id: "+ID+"\n");
        writer2.write("Name: "+ Name +"\n");
        writer2.write("Password: "+passWord+"\n");
        writer2.close();
    }           

    /**
     * In this method, I check if traders registered with this method are on file
     * @param passWord
     * @return
     * @throws IOException
     */
    public boolean checkSignTrader(String passWord) throws IOException{
        String line;
        
        BufferedReader reader2 = new BufferedReader(new FileReader("trader_users.txt"));
        
        while((line = reader2.readLine()) != null) {
            if(line.contains(passWord)){
                reader2.close();
                return true;
            }
        }
        reader2.close();
        return false;
    }

    /**
     * In this method, I read the 'trader_users.txt' ,I take these datas and I process its.
     * @param val
     * @return
     * @throws IOException
     */
    public boolean readFileTrader(String val) throws IOException{
        String data;

        BufferedReader reader = new BufferedReader(new FileReader("trader_users.txt"));

        while((data = reader.readLine()) != null){
            
            if(data.contains(val)){
                reader.close();
                return true;
            }

        }
        reader.close();
        return false;
    }
    
    /**
     * In this method, I generate random ID for traders in trader_users.txt.
     * @return
     * @throws IOException
     */
    private String randomTrader() throws IOException{

        StringBuilder id = new StringBuilder();
        
        String numbers = "1234567890";
        Random random = new Random();
        int length = 8;
        
        while(readFileTrader(id.toString())) {
            id = new StringBuilder();
            for (int i = 0; i < length; i++) {
                int index = random.nextInt(numbers.length());
                char randomChar = numbers.charAt(index);
                id.append(randomChar);
            }
        }
        return id.toString();

    }


    /**
     * In this method , I generate password for traders in trader_user.txt.
     * @return
     * @throws IOException
     */
    private String randomPass() throws IOException{

        StringBuilder id = new StringBuilder();
        String chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        Random random = new Random();
        int length = 6;
        while (readFileTrader(id.toString())) {
            id = new StringBuilder();
            for (int i = 0; i < length; i++) {
                int index = random.nextInt(chars.length());
                char randomChar = chars.charAt(index);
                id.append(randomChar);
            }
        }
        return id.toString();

    }


    
    /*public void setCustomer(String password,long ID){ //Constructor
        this.password = password;
        this.ID = ID;

    }*/

    /**
     * In this class ,readed the product informations from csv file and writed product.txt file.
     */
    public  void productFile(){
        String path = "e-commerce-samples.csv";
        String line = "";
       
        try{
            BufferedReader br = new BufferedReader(new FileReader(path));
            
            FileWriter f = new FileWriter("product.txt");
            
        
            br.readLine();
            
            while((line = br.readLine()) != null ){
                String[] values = line.split(";");
                
                f.write("\n" +"Id: " + values[0]+ "\n" + "Name: " + values[1] + "\n" + "Category: "+ values[2] + "\n" + "Price: "
                + values[3] + "\n" + "Discounted: "+ values[4] + "\n"+ "Description: " + values[5] + "\n"  + "Trader: " + values[6]+ "\n");
                

                if(!readFileTrader(values[6])){
                   
                    String ID = randomTrader();
                    String passWord = randomPass();
                    BufferedWriter writer2 = new BufferedWriter(new FileWriter("trader_users.txt",true));

                    writer2.write("Id : "+ ID +"\n");
                    writer2.write("Name : "+ values[6] +"\n");
                    writer2.write("Password : "+passWord+"\n");
                    writer2.close();
                }
               
            }
            f.close();
            br.close();
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }catch(IOException e){
            e.printStackTrace();
        }
    
    
    }


}