import java.io.*;


public class Lab17a
{
    public static void main(String[] args)
    {
        DataInputStream inputStream;
        DataOutputStream outputStream;
        int counter = 0;
        byte byteBuffer[] = new byte[8];
        String lineBuffer;
        
        if(args.length < 2)
        {
            System.out.print("Usage: java Lab17a [input filename] [output filename]\n");
            System.exit(1);
        }
        
        try
        {
            inputStream = new DataInputStream(new FileInputStream(args[0]));
            outputStream = new DataOutputStream(new FileOutputStream(args[1]));
            
            while(inputStream.read(byteBuffer) > 0)
            {
                lineBuffer = String.format("%s (%s): ", padString(Integer.toString(counter), "0", 4), padString(Integer.toHexString(counter), "0", 4));

                //Print Hex Values
                for(int i = 0; i < byteBuffer.length; i++)
                    lineBuffer += String.format(" %s", padString(binaryToHexadecimal(byteBuffer[i]), "0", 2).toUpperCase());

                lineBuffer += "\t";

                //Print ASCII Characters
                for(int i = 0; i < byteBuffer.length; i++)
                    lineBuffer += String.format(" %s", padString(binaryToCharacter(byteBuffer[i]), " ", 4));

                lineBuffer += "\n";

                outputStream.writeBytes(lineBuffer);
                System.out.print(lineBuffer);

                counter += 8;
            }

            outputStream.close();
        }
        catch(IOException e)
        {
            System.out.println("Error! " + e.getMessage());
        }
    }

    public static String padString(String string, String padding, int maxSize)
    {
        StringBuilder stringBuilder = new StringBuilder();

        for(int i = maxSize - string.length(); i > 0; i--)
            stringBuilder.append(padding);

        stringBuilder.append(string);

        return stringBuilder.toString();
    }

    public static String binaryToCharacter(byte input)
    {
        switch(input)
        {
            case '\n': return "\\n";
            case '\r': return "\\r";
            case '\t': return "\\t";
            default: return Character.toString((char)input);
        }
    }

    public static String binaryToHexadecimal(byte input) {return Integer.toHexString(input);}
}