/** 
* This class is the interface of the store class.
*welcome method give start menu.
*regiserCustomer method is giving information about log in for customer.
*loginAccount method reports that it is logged in.
*Register provide the sing up for customer.
*In stockTotal method I give the default value to 4D array. 
*/
public interface IstoreInfo{

    public void Welcome();
    public void registerCustomer();
    public void loginAccount();
    public void Register();
    public void stockTotal();
}