/**
 * Created by Ricky on 1/29/2016.
 */
public class Song
{
    public static void printHook()
    {
        System.out.println("I don't know why it wouldn't compile,");
        System.out.println("My TA just smiled.\n");
    }

    public static void print1()
    {
        System.out.println("I added System.out.println(\"I <3 coding\"),");
    }

    public static void print2()
    {
        System.out.println("I added a backslash to escape the quotes,");
        print1();
    }

    public static void print3()
    {
        System.out.println("I added a main method with its String[] args,");
        print2();
    }

    public static void print4()
    {
        System.out.println("I added a public class and called it Scum,");
        print3();
    }

    public static void main(String[] args)
    {
        System.out.println("I once wrote a program that wouldn't compile");
        printHook();

        System.out.println("My program did nothing");
        System.out.println("So I started typing.");
        print1();
        printHook();

        System.out.println("\"Parse error,\" cried the compiler");
        System.out.println("Luckily I'm such a code baller.");
        print2();
        printHook();

        System.out.println("Now the compiler wanted an identifier");
        System.out.println("And I thought the situation was getting dire.");
        print3();
        printHook();

        System.out.println("Java complained it expected an enum");
        System.out.println("Boy, these computers really are dumb!");
        print4();
        printHook();
    }
}
