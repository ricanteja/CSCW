import java.util.Scanner;

/**
 * Created by Ricky on 3/9/2016.
 */
public class StringManipulation
{
    static int findFirstVowel(String str)
    {
        for(int i = 0; i < str.length(); i++)
        {
            switch(str.charAt(i))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    return i;
            }
        }

        return -1;
    }

    static String convertToPigLatin(String str)
    {
        str = rot13(str).toLowerCase(); // decrypt input string;
        String first;
        String last;

        int pos = findFirstVowel(str);
        int end = str.length();

        if(pos > 0)
        {
            first = str.substring(pos, end);
            last = str.substring(0, pos).toLowerCase();

            str = first + last + "ay";
        }
        else if(pos == 0)
        {
            first = str.substring(pos + 1, end);
            last = str.substring(pos, pos + 1).toLowerCase();

            str = first + last + "way";
        }

        return str;
    }

    static String reverse(String str)
    {
        String out = "";
        str = rot13(str).toLowerCase();

        for (int i = str.length() - 1; i >= 0; i--)
            out += str.charAt(i);

        return out;
    }

    static String rot13(String str) // EXTRA CREDIT
    {
        String out = "";

        for(int i = 0; i < str.length(); i++)
        {
            char c = str.charAt(i);
            boolean caps = (c <= 'Z' && c >= 'A');

            if((caps && c <= 'M') || (!caps && c <= 'm'))
                c += 13;
            else
                c -= 13;

            out += c;
        }

        return out;
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String str = rot13(input.next()); // encrypt input string

        while(!rot13(str).equals("done"))
        {
            System.out.println(convertToPigLatin(str));
            System.out.println(reverse(str));
            str = rot13(input.next()); // encrypt input string
        }
    }
}
