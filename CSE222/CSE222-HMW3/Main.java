import java.util.*;


public class Main{

    public static  void main(String[] args){
        
        int[][][] shrink = new int[5][][];
        int[][][] shrink2 = new int[5][][];
        int[][][] shrink3 = new int[5][][];
        int[][][] shrink4 = new int[5][][];
        


        shrink[0] = new int[7][5];
        shrink[1] = new int [5][4];
        shrink[2] = new int [10][4];
        shrink[3] = new int [12][1];
        shrink[4] = new int [12][1];

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
                    shrink2[i][j][k] = 4;
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
                    shrink3[i][j][k] = 3;
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

        Branch var = new Branch(shrink);
        Branch var2 = new Branch(shrink2);
        Branch var3 = new Branch(shrink3);
        Branch var4 = new Branch(shrink4);

        int selection;
        String shopping;
        char choice;
        String Epassword;
        Store a = new Store("Anil","@asfafaf","Admin");
        a.stockTotal();
        a.rePlace();
        
        Store b = new Store("Anil","@asfafaf","Admin");
        b.stockTotal();
        b.rePlace();
        Customer c = new Customer("Anil","@asfafaf","safsaf");
        Store d = new Customer("Anil","@asfafaf","safsaf");  //Polymorphism and overriding
        Customer e = new Customer("Ahmet","@asfaf23af","s22afsaf");
        Employee a1 = new Employee("Ali", "@ali02","1234");
        Administrator a2 = new Employee("Ayşe", "@ayse0221", "123");
        Administrator a3 = new Employee("Mehmet", "@mehmet221", "12345");
        Administrator a4 = new Employee("Hasan", "@Hasan2141", "123asf45");
        Administrator a5 = new Employee("Mustafa", "@Mustafa221", "M1234saf5");
        Administrator adm = new Employee("SAcit", "@sacit2asf21", "M1f5");

        KWArrayList<Administrator> AdministratorArray; 
        AdministratorArray = new KWArrayList<Administrator>();
        KWArrayList<Store> StoreArray;
        StoreArray = new KWArrayList<Store>();
        StoreArray.add(a);
        StoreArray.add(b);
        AdministratorArray.add(a1);
        AdministratorArray.add(a2);
        AdministratorArray.add(a3);
        AdministratorArray.add(a4);
        AdministratorArray.add(a5);
        AdministratorArray.add(adm);
        
        KWArrayList<Employee>EmployeeArray;
        EmployeeArray = new KWArrayList<Employee>();
        
       
            a.Welcome();
            a.stockTotal();
            System.out.println();
            
                                
            //a.Register();      
            System.out.println();
            a.registerCustomer();
               
                
            a.getPassword(); 
            c.loginAccount();
            
                   
            System.out.println();
            System.out.println("1-)IF YOU WANT TO KNOW HOW MANY FURNITURE IS IN WHICH STORE, PLEASE PRESS '1'.");
            System.out.println("2-)IF YOU WANT TO SHOP AT THE STORE, PRESS '2'.");
            System.out.println("3-)IF YOU WANT TO SEE THE PRODUCTS IN YOUR SHOPPING CART, press '3'.");
        
                
            System.out.println("Please write that which you furniture you want "+"FOR EXAMPLE: "+"("+"You can write:"+ " chairs "+" desks "+" tables "+" bookcases "+" cabinets "+")");
            System.out.println();
            System.out.println("PLEASE ENTER THE FURNITURE YOU WANT WHICH IN CATALOG:");
                    
                                       
                            
            System.out.println("Sum of the chairs are in Branch1 :" + var.getStock("chair"));
            System.out.println("Sum of the chairs are in Branch2 :" + var2.getStock("chair"));
            System.out.println("Sum of the chairs are in Branch3 :" + var3.getStock("chair"));
            System.out.println("Sum of the chairs are in Branch4 :" + var4.getStock("chair"));
            
                                
                                                        
                
            System.out.println("Sum of the desks are in Branch1 :" + var.getStock("desk"));
            System.out.println("Sum of the desks are in Branch2 :" + var2.getStock("desk"));
            System.out.println("Sum of the desks are in Branch3 :" + var3.getStock("desk"));
            System.out.println("Sum of the desks are in Branch4 :" + var4.getStock("desk"));


                           

            System.out.println("Sum of the tables are in Branch1 :" + var.getStock("table"));
            System.out.println("Sum of the tables are in Branch2 :" + var2.getStock("table"));
            System.out.println("Sum of the tables are in Branch3 :" + var3.getStock("table"));
            System.out.println("Sum of the tables are in Branch4 :" + var4.getStock("table"));
                
                                
                
            System.out.println("Sum of the bookcases are in Branch1 :" + var.getStock("bookcase"));
            System.out.println("Sum of the bookcases are in Branch2 :" + var2.getStock("bookcase"));
            System.out.println("Sum of the bookcases are in Branch3 :" + var3.getStock("bookcase"));
            System.out.println("Sum of the bookcases are in Branch4 :" + var4.getStock("bookcase"));
        
            System.out.println("Sum of the cabinets are in Branch1 :" + var.getStock("cabinet"));
            System.out.println("Sum of the cabinets are in Branch2 :" + var2.getStock("cabinet"));
            System.out.println("Sum of the cabinets are in Branch3 :" + var3.getStock("cabinet"));
            System.out.println("Sum of the cabinets are in Branch4 :" + var4.getStock("cabinet"));

            
                            
            c.choiceCatalog(1,2,3,4,a.getBranch().get(0));       
            System.out.println(c.amountPocket());
        
                                         
                    
            b.getPassword();
            System.out.println();
            b.loginAccount();
            System.out.println();
            System.out.println("1-) PLEASE PRESS '1' TO QUERY THE PRODUCTS IN STOCK .");
            System.out.println("2-) PLEASE PRESS '2' TO REQUEST A PRODUCT FROM THE MANAGER.");
            System.out.println("3-) ENTER THE PASSWORD OF THE CUSTOMER YOU WANT AND PRESS '3' TO VIEW THE CUSTOMER'S SHOPPING CART. ");
            System.out.println("4-) PLEASE PRESS '4' TO ENTER THE CUSTOMER'S PASSWORD AND SHOP INSTEAD OF THE CUSTOMER.");

                       
            System.out.println("Sum of the chairs are in Branch1 :" + var.getStock("chair"));
            System.out.println("Sum of the chairs are in Branch2 :" + var2.getStock("chair"));
            System.out.println("Sum of the chairs are in Branch3 :" + var3.getStock("chair"));
            System.out.println("Sum of the chairs are in Branch4 :" + var4.getStock("chair"));
            System.out.println("Sum of the desks are in Branch1 :" + var.getStock("desk"));
            System.out.println("Sum of the desks are in Branch2 :" + var2.getStock("desk"));
            System.out.println("Sum of the desks are in Branch3 :" + var3.getStock("desk"));
            System.out.println("Sum of the desks are in Branch4 :" + var4.getStock("desk"));
            System.out.println("Sum of the tables are in Branch1 :" + var.getStock("table"));
            System.out.println("Sum of the tables are in Branch2 :" + var2.getStock("table"));
            System.out.println("Sum of the tables are in Branch3 :" + var3.getStock("table"));
            System.out.println("Sum of the tables are in Branch4 :" + var4.getStock("table"));
            System.out.println("Sum of the bookcases are in Branch1 :" + var.getStock("bookcase"));
            System.out.println("Sum of the bookcases are in Branch2 :" + var2.getStock("bookcase"));
            System.out.println("Sum of the bookcases are in Branch3 :" + var3.getStock("bookcase"));
            System.out.println("Sum of the bookcases are in Branch4 :" + var4.getStock("bookcase"));
            System.out.println("Sum of the cabinets are in Branch1 :" + var.getStock("cabinet"));
            System.out.println("Sum of the cabinets are in Branch2 :" + var2.getStock("cabinet"));
            System.out.println("Sum of the cabinets are in Branch3 :" + var3.getStock("cabinet"));
            System.out.println("Sum of the cabinets are in Branch4 :" + var4.getStock("cabinet"));


                               
            a1.callManager();
    
    
            System.out.println("Items in the customer's shopping cart: "+c.amountPocket());
          
            a.getPassword();
            
            
                    
            System.out.println("PLEASE ENTER THE PASSWORD TO LOGIN TO THE SYSTEM.");
            System.out.println("Small Tip -> Password is : Admin");
            
                    b.getPassword();
                    a.loginAccount();    
                    System.out.println();
                    System.out.println("Current Number Of Branch Employee: " + Administrator.numberEmployee());
                    System.out.println("Current Number Of Branch: " + Administrator.numberBranch());
                    System.out.println();
                    
                    System.out.println("1-)IF YOU WANT TO REMOVE A BRANCH EMPLOYEE, PRESS 'q' :");
                    System.out.println("2-)IF YOU WANT TO ADD A BRANCH EMPLOYEE, PRESS 'w' :");
                    System.out.println("3-)IF YOU WANT TO ADD A BRANCH, PRESS 's' :");
                    System.out.println("4-)IF YOU WANT TO REMOVE A BRANCH, PRESS 'a' :");
                    

                    a1.exit(); //quit employee
                    System.out.println("Current Number Of Branch Employee: " + Administrator.numberEmployee());
                
                
                
                    Administrator a6 = new Administrator("Anil", "@sAnil221", "Sanil34saf5");
                    System.out.println("Current Number Of Branch Employee: " + Administrator.numberEmployee());
                
                    a1.quitBranch();  //quit branch
                    System.out.println("Current Number Of Branch : " + Administrator.numberBranch());

                    
                    Administrator b5 = new Administrator("5", "@M5", "M125");
                    System.out.println("Current Number Of Branch : " + Administrator.numberBranch());
                
                    
                    boolean quit = false;
       
                    while(!quit){
                        a.Welcome();
                        a.stockTotal();
                        System.out.println();
                        Scanner input = new Scanner(System.in);
                        selection = input.nextInt();
                        
                    try{
                        switch(selection){
                                    /** 
                                    * The place where customer transactions are made.
                                    *In this place customer register the store first time
                                    */
            
                            case 1:                 
                                a.Register();      
                                System.out.println();
                                a.registerCustomer();
                            break;
            
                            case 2:
                                int select;
                                System.out.println("Please enter the Password:");
                                Scanner input2 = new Scanner(System.in);
                                    /** 
                                    * In this place, if customer registered already, he/she can process in store system.
                                    *If the password she/he registered with and the password she/he entered into the system is correct, she/he can perform transactions on the system
                                    */
                                Epassword = input2.nextLine();            
                                if(Epassword.equals(a.getPassword())){   
                                    c.loginAccount();
                                
                               
                                System.out.println();
                                System.out.println("1-)IF YOU WANT TO KNOW HOW MANY FURNITURE IS IN WHICH STORE, PLEASE PRESS '1'.");
                                System.out.println("2-)IF YOU WANT TO SHOP AT THE STORE, PRESS '2'.");
                                System.out.println("3-)IF YOU WANT TO SEE THE PRODUCTS IN YOUR SHOPPING CART, press '3'.");
            
                                select = input2.nextInt();
                            
                            
                                switch(select){
                                    
                                    case 1:
                                        System.out.println("Please write that which you furniture you want "+"FOR EXAMPLE: "+"("+"You can write:"+ " chairs "+" desks "+" tables "+" bookcases "+" cabinets "+")");
                                        System.out.println();
                                        System.out.println("PLEASE ENTER THE FURNITURE YOU WANT WHICH IN CATALOG:");
                                    
                                    Scanner input3 = new Scanner(System.in);
                                    shopping = input3.nextLine();
                                
                                    switch(shopping){   //Here, if the customer chooses case 1, she/he will be able to see how many furniture in which store.
                                    
                                            case "chairs":                    
                                        
                                            System.out.println("Sum of the chairs are in Branch1 :" + var.getStock("chair"));
                                            System.out.println("Sum of the chairs are in Branch2 :" + var2.getStock("chair"));
                                            System.out.println("Sum of the chairs are in Branch3 :" + var3.getStock("chair"));
                                            System.out.println("Sum of the chairs are in Branch4 :" + var4.getStock("chair"));
                                            
                                            
                                        break;
            
                                            case "desks":
                                                
                                            System.out.println("Sum of the desks are in Branch1 :" + var.getStock("desk"));
                                            System.out.println("Sum of the desks are in Branch2 :" + var2.getStock("desk"));
                                            System.out.println("Sum of the desks are in Branch3 :" + var3.getStock("desk"));
                                            System.out.println("Sum of the desks are in Branch4 :" + var4.getStock("desk"));
            
            
                                        break;
            
                                            case "tables":
            
                                            System.out.println("Sum of the tables are in Branch1 :" + var.getStock("table"));
                                            System.out.println("Sum of the tables are in Branch2 :" + var2.getStock("table"));
                                            System.out.println("Sum of the tables are in Branch3 :" + var3.getStock("table"));
                                            System.out.println("Sum of the tables are in Branch4 :" + var4.getStock("table"));
                                             
                                                
                                        break;
            
                                            case "bookcases":
                                                
                                                
                                            System.out.println("Sum of the bookcases are in Branch1 :" + var.getStock("bookcase"));
                                            System.out.println("Sum of the bookcases are in Branch2 :" + var2.getStock("bookcase"));
                                            System.out.println("Sum of the bookcases are in Branch3 :" + var3.getStock("bookcase"));
                                            System.out.println("Sum of the bookcases are in Branch4 :" + var4.getStock("bookcase"));
                                        
                                        break;
            
                                            case "cabinets":
                                                System.out.println("Sum of the cabinets are in Branch1 :" + var.getStock("cabinet"));
                                                System.out.println("Sum of the cabinets are in Branch2 :" + var2.getStock("cabinet"));
                                                System.out.println("Sum of the cabinets are in Branch3 :" + var3.getStock("cabinet"));
                                                System.out.println("Sum of the cabinets are in Branch4 :" + var4.getStock("cabinet"));
            
                                        break;
            
                                        default:
                                            throw new Exception("Invalid Value");                                    
                                       
                                    }
                                
                                    break;
                                
                                    case 2: //if you want to shop in store press 2.
                                        c.choiceCatalog(1,2,3,4,a.getBranch().get(0));       
                                        System.out.println(c.amountPocket());
                                    break;
                                
                                
                                    case 3:  //Here she/he will be able to see how many products she/he has bought and what product features she/he has received.
                                        System.out.println(c.amountPocket());
                                    break;
                                }
                            
                                }  //If customer password is true.
                                                    
                                                else{
                                                    System.out.println("Wrong password, please try again !!!");
                                                }
                            break;
                        
                            case 3:   //In this case,only can be enter the Branch Employee.
                                int option;
                                System.out.println("Please enter the Password:(If you are an administrator or a store employee, you can log in by typing "+"' Admin '" +" in the password. )");
                                Scanner input7 = new Scanner(System.in);
                                Epassword = input7.nextLine();
                                if(Epassword.equals(b.getPassword())){
                                    System.out.println();
                                    b.loginAccount();
                                    System.out.println();
                                    System.out.println("1-) PLEASE PRESS '1' TO QUERY THE PRODUCTS IN STOCK .");
                                    System.out.println("2-) PLEASE PRESS '2' TO REQUEST A PRODUCT FROM THE MANAGER.");
                                    System.out.println("3-) ENTER THE PASSWORD OF THE CUSTOMER YOU WANT AND PRESS '3' TO VIEW THE CUSTOMER'S SHOPPING CART. ");
                                    System.out.println("4-) PLEASE PRESS '4' TO ENTER THE CUSTOMER'S PASSWORD AND SHOP INSTEAD OF THE CUSTOMER.");
            
                                    option = input.nextInt();
                                    
                                        switch(option){  //branch employee can see the stock of furniture of the stores.
                                            case 1:
                                                System.out.println("Sum of the chairs are in Branch1 :" + var.getStock("chair"));
                                                System.out.println("Sum of the chairs are in Branch2 :" + var2.getStock("chair"));
                                                System.out.println("Sum of the chairs are in Branch3 :" + var3.getStock("chair"));
                                                System.out.println("Sum of the chairs are in Branch4 :" + var4.getStock("chair"));
                                                System.out.println("Sum of the desks are in Branch1 :" + var.getStock("desk"));
                                                System.out.println("Sum of the desks are in Branch2 :" + var2.getStock("desk"));
                                                System.out.println("Sum of the desks are in Branch3 :" + var3.getStock("desk"));
                                                System.out.println("Sum of the desks are in Branch4 :" + var4.getStock("desk"));
                                                System.out.println("Sum of the tables are in Branch1 :" + var.getStock("table"));
                                                System.out.println("Sum of the tables are in Branch2 :" + var2.getStock("table"));
                                                System.out.println("Sum of the tables are in Branch3 :" + var3.getStock("table"));
                                                System.out.println("Sum of the tables are in Branch4 :" + var4.getStock("table"));
                                                System.out.println("Sum of the bookcases are in Branch1 :" + var.getStock("bookcase"));
                                                System.out.println("Sum of the bookcases are in Branch2 :" + var2.getStock("bookcase"));
                                                System.out.println("Sum of the bookcases are in Branch3 :" + var3.getStock("bookcase"));
                                                System.out.println("Sum of the bookcases are in Branch4 :" + var4.getStock("bookcase"));
                                                System.out.println("Sum of the cabinets are in Branch1 :" + var.getStock("cabinet"));
                                                System.out.println("Sum of the cabinets are in Branch2 :" + var2.getStock("cabinet"));
                                                System.out.println("Sum of the cabinets are in Branch3 :" + var3.getStock("cabinet"));
                                                System.out.println("Sum of the cabinets are in Branch4 :" + var4.getStock("cabinet"));
            
            
                                            break;
            
            
                                            case 2:
                                                a1.callManager();
                                            break;
                                        
                                        
                                            case 3:
                                                System.out.println("Items in the customer's shopping cart: "+c.amountPocket());
                                            break;
                                        
                                            case 4:
                                                System.out.println("PLEASE ENTER THE PASSWORD OF THE CUSTOMER THAT YOU WILL ENTER THE ACCOUNT.");
                                                Scanner input8 = new Scanner(System.in);
                                                Epassword = input8.nextLine();
                                                if(Epassword.equals(a.getPassword())){
                                                    //c.choiceCatalog(a.name,a.getBranch().get(0));       
                                                    System.out.println(c.amountPocket());
                                                }
                                                System.out.println("Items in the customer's  NEW shopping cart: "+c.amountPocket());
                                                break;
                                        
                                            default:
                                                throw new Exception("Invalid Value !!!");
                                        
                                        }
                                    
                                }
                                
                            break;
                        
                            case 4:  //Only can be enter and process Administrator in case 4.
                                
                                System.out.println("PLEASE ENTER THE PASSWORD TO LOGIN TO THE SYSTEM.");
                                System.out.println("(Small Tip -> Password is : Admin)");
                                Scanner input5 = new Scanner(System.in);
                                Epassword = input5.nextLine();
                                    if(Epassword.equals(b.getPassword())){
                                        a.loginAccount();    
                                        System.out.println();
                                        System.out.println("Current Number Of Branch Employee: " + Administrator.numberEmployee());
                                        System.out.println("Current Number Of Branch: " + Administrator.numberBranch());
                                        System.out.println();
                                        
                                        System.out.println("1-)IF YOU WANT TO REMOVE A BRANCH EMPLOYEE, PRESS 'q' :");
                                        System.out.println("2-)IF YOU WANT TO ADD A BRANCH EMPLOYEE, PRESS 'w' :");
                                        System.out.println("3-)IF YOU WANT TO ADD A BRANCH, PRESS 's' :");
                                        System.out.println("4-)IF YOU WANT TO REMOVE A BRANCH, PRESS 'a' :");
                                        Scanner input6 = new Scanner(System.in);
                                        choice = input6.next().charAt(0);
                                   
                                        switch(choice){
                                    
                                            case 'q':
                                                a1.exit(); //quit employee
                                                System.out.println("Current Number Of Branch Employee: " + Administrator.numberEmployee());
                                            break;
                                            
                                            case 'w':   //hire employee
                                                a6 = new Administrator("Anil", "@sAnil221", "Sanil34saf5");
                                                System.out.println("Current Number Of Branch Employee: " + Administrator.numberEmployee());
                                            break;
                                            
                                            case 'a':
                                                a1.quitBranch();  //quit branch
                                                System.out.println("Current Number Of Branch : " + Administrator.numberBranch());
                                            break;
            
                                            case 's': //add branch
                                                //Administrator b5 = new Branch("5", "@M5", "M125");
                                                System.out.println("Current Number Of Branch : " + Administrator.numberBranch());
                                            break;
                                            
                                            default:
                                                throw new Exception("Invalid Value");
                                           
                                        }
                                   
                                    
                                    }
                                            else{
                                                System.out.println("PLEASE ENTER THE CORRECT PASSWORD !!!");
                                            }
                            break;
                        
                            case 0:  //exit the program.
                                quit = true;
                            break;
            
                            default:
                                throw new Exception("Invalid Value !!!");
                        }
                    }catch(Exception exception){
                        System.out.println(exception.getMessage());
                    }
                        
                    }
                    System.out.println("HAVE A GOOD DAY. WE HOPE YOU ENJOYED IT.!!!");     
        
       
    }

}