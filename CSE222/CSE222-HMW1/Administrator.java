/** This class includes the additions and subtractions made by the manager. 
*/
public class Administrator extends Store{

    
    private static int countEmployee = 0;
    private static int countBranch = 0;
    
    public Administrator(String nameSurname,String eposta,String password){ //Constructor

        super(nameSurname,eposta,password);
        Administrator.countEmployee++;
        Administrator.countBranch++;
    }

     /**
     * To remove employees from the store.
     */
    public void exit(){  
        Administrator.countEmployee--;
    }

    /**
     * @return count of employee.
     */
    public static int numberEmployee(){ 
        return Administrator.countEmployee;
    }

     /**
     * To remove branch from the system.
     */
    public void quitBranch(){ 
        Administrator.countBranch--;
    }
    
    /**
     * @return count of Branch.
     */
    public static int numberBranch(){
        return Administrator.countBranch;
    }

    
}