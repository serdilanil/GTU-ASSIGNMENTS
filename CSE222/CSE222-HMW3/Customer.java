import java.util.*;

/**
*This class records the features of the furniture you want to buy when the customer or employee orders.  
*/
public class Customer extends Account{

     

    String[][] pocket = new String[1][4];

    public Customer(String nameSurname,String eposta,String password){ //Constructor

        super(nameSurname,eposta,password);
    }

    private int pocketCount = 0; 

    /**
     * @param branchPocket  Furniture types and amount to be inserted.
     * @param branch  Index of the branchPocket.
     *In this function, after first selecting the product type, we can select other features (color, model and quantity). 
     */
     public void choiceCatalog(int name,int model,int color,int amount,Branch branch)throws RuntimeException{
        
        //int model,color,amount;
        System.out.println("PLEASE ONLY WRITE THE NUMBER OPPOSITE OF THE ITEM YOU WANT TO CHOOSE.( chair = '0', desk = '1', table = '2', bookcase = '3', cabinet = '4' )");
        
        //Scanner input = new Scanner(System.in);
        //name = input.nextInt(); 
    
        switch(name){  // we choice the type of furniture type in this switch-case.

            case 0:
                pocket[pocketCount][0] = "chair";
            break;

            case 1:
                pocket[pocketCount][0] = "desk";
            break;

            case 2:
                pocket[pocketCount][0] = "table";
             break;

            case 3:
                pocket[pocketCount][0] = "bookcase";
            break;

            case 4:
                pocket[pocketCount][0] = "cabinets";
            break;

            default:
                throw new RuntimeException("Invalid Value!!!");
        }
    
                                                            //In this place we entered the furniture features.
        System.out.println("PLEASE ENTER THE MODEL YOU WILL CHOOSE AS A NUMBER.(FOR EXAMPLE Model1 = '1', Model2 = '2' ...):  ");
        
        //model = input.nextInt(); 
        
        pocket[pocketCount][1] = "Model " + Integer.toString(model);

        System.out.println("PLEASE ENTER THE COLOR YOU WILL CHOOSE AS A NUMBER.(FOR EXAMPLE Color1 = '1', Color2 = '2' ...): ");
        //color = input.nextInt(); 

        pocket[pocketCount][2] = "Color " + Integer.toString(color);

        System.out.println("Please determine the amount of furniture ");
      
        //amount = input.nextInt(); 

        pocket[pocketCount][3] = Integer.toString(amount);

        branch.decrease(name, model, color, amount);


        pocketCount++;
        
        extendArray();
    }

    public void loginAccount(){
        System.out.println("THE SYSTEM HAS BEEN LOGGED IN BY CUSTOMER.");
    }

    /** 
    * In this function, I am expanding the size of the directory used for our shopping cart.
    */
    
    private void extendArray(){ 

        String[][] temp;
        
        temp = pocket;

        pocket =  new String[temp.length+1][4];
        
        for(int i=0;i<temp.length;i++){
            pocket[i] = temp[i];
        }
    }

    /** 
    * I print the product that the customer bought in her/his basket and all the features of the product with this function.
    */
    public String amountPocket(){  
        StringBuilder a = new StringBuilder();

        for(int i=0;i<pocket.length-1;i++){
            
            a.append(" Name: ");
            a.append(pocket[i][0]);
            a.append(", Model: ");
            a.append(pocket[i][1]);
            a.append(", Color: ");
            a.append(pocket[i][2]);
            a.append(", Amount: ");
            a.append(pocket[i][3]);
            a.append("\n");            
        }
    
        return a.toString();
    }


}