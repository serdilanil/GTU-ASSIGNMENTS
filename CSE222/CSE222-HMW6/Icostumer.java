import java.io.IOException;
/**
 * this interface is costumer interface
 */

public interface Icostumer{

    public void sortNameA_Z() throws IOException;

    public void sortPrice_Inc() throws IOException;

    public void sortDiscount_Inc() throws IOException;

    public void sortNameZ_A() throws IOException;

    public void sortPrice_Dec() throws IOException;

    public void sortDiscount_Dec() throws IOException;

    public void filterPrice(int lower,int upper);
}