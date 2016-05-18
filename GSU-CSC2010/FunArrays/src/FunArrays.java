// Ricardo Tejada


import java.util.Scanner;

public class FunArrays {

	public static void main(String[] args)
	{
        Scanner input = new Scanner(System.in);
        int arraySize;
        int[] array;
        boolean run = true;

        while(run)
        {
            System.out.println("Please enter how big you want the array to be: ");
            arraySize = input.nextInt();
            array = new int[arraySize];

            System.out.println("Please enter " + arraySize + " number(s) separated by spaces");

            input.nextLine(); // Remove junk in buffer
            for(int i = 0; i < arraySize; i++)
                array[i] = input.nextInt();

            if(isLucky(array))
                System.out.println(sum(array));
            else
                System.out.println(sumOfEvens(array));

            input.nextLine(); // Remove junk in buffer
            run = goAgain(input);
        }
	}

	static boolean isLucky(int[] array)
	{
        for(int i = 0; i < array.length; i++)
        {
            if(array[i] == 7 || array[i] == 13 || array[i] == 18)
                return true;
        }

        return false;
	}

	static int sum(int[] array)
	{
        int val = 0;

        for(int i = 0; i < array.length; i++)
            val += array[i];

        return val;
	}

	static int sumOfEvens(int[] array)
	{
        int val = 0;

        for(int i = 0; i < array.length; i++)
            val += (array[i] % 2) == 0 ? array[i] : 0;

        return val;
	}

    static int dotProduct(int[] arrayA, int[] arrayB)
    {
        int val = 0;

        for(int i = 0; i < arrayA.length; i++)
            val += arrayA[i] * arrayB[i];

        return val;
    }

    static boolean goAgain(Scanner input)
    {
        System.out.println("Do you want to check if another array is lucky, punk?: ");

        while(true)
        {
            String str = input.next();

            if(str.equals("yes") || str.equals("Yes") || str.equals("YES"))
                return true;
            else if(str.equals("no") || str.equals("No") || str.equals("NO"))
                return false;

            input.nextLine(); // Remove junk in buffer
            System.out.println("Sorry what was that? Please enter Yes or No: ");
        }
    }
}
