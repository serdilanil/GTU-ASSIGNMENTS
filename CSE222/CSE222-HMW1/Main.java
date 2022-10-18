import java.util.*;


public class Main{

    public static  void main(String[] args){
    

        int selection;
        String shopping;
        char choice;
        String Epassword;
        Store a = new Store("Anil","@asfafaf","Admin");
        Store b = new Store("Anil","@asfafaf","Admin");
        Customer c = new Customer("Anil","@asfafaf","safsaf");
        Store d = new Customer("Anil","@asfafaf","safsaf");  //Polymorphism and overriding
        Employee a1 = new Employee("Ali", "@ali02","1234");
        Administrator a2 = new Employee("Ayşe", "@ayse0221", "123");
        Administrator a3 = new Employee("Mehmet", "@mehmet221", "12345");
        Administrator a4 = new Employee("Hasan", "@Hasan2141", "123asf45");
        Administrator a5 = new Employee("Mustafa", "@Mustafa221", "M1234saf5");
        Administrator b1 = new Branch("1", "@M1", "M12");
        Administrator b2 = new Branch("2", "@M2", "M12");
        Administrator b3 = new Branch("3", "@M3", "M12");
        Administrator b4 = new Branch("4", "@M4", "M12");
        int sum=0;
                int sum2=0;
                int sum3=0;
                int sum4=0;
                int sumD=0;
                int sumD2=0;
                int sumD3=0;
                int sumD4=0;
                int sumT=0;
                int sumT2=0;
                int sumT3=0;
                int sumT4=0;
                int sumB=0;
                int sumB2=0;
                int sumB3=0;
                int sumB4=0;
                int sumC=0;
                int sumC2=0;
                int sumC3=0;
                int sumC4=0;
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
                
                try{
                    switch(select){
                        
                        case 1:
                            System.out.println("Please write that which you furniture you want "+"FOR EXAMPLE: "+"("+"You can write:"+ " chairs "+" desks "+" tables "+" bookcases "+" cabinets "+")");
                            System.out.println();
                            System.out.println("PLEASE ENTER THE FURNITURE YOU WANT WHICH IN CATALOG:");
                            
                        Scanner input3 = new Scanner(System.in);
                        shopping = input3.nextLine();
                    try{
                        switch(shopping){   //Here, if the customer chooses case 1, she/he will be able to see how many furniture in which store.
                        
                            case "chairs":                    
                            
                            for (int i = 0; i < a.Branch[0][0].length ; i++){
                                    for(int j=0;j<a.Branch[0][0][i].length;j++){
                                        sum += a.Branch[0][0][i][j];
                                    }
                                }
                                
                                for (int i = 0; i < a.Branch[1][0].length ; i++){
                                    for(int j=0;j<a.Branch[1][0][i].length;j++){
                                        sum2 += a.Branch[1][0][i][j];
                                    }
                                }
                                for (int i = 0; i < a.Branch[2][0].length ; i++){
                                    for(int j=0;j<a.Branch[2][0][i].length;j++){
                                        sum3 += a.Branch[2][0][i][j];
                                    }
                                }
                                for (int i = 0; i < a.Branch[3][0].length ; i++){
                                    for(int j=0;j<a.Branch[3][0][i].length;j++){
                                        sum4 += a.Branch[3][0][i][j];
                                    }
                                }
                               
                                
                                System.out.println("Sum of the office Chairs are in Branch1:" + sum);
                                System.out.println("Sum of the office Chairs are in Branch2:" + sum2);
                                System.out.println("Sum of the office Chairs are in Branch3:" + sum3);
                                System.out.println("Sum of the office Chairs are in Branch4:" + sum4);
                            break;

                                case "desks":
                                    
                                for (int i = 0; i < a.Branch[0][1].length ; i++){
                                        for(int j=0;j<a.Branch[0][1][i].length;j++){
                                            sumD += a.Branch[0][1][i][j];
                                        }
                                    }
                                    
                                    for (int i = 0; i < a.Branch[1][1].length ; i++){
                                        for(int j=0;j<a.Branch[1][1][i].length;j++){
                                            sumD2 += a.Branch[1][1][i][j];
                                        }
                                    }
                                    for (int i = 0; i < a.Branch[2][1].length ; i++){
                                        for(int j=0;j<a.Branch[2][1][i].length;j++){
                                            sumD3 += a.Branch[2][1][i][j];
                                        }
                                    }
                                    for (int i = 0; i < a.Branch[3][1].length ; i++){
                                        for(int j=0;j<a.Branch[3][1][i].length;j++){
                                            sumD4 += a.Branch[3][1][i][j];
                                        }
                                    }
                                    
                                    
                                    System.out.println("Sum of the office Desks are in Branch1:" + sumD);
                                    System.out.println("Sum of the office Desks are in Branch2:" + sumD2);
                                    System.out.println("Sum of the office Desks are in Branch3:" + sumD3);
                                    System.out.println("Sum of the office Desks are in Branch4:" + sumD4);
                                    
                            break;

                                case "tables":

                                    for (int i = 0; i < a.Branch[0][2].length ; i++){
                                        for(int j=0;j<a.Branch[0][2][i].length;j++){
                                            sumT += a.Branch[0][2][i][j];
                                        }
                                    }
                                    
                                    for (int i = 0; i < a.Branch[1][2].length ; i++){
                                        for(int j=0;j<a.Branch[1][2][i].length;j++){
                                            sumT2 += a.Branch[1][2][i][j];
                                        }
                                    }
                                    for (int i = 0; i < a.Branch[2][2].length ; i++){
                                        for(int j=0;j<a.Branch[2][2][i].length;j++){
                                            sumT3 += a.Branch[2][2][i][j];
                                        }
                                    }
                                    for (int i = 0; i < a.Branch[3][2].length ; i++){
                                        for(int j=0;j<a.Branch[3][2][i].length;j++){
                                            sumT4 += a.Branch[3][2][i][j];
                                        }
                                    }
                                 
                                    System.out.println("Sum of the office Tables are in Branch1:" + sumT);
                                    System.out.println("Sum of the office Tables are in Branch2:" + sumT2);
                                    System.out.println("Sum of the office Tables are in Branch3:" + sumT3);
                                    System.out.println("Sum of the office Tables are in Branch4:" + sumT4);
                                    
                            break;

                                case "bookcases":
                                   
                                    
                                for (int i = 0; i < a.Branch[0][3].length ; i++){
                                        for(int j=0;j<a.Branch[0][3][i].length;j++){
                                            sumB += a.Branch[0][3][i][j];
                                        }
                                    }
                                    
                                    for (int i = 0; i < a.Branch[1][3].length ; i++){
                                        for(int j=0;j<a.Branch[1][3][i].length;j++){
                                            sumB2 += a.Branch[1][3][i][j];
                                        }
                                    }
                                    for (int i = 0; i < a.Branch[2][3].length ; i++){
                                        for(int j=0;j<a.Branch[2][3][i].length;j++){
                                            sumB3 += a.Branch[2][3][i][j];
                                        }
                                    }
                                    for (int i = 0; i < a.Branch[3][3].length ; i++){
                                        for(int j=0;j<a.Branch[3][3][i].length;j++){
                                            sumB4 += a.Branch[3][3][i][j];
                                        }
                                    }
                                    
                                    
                                    System.out.println("Sum of the office Bookcases are in Branch1:" + sumB);
                                    System.out.println("Sum of the office Bookcases are in Branch2:" + sumB2);
                                    System.out.println("Sum of the office Bookcases are in Branch3:" + sumB3);
                                    System.out.println("Sum of the office Bookcases are in Branch4:" + sumB4);
                            
                            break;

                                case "cabinets":
                                    
                                for (int i = 0; i < a.Branch[0][4].length ; i++){
                                        for(int j=0;j<a.Branch[0][4][i].length;j++){
                                            sumC += a.Branch[0][4][i][j];
                                        }
                                    }
                                    
                                    for (int i = 0; i < a.Branch[1][4].length ; i++){
                                        for(int j=0;j<a.Branch[1][4][i].length;j++){
                                            sumC2 += a.Branch[1][4][i][j];
                                        }
                                    }
                                    for (int i = 0; i < a.Branch[2][4].length ; i++){
                                        for(int j=0;j<a.Branch[2][4][i].length;j++){
                                            sumC3 += a.Branch[2][4][i][j];
                                        }
                                    }
                                    for (int i = 0; i < a.Branch[3][4].length ; i++){
                                        for(int j=0;j<a.Branch[3][4][i].length;j++){
                                            sumC4 += a.Branch[3][4][i][j];
                                        }
                                    }
                                   
                                    
                                    System.out.println("Sum of the office Cabinets are in Branch1:" + sumC);
                                    System.out.println("Sum of the office Cabinets are in Branch2:" + sumC2);
                                    System.out.println("Sum of the office Cabinets are in Branch3:" + sumC3);
                                    System.out.println("Sum of the office Cabinets are in Branch4:" + sumC4);

                            break;

                            default:
                                throw new Exception("Invalid Value");                                    
                           
                        }
                    }catch(Exception e){
                        System.out.println("ERROR !!! PLEASE ENTER THE VALID NUMBER.");
                    }
                        break;
                    
                        case 2: //if you want to shop in store press 2.
                            c.choiceCatalog(a.Branch,0);       
                            System.out.println(c.amountPocket());
                        break;
                    
                    
                        case 3:  //Here she/he will be able to see how many products she/he has bought and what product features she/he has received.
                            System.out.println(c.amountPocket());
                        break;
                    }
                }catch(Exception e){
                    System.out.println("ERROR !!! PLEASE ENTER THE VALID NUMBER.");
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
                        
                        try{
                            switch(option){  //branch employee can see the stock of furniture of the stores.
                                case 1:
                                    System.out.println("Sum of the office Chairs are in Branch1:" + sum);
                                    System.out.println("Sum of the office Chairs are in Branch2:" + sum2);
                                    System.out.println("Sum of the office Chairs are in Branch3:" + sum3);
                                    System.out.println("Sum of the office Chairs are in Branch4:" + sum4);
                                    System.out.println("Sum of the office Desks are in Branch1:" + sumD);
                                    System.out.println("Sum of the office Desks are in Branch2:" + sumD2);
                                    System.out.println("Sum of the office Desks are in Branch3:" + sumD3);
                                    System.out.println("Sum of the office Desks are in Branch4:" + sumD4);
                                    System.out.println("Sum of the office Tables are in Branch1:" + sumT);
                                    System.out.println("Sum of the office Tables are in Branch2:" + sumT2);
                                    System.out.println("Sum of the office Tables are in Branch3:" + sumT3);
                                    System.out.println("Sum of the office Tables are in Branch4:" + sumT4);
                                    System.out.println("Sum of the office Bookcases are in Branch1:" + sumB);
                                    System.out.println("Sum of the office Bookcases are in Branch2:" + sumB2);
                                    System.out.println("Sum of the office Bookcases are in Branch3:" + sumB3);
                                    System.out.println("Sum of the office Bookcases are in Branch4:" + sumB4);
                                    System.out.println("Sum of the office Cabinets are in Branch1:" + sumC);
                                    System.out.println("Sum of the office Cabinets are in Branch2:" + sumC2);
                                    System.out.println("Sum of the office Cabinets are in Branch3:" + sumC3);
                                    System.out.println("Sum of the office Cabinets are in Branch4:" + sumC4);
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
                                        c.choiceCatalog(a.Branch,0);
                                    }
                                    System.out.println("Items in the customer's  NEW shopping cart: "+c.amountPocket());
                                    break;
                            
                                default:
                                    throw new Exception("Invalid Value !!!");
                            
                            }
                        }catch(Exception e){
                            System.out.println("ERROR !!! PLEASE ENTER THE VALID NUMBER.");
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
                        try{
                            switch(choice){
                        
                                case 'q':
                                    a1.exit(); //quit employee
                                    System.out.println("Current Number Of Branch Employee: " + Administrator.numberEmployee());
                                break;
                                
                                case 'w':   //hire employee
                                    Administrator a6 = new Administrator("Anil", "@sAnil221", "Sanil34saf5");
                                    System.out.println("Current Number Of Branch Employee: " + Administrator.numberEmployee());
                                break;
                                
                                case 'a':
                                    a1.quitBranch();  //quit branch
                                    System.out.println("Current Number Of Branch : " + Administrator.numberBranch());
                                break;

                                case 's': //add branch
                                    Administrator b5 = new Branch("5", "@M5", "M125");
                                    System.out.println("Current Number Of Branch : " + Administrator.numberBranch());
                                break;
                                
                                default:
                                    throw new Exception("Invalid Value");
                               
                            }
                        }catch(Exception e){
                            System.out.println("ERROR !!! PLEASE ENTER THE VALID NUMBER.");
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
        }catch(Exception e){
            System.out.println("ERROR !!! PLEASE ENTER THE VALID NUMBER.");
        }
            
        }
        System.out.println("HAVE A GOOD DAY. WE HOPE YOU ENJOYED IT.!!!");
    }

}