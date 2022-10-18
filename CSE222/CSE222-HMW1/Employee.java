/** 
* This class can use all the features of the Administrator class. It also informs the manager about the number of products. .
*/

public class Employee extends Administrator{

    public Employee(String nameSurname,String eposta,String password){

        super(nameSurname,eposta,password);
    }


        /** 
        *Call the manager if there is need product in store. .
        */
    public void callManager(){  
        System.out.println(" PLEASE PROVIDE PRODUCT. ");
    }

}