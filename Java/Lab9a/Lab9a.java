import java.util.Scanner;

class Stock
{
    Stock(String symbol, String name)
    {
        mSymbol = symbol;
        mName = name;
    }
    
    String getSymbol()
    {
        return mSymbol;
    }
    
    void setSymbol(String symbol)
    {
        mSymbol = symbol;
    }
    
    String getName()
    {
        return mName;
    }
    
    void setName(String name)
    {
        mName = name;
    }
    
    double getPreviousClosingPrice()
    {
        return mPreviousClosingPrice;
    }
    
    void setPreviousClosingPrice(double price)
    {
        mPreviousClosingPrice = price;
    }
    
    double getCurrentPrice()
    {
        return mCurrentPrice;
    }
    
    void setCurrentPrice(double price)
    {
        mCurrentPrice = price;
    }
    
    double getChangePercent()
    {
        return ((mCurrentPrice - mPreviousClosingPrice) / mPreviousClosingPrice) * 100;
    }
    
    String mSymbol;
    String mName;
    double mPreviousClosingPrice;
    double mCurrentPrice;
}

public class Lab9a
{
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);
        String symbol;
        String name;
        double previousPrice;
        double currentPrice;
        
        
        System.out.print("\t\tStock Program\n\t\tby Ricardo Tejada\n\n");
        
        while(true)
        {
            System.out.print("Enter stock Symbol (or \'q\' to exit): ");
            symbol = scan.nextLine().trim();
            
            if((symbol.equals("q")))
                break;
            
            System.out.print("Enter company name: ");
            name = scan.nextLine().trim();
            
            Stock stock = new Stock(symbol, name);
            
            System.out.print("Enter previous closing price: ");
            previousPrice = Double.parseDouble(scan.nextLine());
            stock.setPreviousClosingPrice(previousPrice);
            
            System.out.print("Enter current price: ");
            currentPrice = Double.parseDouble(scan.nextLine());
            stock.setCurrentPrice(currentPrice);
            
            System.out.printf("SYMBOL=%s, NAME=%s, Previous Price=%.2f, "
                    + "Current Price=%.2f, Percent Change=%.2f%%\n\n", 
                    stock.getSymbol(),
                    stock.getName(),
                    stock.getPreviousClosingPrice(),
                    stock.getCurrentPrice(),
                    stock.getChangePercent());
        }
    }
}

