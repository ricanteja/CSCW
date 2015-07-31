import java.util.Scanner;

class MyPoint
{
    MyPoint()
    {
        x = 0;
        y = 0;
    }

    MyPoint(double xVal, double yVal)
    {
        x = xVal;
        y = yVal;
    }

    double distance(MyPoint otherPoint)
    {
        double xVec, yVec;

        xVec = (otherPoint.getX() - x) * (otherPoint.getX() - x);
        yVec = (otherPoint.getY() - y) * (otherPoint.getY() - y);

        return Math.sqrt(xVec + yVec);
    }

    double distance(double xVal, double yVal)
    {
        double xVec, yVec;

        xVec = (xVal - x) * (xVal - x);
        yVec = (yVal - y) * (yVal - y);

        return Math.sqrt(xVec + yVec);
    }

    double getX() {return x;}

    double getY() {return y;}

    double x, y;
}

class Lab10a
{
    static void title() {System.out.print("\t\tMy Point Lab10a\n\t\tby Ricardo Tejada\n\n");}

    public static void main(String[] args)
    {
        MyPoint pointA = new MyPoint();
        MyPoint pointB = new MyPoint();
        String buffer;
        Scanner input = new Scanner(System.in);

        title();

        while(true)
        {
            //Get first point
            System.out.print("Enter x and y coordinates for p1 (or q to exit): ");
            buffer = input.nextLine();

            if(buffer.toUpperCase().charAt(0) == 'Q')
                break;

            pointA.x = Double.parseDouble(buffer.split(" ")[0]);
            pointA.y = Double.parseDouble(buffer.split(" ")[1]);
            System.out.printf("p1 = (%.6f, %.6f)\n", pointA.getX(), pointA.getY());


            //Get second point
            System.out.print("Enter x and y coordinates for p2 (or q to exit): ");
            buffer = input.nextLine();

            if(buffer.toUpperCase().charAt(0) == 'Q')
                break;

            pointB.x = Double.parseDouble(buffer.split(" ")[0]);
            pointB.y = Double.parseDouble(buffer.split(" ")[1]);
            System.out.printf("p2 = (%.6f, %.6f)\n", pointB.getX(), pointB.getY());


            //Print Distance
            System.out.printf("Distance (object to object)           = %.5f\n", pointA.distance(pointB));
            System.out.printf("Distance (object to X, Y coordinates) = %.5f\n", pointA.distance(pointB.getX(), pointB.getY()));
        }


        System.out.println("");
    }
}