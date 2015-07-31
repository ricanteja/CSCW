import java.util.Scanner;

public class Palindrome
{
    public static long reverseNumber(long number)
    {
        long reverseInt = 0;

        while(number > 0)
        {
            reverseInt = (reverseInt + (number % 10)) * 10;
            number /= 10;
        }
        
        return reverseInt / 10;
    }
    
    public static boolean isPalindrome(long number)
    {
        return number == reverseNumber(number);
    }
    
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        long integer;
        
        System.out.print("\t\tPalindrome\n\t\tby Ricardo Tejada\n\n");
        System.out.print("Please enter a number: ");
        
        integer = input.nextInt();

        System.out.printf("%d is" + (isPalindrome(integer) ? " " : " not ") + "a palindrome.", integer);
    }
}