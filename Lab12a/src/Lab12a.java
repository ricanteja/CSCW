import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Lab12a
{
    public static void main(String[] args)
    {
        String target = args[0];
        File file = new File(args[1]);
        Scanner reader;
        String buffer;

        try
        {
            reader = new Scanner(file);

            for(int i = 1; reader.hasNext(); i++)
            {
                buffer = reader.nextLine();

                if(args.length > 2 && args[2].equals("upper"))
                {
                    if(buffer.toUpperCase().contains(target.toUpperCase()))
                        System.out.printf("%d: %s\n", i, buffer);
                }
                else
                {
                    if(buffer.contains(target))
                        System.out.printf("%d: %s\n", i, buffer);
                }
            }
        }
        catch(IOException e)
        {
            System.out.print("Error! " + e.toString() + "\n");
        }
    }
}