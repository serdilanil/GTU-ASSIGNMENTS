import java.util.*;

    /**
    * In this class, I have defined a 4-dimensional array to hold furniture information. This information is furniture type, color, model and number. 
    */
    public class Store implements IstoreInfo{
    
    /** Represent Furniture stock information,customer register process,some menu entry and entry notification.
    */
    
    int [][][] shrink = new int [5][][];
    int [][][] shrink2 = new int [5][][];
    int [][][] shrink3 = new int [5][][];
    int [][][] shrink4 = new int [5][][];
    int name,color,model,amount;

    KWLinkedList<Branch> branch = new KWLinkedList<Branch>();


    public KWLinkedList<Branch> getBranch(){
        return branch;
    }

    protected String nameSurname,eposta,password;
    int Bookcase;
    int Cabine;
    int Chairs;
    int Table;
    int Desk;

    public Store(String nameSurname,String eposta,String password){ //Constructor
        this.nameSurname = nameSurname;
        this.eposta = eposta;
        this.password = password;
    }
     /**
     * Show the First menu for the users.
     */
    @Override
    public void Welcome(){
        System.out.println();
        System.out.println("*******WELCOME TO THE FURNITURE STORE:*********");
        System.out.println("***PLEASE SELECT THE NUMBER FOR MENU:***");
        System.out.println(" 1)-Press 1 to New Register: ");
        System.out.println(" 2)-Press 2 Already Customer: ");
        System.out.println(" 3)-Press 3 if you are Branch Employee: ");
        System.out.println(" 4)-Press 4 if you are Administrator: ");
        System.out.println(" 0)-Press 0 if you want to exit the store: "); 
    }
    
    /** In this function,
     * If the customer registration is successful, the screen recording completed text is printed.
     */
    @Override
    public void registerCustomer(){
        System.out.println("YOUR REGISTRATION HAS BEEN COMPLETED.YOU CAN LOG IN TO THE SYSTEM With The Password You Set. ");
    }

    /** In this function,
    * If the customer registration is successful, the screen recording completed text is printed.
    */
    @Override
    public void loginAccount(){
        System.out.println("THE SYSTEM HAS BEEN LOGGED IN BY EMPLOYEES.");
    }

    /** In this function,
    * This function allows the customer to enter the information required to register in the system.
    */
    @Override
    public void Register(){
        String nameSur;
        String eMail;
        String passW;
        Scanner in = new Scanner(System.in);
        Customer object;
                
                System.out.println("Enter Customer name:");
                nameSur = in.next();
                System.out.println("Enter Customer Eposta: ");
                eMail = in.next();
                System.out.println("Enter Customer Password: ");
                passW = in.next();
                this.setAccount(nameSur,eMail,passW);
    }        

    public String getnameSurname(){
        return nameSurname;
    }

    /**
     * Set the name or surname of the administrator,Employee or Customer existing on this Store.
     * @param nameSurname set the user information.
     */
    public void setnameSurname(String nameSurname){
        this.nameSurname = nameSurname;

    }
    
    /**
     * Gets the limit of the elements existing on this Collection.
     * @return eposta for register the system for customer.
     */
    public String getEposta(){
        return eposta;
    }
     
    /**
     * Set the eposta as string of Customer existing on this Store.
     * @param eposta set the customer information.
     */
    public void setEposta(String eposta){
        this.eposta = eposta;
    }

    /**
     * Gets the password of the user existing on Store.
     * @return password for register the system for customer,employee and administrator.
     */
    public String getPassword(){
        return password;
    }
    
    /**
     * Set the eposta as string of Customer existing on this Store.
     * @param password set the customer,branch employee and administrator information.
     */
    public void setPassword(String password){
        this.password = password;
    }
    
    /**
     * Gets the password of the user existing on Store.
     * @return password for register the system for customer,employee and administrator.
     */
    public String enterPassword(){
        return this.password;
    }


    public void setAccount(String name,String eposta,String password){ //Constructor
        this.nameSurname = name;
        this.eposta = eposta;
        this.password = password;

    }

    /** In this function,
     * I myself assigned values to 3-dimensional arrays for the number of furniture and features.
     * for example(1-Furnitures,2-Model,3-Color)
     */
    @Override
    public void stockTotal(){
    
    
    shrink[0] = new int[7][5];
    shrink[1] = new int [5][4];
    shrink[2] = new int [10][4];
    shrink[3] = new int [12][1];
    shrink[4] = new int [12][1];
        
        int[] array = new int[5];
        

        for(int i=0;i<shrink.length;i++){
            for(int j=0;j<shrink[i].length;j++){
                for(int k=0;k<shrink[i][j].length;k++){
                    shrink[i][j][k] = 5;
                }
            }
        }
        
        
        shrink2[0] = new int[7][5];
        shrink2[1] = new int [5][4];
        shrink2[2] = new int [10][4];
        shrink2[3] = new int [12][1];
        shrink2[4] = new int [12][1];

        
        for(int i=0;i<shrink2.length;i++){
            for(int j=0;j<shrink2[i].length;j++){
                for(int k=0;k<shrink2[i][j].length;k++){
                    shrink2[i][j][k] = 5;
                }
            }
        }
        
        

        shrink3[0] = new int[7][5];
        shrink3[1] = new int [5][4];
        shrink3[2] = new int [10][4];
        shrink3[3] = new int [12][1];
        shrink3[4] = new int [12][1];


        for(int i=0;i<shrink3.length;i++){
            for(int j=0;j<shrink3[i].length;j++){
                for(int k=0;k<shrink3[i][j].length;k++){
                    shrink3[i][j][k] = 5;
                }
            }
        }

        shrink4[0] = new int[7][5];
        shrink4[1] = new int [5][4];
        shrink4[2] = new int [10][4];
        shrink4[3] = new int [12][1];
        shrink4[4] = new int [12][1];


        for(int i=0;i<shrink4.length;i++){
            for(int j=0;j<shrink4[i].length;j++){
                for(int k=0;k<shrink4[i][j].length;k++){
                    shrink4[i][j][k] = 5;
                }
            }
        }


}


/*
*In this method, I reduce the 3-dimensional array to a one-dimensional array, 
*at the same time I apply ArrayList here.
*/
public void rePlace(){


    branch.add(0,new Branch(shrink));
    branch.add(1,new Branch(shrink2));
    branch.add(2,new Branch(shrink3));
    branch.add(3,new Branch(shrink4));
}

}