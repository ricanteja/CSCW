import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.io.*;

class CreditAccount
{
    CreditAccount(String accNum, double max)
    {
        accountNumber = accNum;
        issuerSymbol = "" + accountNumber.charAt(0);
        maxLimit = max;
        available = maxLimit;
        accountValid = true;
    }

    CreditAccount(String recordData)
    {
        String[] data = recordData.split("\\|");

        accountNumber = data[0];
        issuerSymbol = "" + accountNumber.charAt(0);
        available = Double.parseDouble(data[1]);
        maxLimit = Double.parseDouble(data[2]);
        accountValid = true;
    }

    public void setAccountNumber(String accNum) { accountNumber = accNum; }
    public String getAccountNumber() { return accountNumber; }

    public void setIssuerSymbol(String issuerSym) { issuerSymbol = issuerSym; }
    public String getIssuerSymbol() { return issuerSymbol; }

    public void setAvailable(double newAvailable) { available = newAvailable; }
    public double getAvailable() { return available; }

    public void setMaxLimit(double newMaxLimit) { maxLimit = newMaxLimit; }
    public double getMaxLimit() { return maxLimit; }

    public void setValid(boolean valid) { accountValid = valid; }
    public boolean isValid() { return accountValid; }

    public String getRecord() { return String.format("%s|%7.2f|%7.2f", accountNumber, available, maxLimit); }

    private String accountNumber;
    private String issuerSymbol;
    private boolean accountValid;

    private double available;
    private double maxLimit;
}

class Credit
{
    static void printHelp()
    {
        System.out.print("This program accepts the following inputs and performs the related actions:\n");

        System.out.print("USAGE:\tcommand argument(s)\n\tCOMMAND                            ARGUMENT(S)\n" +
                "\thelp                               Output this help text.\n" +
                "\tcreate [issuer symbol]             Create a new account with issuer.\n" +
                "\tverify [account number] [amount]   Verify a purchase or credit.\n" +
                "\tq                                  Exit the program.\n");

        System.out.print("\nThe command and [issuer symbol] values are NOT case sensitive.\n" +
                "The following credit cards are supported:\n" +
                "\nCARD                    SYMBOL\n" +
                "American Express        AE\n" +
                "Visa                    V\n" +
                "MasterCard              MC\n" +
                "Discover                DIS\n" +
                "Diners Club             DINE\n\n");
    }

    static void saveData(CreditAccount[] records)
    {
        DateFormat formatDate = new SimpleDateFormat("yyyyMMdd_HHmmss");
        Date currentDate = new Date(System.currentTimeMillis());
        File currentFile = new File("dataFile.txt");
        File oldFile = new File("dateFile_" + formatDate.format(currentDate) + ".txt");
        FileWriter writer;

        try
        {
            if(currentFile.exists())
            {
                CreditAccount[] oldRecords = loadData();
                oldFile.createNewFile();

                writer = new FileWriter(oldFile);

                for(int i = 0; i < oldRecords.length; i++)
                    writer.write(oldRecords[i].getRecord() + "\n\n");

                writer.close();
            }
            else
                currentFile.createNewFile();

            writer = new FileWriter(currentFile);

            for(int i = 0; i < records.length; i++)
                writer.write(records[i].getRecord() + "\n\n");

            System.out.print("\t" + records.length + " record(s) saved.\n");

            writer.close();
        }
        catch(java.io.IOException e)
        {
            System.out.println("Error: " + e.toString());
        }
    }

    static CreditAccount[] loadData()
    {
        File file = new File("dataFile.txt");
        Scanner reader;
        String buffer;
        String[] recordData;
        CreditAccount[] records = new CreditAccount[0];

        try
        {
            if(file.exists())
            {
                reader = new Scanner(file);

                for(buffer = ""; reader.hasNextLine(); buffer += reader.nextLine() + " ");

                if(buffer.isEmpty())
                {
                    System.out.print("\tNo records to load.\n");
                    return records;
                }

                recordData = buffer.split("\n");
                records = new CreditAccount[recordData.length];

                for(int i = 0; i < recordData.length; i++)
                    records[i] = new CreditAccount(recordData[i]);

                System.out.print("\t" + records.length + " record(s) loaded.\n");
            }
            else
                System.out.print("\tNo records to load.\n");
        }
        catch(java.io.IOException e)
        {
            System.out.println("Error: " + e.toString());
        }

        return records;
    }

