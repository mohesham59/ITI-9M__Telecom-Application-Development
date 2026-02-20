import java.util.function.Function;
import java.util.Scanner;

public class QuadraticEquation implements Function<Double[], Double[]> {

    @Override
    public Double[] apply (Double[] parameters)
    {
        double a = parameters[0];
        double b = parameters[1];
        double c = parameters[2];

        double D = b*b - 4*a*c;

        if (D < 0) {
            System.out.println("No real roots (D < 0)");
            return null;
        }
        double root1 = (-b + Math.sqrt(D)) / (2*a);
        double root2 = (-b - Math.sqrt(D)) / (2*a);

        return new Double[]{root1 , root2};
    }

    public static void main (String[] args) {
        QuadraticEquation equation = new QuadraticEquation();

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter parameter (a): ");
        double a = sc.nextDouble();
        System.out.println("Enter parameter (b): ");
        double b = sc.nextDouble();
        System.out.println("Enter parameter (c): ");
        double c = sc.nextDouble();

        Double[] parameters = {a, b, c};
        System.out.println("\nEquation:\nD = b*b - 4*a*c\nRoot1 = (-b + sqrt(D)) / (2*a)\nRoot2 = (-b - sqrt(D)) / (2*a)");

        Double[] result = equation.apply(parameters);

        System.out.println("\nResult of Quadratic Equation:\nRoot1: " + result[0] + "\nRoot2: " + result[1]);

    }
}
