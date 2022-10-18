import java.io.IOException;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        boolean quit = false;
        int selection;
        long registerId;
        String registerPassword;
        store a = new store("Anil",12345678);
        trader t = new trader("aadmin",11111111);
        customer c = new customer("asfasf",22);

    ////////////////////////////////////////  DRIVER ///////////////////////////////////////////////
    
      a.productFile();
    
    //////////////////////////////////////// COSTUMER DRIVER /////////////////////////////////////////////
        
        //This information of product writed orders.txt , you can check.
        c.orderProduct("ABCDEFGH2GTFR123", "SerdilAnil", "Footwear >> Man FootWear", 10000, 200," Comfartable and cheap Footwear ", "Serdil Anil Unlu");    
        c.orderProduct("QWQWQWQQWER12345", "Serdil Anil Unlu", "Clock >> Woman Clock", 800, 450, "Gold and silver plated 2-year warranty watches.", "ClockWoman");
        c.orderProduct("ACUYHTRBN12345RU", "Lionel Messi", "Sport Shoes", 1000, 530, "Dirt-resistant gear crampons", "Shoes monster");


        System.out.println("******************* I SEARCHED 'Shampoo' TEXT AND PRINT THE TERMINAL *****************");
        System.out.println();
        System.out.println();
        c.searchQuery("Shampoo");
        System.out.println();
        System.out.println();
        System.out.println("******************* FILTERED PRICE FROM 1500 TO 2500 AND I PRINT And I PRINT PRODUCTS THAT ARE IN THIS PRICE RANGE AND CONTAIN THE WORD 'Shampoo' TO THE TERMINAL.***************");
        System.out.println();
        c.filterPrice(1500, 2500);
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println("******************* I HAVE LISTED ALL THE PRODUCTS THAT CONTAIN THE NAME 'Shampoo' IN THE DESCRIPTION OR NAME, IN DESCENDING ORDER OF PRICE.************************");
        c.sortPrice_Dec();
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println("********************** I HAVE LISTED 'Shampoo' IN FROM 'A' TO 'Z'(FOR INCLUDING 'Shampoo' IN NAME OR DESCRIPTION)************************ ");
        System.out.println();
        System.out.println();
        c.sortNameA_Z();
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println("*********************** I HAVE LISTED 'Shampoo' IN DESCENDING ORDER OF DISCOUNT:(FOR INCLUDING 'Shampoo' IN NAME OR DESCRIPTION) *****************************");
        System.out.println();
        c.sortDiscount_Dec();
        System.out.println();
        System.out.println();
        System.out.println("*********************** I HAVE LISTED IN INCREASING ORDER OF PRICE :(FOR INCLUDING 'Shampoo' IN NAME OR DESCRIPTION:)*******************************");
        System.out.println();
        c.sortPrice_Inc();
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println();
        System.out.println("************************ I HAVE LISTED IN INCREASING ORDER OF DISCOUNT (FOR INCLUDING 'Shampoo' IN NAME OR DESCRIPTION:)******************************************");
        System.out.println();
        System.out.println();
        c.sortDiscount_Inc();
        System.out.println();
        System.out.println();
        System.out.println("************************** I SEARCHED 'Sicons' TRADER IN product.txt AND I PRINT THE CARREL PRODUCTS: **************************************");
        System.out.println();
        c.showProduct("Sicons");
        System.out.println();


        
        
    /////////////////////////////////////// TRADER DRİVER ////////////////////////////////////////////////

        //I ADDED PRODUCT TO 'product.txt' YOU CAN CHECK IT TO VERIFY.
        System.out.println();
        System.out.println("ADDED PRODUCT TO 'product.txt'");
        t.addProduct("Green CHAIR Furniture","FURNITURE >> CHAIR >> ",4000,450,"KEY WORD IS WOOD THAT RESISTANT AND CAN EASILY CLEAN","GREENWOOD");
        System.out.println();

        //I REMOVED THE PRODUCT WITH THE PARAMETER I PLACED IN THE FUNCTION.
        System.out.println("REMOVED PRODUCT FORM product.txt:");
        t.removeProduct("SRTEH2FF9KEDEFGF");

        //I EDIT THE NAME AND PRICE OF THE PRODUCT WHOSE ID I ENTERED.
        System.out.println("EDIT PRODUCT TO product.txt:");
        t.editProduct("SBEEH3QGU7MFYJFY", "Anil Unlu", 1350);
        System.out.println();
        System.out.println();
        //THIS METHODS SHOWS THE ORDERS THAT IN THE 'order.txt'.
        System.out.println("*************** SHOWED ORDERS FROM 'order.txt': ****************************** ");
        System.out.println();
        System.out.println();
        t.showOrders();
        System.out.println();
        System.out.println();
        //Here, if I accept the orders in the order.txt file, 
        //I print a confirm order in the 'situation' section under the orders, and if I do not accept, I print a canceled order.
        //IF SITUATION IS 1 ORDER IS CONFIRMED OTHERWISE IF 0 ORDER IS CANCELED.

        t.confirmOrder(1,"QWERTYUIOP12345L");
        t.confirmOrder(0,"ABCDEFGH2GTFR123");

    //////////////////////////////////////// MENU ////////////////////////////////////////////////////////

    
        while(!quit){
            System.out.println();
            a.Welcome();
            Scanner input  = new Scanner(System.in);
            selection = input.nextInt();
        
        try{
            switch(selection){

                case 1:
                    a.Register();
                    System.out.println();
                    System.out.println("Registration process successful good shoppings.");
                break;
            
                case 2:
           
                    int select;
                    String k;
                    String l;
                    String m;
                    String n;
                    String p;
                    int x;
                    int y;
                    String z;
                    String r;
                    System.out.println("Please enter the ID: ");
                    Scanner input2 = new Scanner(System.in);
                    registerId = input2.nextLong();
                    System.out.println();
                    System.out.println("Please enter the password: ");
                    Scanner input3 = new Scanner(System.in);
                    registerPassword = input3.nextLine();
                
                
                    if(registerId == a.getID() && registerPassword.equals(a.getPassword()) || a.checkSign(registerPassword) == true){
                        
                    do{
                        System.out.println("Login to the system is successful.");
                        System.out.println();
                        System.out.println("0-) IF YOU WANT TO BACK TO MAIN MENU ,PLEASE PRESS '0' ");
                        System.out.println("1-) IF YOU WANT TO ORDER, PLEASE PRESS '1'.");
                        System.out.println("2-) IF YOU WANT TO SEARCH AND QUERY THE TEXT BY THEIR DECRASE NAMES, PLEASE FIRST PRESS '2'.)");
                        System.out.println("3-) IF YOU SEARCH TEXT ,FOR SORTING NAME FROM A TO Z ,PLEASE ENTER NUMBER '3'.)");
                        System.out.println("4-) IF YOU SEARCH TEXT ,FOR THE INCREASING PRICE ORDER ,PLEASE ENTER NUMBER '4'.)");
                        System.out.println("5-) IF YOU SEARCH TEXT ,FOR THE INCREASING DISCOUNT ORDER ,PLEASE ENTER NUMBER '5'.)");
                        System.out.println("6-) IF YOU SEARCH TEXT ,FOR SORTING NAME FROM Z TO A ,PLEASE ENTER NUMBER '6'.)");
                        System.out.println("7-) IF YOU SEARCH TEXT ,FOR THE DECREASING PRICE ORDER ,PLEASE ENTER NUMBER '7'.)");
                        System.out.println("8-) IF YOU SEARCH TEXT ,FOR THE DECREASING DISCOUNT ORDER ,PLEASE ENTER NUMBER '8'.)");
                        System.out.println("9-) IF YOU DISPLAY PRODUCTS OF TRADER ,PLEASE PRESS '9'.)");
                        System.out.println("10-) IF YOU FILTER THE PRICE ABOUT YOU SEARCHED TEXT)");
                        select = input.nextInt();
                        switch(select){

                            case 1:
                                System.out.println("PLEASE ENTER THE 'ID' OF THE PRODUCT YOU WANT TO ORDER: ");
                                k = input3.nextLine();
                                System.out.println("PLEASE ENTER THE 'NAME' OF THE PRODUCT YOU WANT TO ORDER: ");
                                l = input3.nextLine();
                                System.out.println("PLEASE ENTER THE 'CATEGORY' OF THE PRODUCT YOU WANT TO ORDER: ");
                                m = input3.nextLine(); 
                                System.out.println("PLEASE ENTER THE 'PRICE' OF THE PRODUCT YOU WANT TO ORDER: ");
                                x = input.nextInt(); 
                                System.out.println("PLEASE ENTER THE 'DISCOUNTED' OF THE PRODUCT YOU WANT TO ORDER: ");
                                y = input.nextInt();                                 
                                System.out.println("PLEASE ENTER THE 'DESCRIPTION' OF THE PRODUCT YOU WANT TO ORDER: ");
                                n = input3.nextLine(); 
                                System.out.println("PLEASE ENTER THE 'TRADER' OF THE PRODUCT YOU WANT TO ORDER: ");
                                p = input3.nextLine(); 

                                c.orderProduct(k,l,m, x, y, n, p);

                            break;

                            case 2:
                                System.out.println("PLEASE WRITE THE WORD YOU WANT TO SEARCH.");
                                z = input3.nextLine();       
                                c.searchQuery(z);
                            break;
                            
                            case 3:
                                
                                c.sortNameA_Z();
                            break;
                            
                            case 4:
                                c.sortPrice_Inc();
                            break;

                            case 5:
                                c.sortDiscount_Inc();
                            break;

                            case 6:
                                c.sortNameZ_A();
                            break;

                            case 7:
                                c.sortPrice_Dec();
                            break;

                            case 8:
                                c.sortDiscount_Dec();
                            break;

                            case 9:
                                System.out.println("ENTER THE NAME OF THE TRADER WHOSE PRODUCT YOU WANT TO SEE.");
                                r = input3.nextLine();
                                c.showProduct(r);
                            break;

                            case 10:
                                int upper;
                                int lower;
                                System.out.println("PLEASE ENTER THE LOWER: ");
                                lower = input.nextInt(); 
                                System.out.println("PLEASE ENTER THE UPPER: ");
                                upper = input.nextInt();
                                c.filterPrice(lower,upper);
                                
                            break;

                            default:
                                System.out.println("Please enter the invalid value: ");
                        }
                    
                    }while(select != 0);
                    
                    }
                    
                    
                    else{
                        System.out.println("Plase try again.");
                    }
                    System.out.println();
            

                break;


                case 3:
                    a.registerTrader();
                    System.out.println();
                    System.out.println("Registration process successful good sales.");
                break;

                
                case 4:
                    String v;
                    String w;
                    int d;
                    String traderId;
                    String f;
                    String g;
                    int h;
                    int choice = -1;
                    String first,second,fifth,sixth;
                    int third,fourth;
                    String traderPassWord;
                    System.out.println("PLEASE ENTER THE ID ");
                    Scanner input4 = new Scanner(System.in);
                    traderId = input4.nextLine();
                    System.out.println();
                    System.out.println("PLEASE ENTER THE PASSWORD ");
                    Scanner input5 = new Scanner(System.in);
                    traderPassWord = input5.nextLine();
                    Scanner input6 = new Scanner(System.in);

                do{
                    if(a.readFileTrader(traderId) && a.readFileTrader(traderPassWord)){

                        System.out.println("1-) IF YOU WANT TO ADD PRODUCTS TO (product.txt) PLEASE ENTER NUMBER '1' ");
                        System.out.println("2-) IF YOU WANT TO REMOVE PRODUCTS FROM (product.txt) PLEASE ENTER NUMBER '2' ");
                        System.out.println("3-) IF YOU WANT TO EDIT PRODUCTS TO (product.txt) PLEASE ENTER NUMBER '3' ");
                        System.out.println("4-) IF YOU WANT TO SEE THE CUSTOMER'S ORDER'S PLEASE ENTER NUMBER '4' ");
                        System.out.println("5-)IF YOU WANT TO MEET AND CANCEL THE CUSTOMER'S ORDER'S PLEASE ENTER NUMBER '5' ");
                        System.out.println("6-) IF YOU WANT TO BACK TO MAIN MENU:");
                        choice = input6.nextInt();
                        
                        if(choice == 1){
                            System.out.println("PLEASE ENTER THE INFORMATION FOR THE PRODUCT YOU WANT TO ADD, RESPECTİVELY.");
                            System.out.println("PLEASE ENTER THE NAME: ");
                            first = input5.nextLine();
                            System.out.println("PLEASE ENTER THE CATEGORY: ");
                            second = input5.nextLine();
                            System.out.println("PLEASE ENTER THE PRICE: ");
                            third = input6.nextInt();
                            System.out.println("PLEASE ENTER THE DISCOUNTED: ");
                            fourth = input6.nextInt();
                            System.out.println("PLEASE ENTER THE DESCRIPTION: ");
                            fifth = input5.nextLine();
                            System.out.println("PLEASE ENTER THE TRADER: ");
                            sixth = input5.nextLine();

                            t.addProduct(first,second,third,fourth,fifth,sixth);
                            System.out.println();
                            System.out.println("THE PRODUCT YOU WRİTED IS SAVED AT THE END OF THE 'product.txt' FILE.");
                        }
                        
                        else if(choice == 2){
                            System.out.println("PLEASE ENTER THE ID OF THE PRODUCT YOU WANT TO REMOVE.");
                            f = input5.nextLine();
                            t.removeProduct(f);
                            System.out.println();
                            System.out.println("THE PRODUCT YOU ENTERED ID FOR HAS BEEN REMOVED FROM 'product.txt'.");
                        }
                        
                        else if(choice == 3){
                            System.out.println("ENTER THE ID OF THE PRODUCT YOU WANT TO REPLACE.");
                            v = input5.nextLine();
                            System.out.println("ENTER THE NAME OF THE PRODUCT YOU WANT TO REPLACE.");
                            w = input5.nextLine();
                            System.out.println("ENTER THE PRICE OF THE PRODUCT YOU WANT TO REPLACE.");
                            d = input6.nextInt();
                            t.editProduct(v, w, d);
                        }
                    
                    
                        else if(choice == 4){
                            System.out.println("ORDER ARE LISTED BELOW.");
                            System.out.println();
                            t.showOrders();
                        }
                        
                        else if(choice == 5){
                            System.out.println("ENTER THE ID OF THE PRODUCT YOU WILL ACCEPT OR CANCEL.");
                            g = input5.nextLine();
                            System.out.println();
                            System.out.println("0-) IF YOU WANT CANCEL THE ORDER ,PLEASE ENTER '0'. ");
                            System.out.println("1-) IF YOU CONFIRM ORDER ,PLEASE ENTER '1'. ");
                            h = input6.nextInt();
                            t.confirmOrder(h,g);
                            
                        }
                    
                        

                    }
                
                }while(choice != 6);

                break;

                case 0:
                    quit = true;

                break;

                default:
                    throw new Exception("Invalid Value !!!");


            }
        }catch(Exception e){
            System.out.println("ERROR !!! PLEASE ENTER THE VALID NUMBER. ");
        }
        }
        
        System.out.println("HAVE A GOOD DAY. WE HOPE YOU ENJOYED IT. ");
        
        
    }
}