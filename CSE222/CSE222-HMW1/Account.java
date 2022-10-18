/** This class reports the moves made by the Customer in the system. 
*/
public abstract class Account extends Store{

    /** Represents customer entry registration.
     */

    
    public Account(String nameSurname,String eposta,String password){

        super(nameSurname,eposta,password);
    }

    /**
     * When the customer logs into the system, the customer input information comes from the system.
     */
    public abstract void loginAccount();


    /**
     * @return password for customer.
     */
    public String enterPassword(){ 
        return password;
    }

   

}