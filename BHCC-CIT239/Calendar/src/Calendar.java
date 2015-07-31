import java.util.Scanner;

class BHCCDate
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Prints the title to the screen
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void printTitle()
    {
        System.out.print("\t\t    Calendar Program    \n");
        System.out.print("\t\t    by Ricardo Tejada \n\n");
        System.out.print("This program accepts the following inputs and performs the corresponding actions:");
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Prints the menu to the screen
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void printMenu()
    {
        System.out.print("\n\tINPUT:      ACTION:\n");
        System.out.print("\n\tMM DD YYYY  The program will print how many days have passed since Jan 1 YYYY\n");
        System.out.print("\th           Output this HELP text.\n");
        System.out.print("\tq           Quit(exit) the program.\n");
        System.out.print("\tv           Turn Verbose mode ON or OFF.\n");
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Print the date relevant to internal values
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void printDate()
    {
        if(isDateValid())
        {
            System.out.print(total + (total > 1 ? " days have" : " day has") + " elapsed from Jan 1, " + year + " to ");
            switch(month)
            {
                case 1:System.out.print("Jan"); break;
                case 2:System.out.print("Feb"); break;
                case 3:System.out.print("Mar"); break;
                case 4:System.out.print("Apr"); break;
                case 5:System.out.print("May"); break;
                case 6:System.out.print("Jun"); break;
                case 7:System.out.print("Jul"); break;
                case 8:System.out.print("Aug"); break;
                case 9:System.out.print("Sep"); break;
                case 10:System.out.print("Oct"); break;
                case 11:System.out.print("Nov"); break;
                case 12:System.out.print("Dec"); break;
            }
            System.out.print(" " + day + ", " + year + ".\n");
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Extracts the date information from string
    //              Will catch invalid input
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void parseDate(String data)
    {
        errors = false;
        total = 0;

        data = data.trim();
        if(!data.isEmpty())
        {
            month = parseMonth(data);
            day = parseDay(data);
            year = parseYear(data);

            for(int i = month; i > 0; --i)
                switch(i)
                {
                    case 1:total += i == month ? day : 31; break;
                    case 2:total += i == month ? day : isLeapYear() ? 29 : 28; break;
                    case 3:total += i == month ? day : 31; break;
                    case 4:total += i == month ? day : 30; break;
                    case 5:total += i == month ? day : 31; break;
                    case 6:total += i == month ? day : 30; break;
                    case 7:total += i == month ? day : 31; break;
                    case 8:total += i == month ? day : 31; break;
                    case 9:total += i == month ? day : 30; break;
                    case 10:total += i == month ? day : 31; break;
                    case 11:total += i == month ? day : 30; break;
                    case 12:total += i == month ? day : 31; break;
                }
        }
        else
            errors = true;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Returns the month part of the string
    //              Will catch invalid input
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int parseMonth(String source)
    {
        String buffer = "";
        int result = 0;

        try
        {
            for(int i = 0; i < source.length() && source.charAt(i) != ' '; ++i)
                buffer += source.charAt(i);

            result = Integer.parseInt(buffer);
        }
        catch(NumberFormatException exception)
        {
            if(verbose && !errors)
                System.out.println("Error: \"" + buffer + "\" is not a valid month.");

            errors = true;
        }
        catch(StringIndexOutOfBoundsException exception)
        {
            if(verbose && !errors)
                System.out.println("Error: Not enough entries for date.");

            errors = true;
        }
        if(result > 13 || result < 1 && !errors)
        {
            if(verbose)
                System.out.println("Error: \"" + result + "\" is not a valid month.");

            errors = true;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Returns the day part of the string
    //              Will catch invalid input
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int parseDay(String source)
    {
        String buffer = "";
        int result = 0;

        try
        {
            source = source.substring(source.indexOf(' '), source.length()).trim();

            for(int i = 0; i < source.length() && source.charAt(i) != ' '; ++i)
                buffer += source.charAt(i);

            result = Integer.parseInt(buffer);
        }
        catch(NumberFormatException exception)
        {
            if(verbose && !errors)
                System.out.println("Error: \"" + buffer + "\" is not a valid day.");

            errors = true;
        }
        catch(StringIndexOutOfBoundsException exception)
        {
            if(verbose && !errors)
                System.out.println("Error: Not enough entries for date.");

            errors = true;
        }
        if(result > 31 || result < 1)
        {
            if(verbose && !errors)
                System.out.println("Error: \"" + result + "\" is not a valid day.");

            errors = true;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Returns the year part of the string
    //              Will catch invalid input
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int parseYear(String source)
    {
        String buffer = "";
        int result = 0;

        try
        {
            source = source.substring(source.indexOf(' '), source.length()).trim();
            source = source.substring(source.indexOf(' '), source.length()).trim();

            for(int i = 0; i < source.length() && source.charAt(i) != ' '; ++i)
                buffer += source.charAt(i);

            result = Integer.parseInt(source);
        }
        catch(NumberFormatException exception)
        {
            if(verbose && !errors)
                System.out.println("Error: \"" + buffer + "\" is not a valid year.");

            errors = true;
        }
        catch(StringIndexOutOfBoundsException exception)
        {
            if(verbose && !errors)
                System.out.println("Error: Not enough entries for date.");

            errors = true;
        }
        if(result < 1 && !errors)
        {
            if(verbose)
                System.out.println("Error: \"" + result + "\" is not a valid year.");

            errors = true;
        }

        return result;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Returns true if date fields are valid
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    boolean isDateValid()
    {
        if(!errors)
        {
            if(month == 2)
            {
                if(isLeapYear())
                {
                    if(day > 29)
                    {
                        System.out.println("Error: \"" + day + "\" is not a valid date for Feb " + year);
                        errors = true;
                    }
                }
                else
                {
                    if(day > 28)
                    {
                        System.out.println("Error: \"" + day + "\" is not a valid date for Feb " + year);
                        errors = true;
                    }
                }
            }
        }

        return errors == false;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Pre cond:    None
    // Post cond:   Returns true if 'year' is a leap year
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    boolean isLeapYear()    {return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;}

    public int month, day, year, total;
    boolean running;
    boolean verbose;
    boolean errors;
}

public class Calendar
{
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Main Function
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String input;

        BHCCDate myDate = new BHCCDate();
        myDate.verbose = false;
        myDate.running = true;

        myDate.printTitle();
        myDate.printMenu();

        while(myDate.running)
        {
            System.out.print("Please enter numeric date (or h for HELP): ");
            input = scan.nextLine();

            if(input.equals("q"))
                myDate.running = false;
            else if(input.equals("h"))
                myDate.printMenu();
            else if(input.equals("v"))
                myDate.verbose = !myDate.verbose;
            else
            {
                myDate.parseDate(input);
                myDate.printDate();
            }
        }

        System.out.print("About to exit program...");
    }
}