    static void createAccount(String command)
    {
        if(command.split(" ").length < 2)
        {
            System.out.print("\tError! Not enough arguments for command.\n");
            return;
        }

        String issuerSym = command.split(" ")[1].toUpperCase();
        String accountNum;
        double maxCredit;

        CreditAccount account;
        CreditAccount[] oldRecords;
        CreditAccount[] newRecords;

        if(issuerSym.equals("AE"))
            accountNum = "3";
        else if(issuerSym.equals("V"))
            accountNum = "4";
        else if(issuerSym.equals("MC"))
            accountNum = "5";
        else if(issuerSym.equals("DIS"))
            accountNum = "6";
        else if(issuerSym.equals("DINE"))
            accountNum = "7";
        else
        {
            System.out.print("\tError! Issuer symbol [" + issuerSym + "] is not valid.\n");
            return;
        }

        for(int i = 0; i < 15; i++)
            accountNum += Integer.toString((int)(Math.random() * 10));

        maxCredit = Integer.parseInt(accountNum.substring(15)) >= 4 ? 1000.0f : 500.0f;

        account = new CreditAccount(accountNum, maxCredit);
        account.setIssuerSymbol(issuerSym.toUpperCase());
        account.setValid(true);

        oldRecords = loadData();
        newRecords = new CreditAccount[oldRecords.length + 1];

        for(int i = 0; i < oldRecords.length; i++)
            newRecords[i] = oldRecords[i];

        newRecords[oldRecords.length] = account;

        saveData(newRecords);

        System.out.print("\tCreated new credit card account [" + issuerSym.toUpperCase() + "]:\tAccount Number " +
                accountNum + ", Credit Limit : " + account.getMaxLimit() + "\n");
    }

    static void authorizeTransaction(String command)
    {
        if(command.split(" ").length < 3)
        {
            System.out.print("\tError! Not enough arguments for command.\n");
            return;
        }

        String accNum = command.split(" ")[1];

        double amount = -Double.parseDouble(command.split(" ")[2]);     //Invert the amount because - means add to credit and + means take away from credit
        CreditAccount[] records = loadData();

        for(int i = 0; i < records.length; i++)
        {
            if(records[i].getAccountNumber().equals(accNum))
            {
                if(amount > 0)
                {
                    if(records[i].getMaxLimit() == records[i].getAvailable())
                        System.out.print("\tError! Authorization attempt failed. Credit is already max.\n");
                    else if(records[i].getAvailable() + amount > records[i].getMaxLimit())
                    {
                        records[i].setAvailable(records[i].getAvailable());
                        System.out.print("\tWarning! Authorization granted. Attempted to raise credit above max.\n");
                        System.out.printf("\tAccount %s|Transaction %.2f|Available Credit %.2f\n", accNum, amount, records[i].getAvailable());
                    }
                    else
                    {
                        records[i].setAvailable(records[i].getAvailable() + amount);
                        System.out.print("\tAuthorization granted.\n");
                        System.out.printf("\tAccount %s|Transaction %.2f|Available Credit %.2f\n", accNum, amount, records[i].getAvailable());
                    }
                }
                else
                {
                    if(amount + records[i].getAvailable() < 0)
                        System.out.print("\tError! Authorization denied. Attempted to use more credit than available .\n");
                    else
                    {
                        records[i].setAvailable(amount + records[i].getAvailable());
                        System.out.print("\tAuthorization granted.\n");
                        System.out.printf("\tAccount %s|Transaction %.2f|Available Credit %.2f\n", accNum, amount, records[i].getAvailable());
                    }
                }

                saveData(records);

                return;
            }
        }

        System.out.print("\tError! No record found for account " + accNum + ".\n");
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        boolean runFlag = true;
        String userInput;

        printHelp();

        while(runFlag)
        {
            System.out.print("Command: ");
            userInput = scanner.nextLine();

            System.out.print("userInput = " + userInput + "\n");

            if(userInput.split(" ")[0].toUpperCase().equals("HELP"))
                printHelp();
            else if(userInput.split(" ")[0].toUpperCase().equals("CREATE"))
                createAccount(userInput);
            else if(userInput.split(" ")[0].toUpperCase().equals("VERIFY"))
                authorizeTransaction(userInput);
            else if(userInput.split(" ")[0].toUpperCase().equals("Q"))
                runFlag = false;
            else
                System.out.print("\tError! Invalid command: " + userInput + "\n");
        }

        System.out.print("Exit program.\n");
    }
}