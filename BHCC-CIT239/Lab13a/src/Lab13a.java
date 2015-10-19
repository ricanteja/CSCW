import java.util.Scanner;

public class Lab13a
{
    /** Main method */
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String buffer;

        double side1, side2, side3;

        System.out.print("Enter three sides: ");
        buffer = input.nextLine();

        side1 = Double.parseDouble(buffer.split(" ")[0]);
        side2 = Double.parseDouble(buffer.split(" ")[1]);
        side3 = Double.parseDouble(buffer.split(" ")[2]);

        GeometricObject triangle = new Triangle(side1, side2, side3);

        System.out.print("Enter the color: ");
        buffer = input.nextLine();

        triangle.setColor(buffer);

        System.out.print("Enter a boolean value for filled: ");
        buffer = input.nextLine();

        triangle.setFilled(Boolean.parseBoolean(buffer));

        System.out.printf("Triangle: " + triangle.toString() +
                ",\nPerimeter = %6.2f, Area = %6.2f\n", triangle.getPerimeter(), triangle.getArea());
    }
}