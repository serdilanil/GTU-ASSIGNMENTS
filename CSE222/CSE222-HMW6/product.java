/**
 * This class used in costumer class for sorting and returning products.
 */
public class product{

    private String name;
    private String ID;
    private int discounted;
    private int price;
    private String trader;
    private String description;
    private String category;

    public product(String ID,String name,String category,int price,int discounted,String description,String trader){
        this.name = name;
        this.ID = ID;
        this.discounted = discounted;
        this.price = price;
        this.description = description;
        this.trader = trader;
        this.category = category;
    }

    /**
     * product name
     * @return name
     */
    public String getName() {
        return name;
    }

    /**
     * product category
     * @return category
     */
    public String getCategory() {
        return category;
    }

    /**
     * product description
     * @return description
     */
    public String getDescription() {
        return description;
    }

    /**
     * product discounted
     * @return discounted
     */
    public int getDiscounted() {
        return discounted;
    }

    /**
     * product ID
     * @return ID
     */
    public String getID() {
        return ID;
    }

    /**
     * product price
     * @return price
     */
    public int getPrice() {
        return price;
    }

    /**
     * product trader
     * @return trader
     */ 
    public String getTrader() {
        return trader;
    }

    /**
     * I print the product and its information by this method.
     */
    public String toString(){
        
        return ("\n" +"Id: " + ID+ "\n" + "Name: " + name + "\n" + "Category: "+ category + "\n" + "Price: "
        + price + "\n" + "Discounted: "+ discounted + "\n"+ "Description: " + description + "\n"  + "Trader: " + trader+ "\n");
     
    }


}