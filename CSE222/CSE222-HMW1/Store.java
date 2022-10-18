import java.util.*;

    /**
    * In this class, I have defined a 4-dimensional array to hold furniture information. This information is furniture type, color, model and number. 
    */
    public class Store implements IstoreInfo{
    
    /** Represent Furniture stock information,customer register process,some menu entry and entry notification.
    */
    protected int Branch[][][][] = new int[5][5][0][0];
    

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
     * I myself assigned values to 4-dimensional arrays for the number of furniture and features.
     * for example(1-Branch count,2-Furnitures,3-Model,4-Color)
     */
    @Override
    public void stockTotal(){
    

        int[] array = new int[5];
        
        Branch[0][0] = new int[7][5];
        Branch[0][1] = new int [5][4];
        Branch[0][2] = new int [10][4];
        Branch[0][3] = new int [12][1];
        Branch[0][4] = new int [12][1];

        
        for(int i=0;i<5;i++){

            for(int j=0;j<Branch[0][i].length;j++){

                for(int k=0;k<Branch[0][i][j].length;k++){

                    Branch[0][i][j][k] = 5;
                }
            }
        
        }
        
        
        
        Branch[1][0] = new int[7][5];
        Branch[1][1] = new int [5][4];
        Branch[1][2] = new int [10][4];
        Branch[1][3] = new int [12][1];
        Branch[1][4] = new int [12][1];

        for(int i=0;i<5;i++){
            for(int j=0;j<Branch[1][i].length;j++){
                
                for(int k=0;k<Branch[1][i][j].length;k++){

                    Branch[1][i][j][k] = 3;
                }
            }
        
        }
        
        Branch[2][0] = new int[7][5]; //office chairs 
        Branch[2][1] = new int [5][4]; //office desks 
        Branch[2][2] = new int [10][4]; //meeting tables
        Branch[2][3] = new int [12][1]; //bookcases 
        Branch[2][4] = new int [12][1]; //office cabinets

        for(int i=0;i<5;i++){

            for(int j=0;j<Branch[2][i].length;j++){

                for(int k=0;k<Branch[2][i][j].length;k++){

                    Branch[2][i][j][k] = 4;
                }
            }
        
        }

        Branch[3][0] = new int[7][5];
        Branch[3][1] = new int [5][4];
        Branch[3][2] = new int [10][4];
        Branch[3][3] = new int [12][1];
        Branch[3][4] = new int [12][1];

        for(int i=0;i<5;i++){

            for(int j=0;j<Branch[3][i].length;j++){

                for(int k=0;k<Branch[3][i][j].length;k++){

                    Branch[3][i][j][k] = 1;
                }
            }
        
        }


}

}