import java.util.Scanner;


public class Lab18a
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int number1, number2;

        System.out.print("Enter two integers (or 'q' to exit): ");

        if(!scanner.hasNext("q") && !scanner.hasNext("Q"))
        {
            number1 = scanner.nextInt();
            number2 = scanner.nextInt();

            System.out.printf("The GCD of %d and %d is %d", number1, number2, gcd(number1, number2));
        }
    }

    public static int gcd(int m, int n)
    {
        System.out.printf("Entering 'gcd' method: m = %d, n = %d\n", m, n);
        int result = n;

        if(m % n != 0)
        {
            result = gcd(n, m % n);
            System.out.printf("Returning 'gcd' value = %d (recursive case:  m = %d, n = %d)\n", result, m, n);
            return result;
        }

        System.out.printf("Returning 'gcd' value = %d (BASE CASE:       m = %d, n = %d)\n", result, m, n);
        return result;
    }
}