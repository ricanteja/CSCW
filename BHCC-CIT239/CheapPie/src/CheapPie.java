import java.util.Scanner;

public class CheapPie
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int loopMax = 10;
        int loopCount;
        double piOver = 0;

        System.out.print("Enter maximum loop count: ");

        loopCount = input.nextInt();

        System.out.println("Maximum loop count = " + loopMax);
        System.out.println("    Count    Approximation    Error            Variance (%)        Term \'i\'");

        for(double i = 1; i <= loopCount; ++i)
        {
            piOver += (i % 2 == 0 ? -1 : 1) / (2 * i - 1);
            
            if(i <= 50 || (i % 100 == 0 || i % 100 == 1 || i == loopCount))
            System.out.printf("%8d:    %.10f    %+014.10f    %+014.10f %%  %+013.10f\n", (int)i, piOver * 4,
                    -Math.PI + piOver * 4, ((-Math.PI + piOver * 4) / Math.PI) * 100, (i % 2 == 0 ? -1 : 1) / (2 * i - 1));
        }

        System.out.printf("  Math.PI =  %.10f", Math.PI);
    }
}
