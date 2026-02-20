import java.util.Scanner;
import java.util.ArrayList;

public class GenericClass {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter The Length of Rectangle: ");
        int lenRec = sc.nextInt();
        System.out.println("Enter The Width of Rectangle: ");
        int widRec = sc.nextInt();

        Rectangle testRectangle = new Rectangle(lenRec,widRec);

        System.out.println("Area of Rectangle: " + testRectangle.areaRectangle());
        testRectangle.draw();

        //------------------------------------------------------------------
        //------------------------------------------------------------------

        System.out.println("\nEnter The radius of Circle: ");
        int radius = sc.nextInt();

        Circle testCircle = new Circle(radius);

        System.out.println("Area of Circle: " + testCircle.areaCircle());
        testCircle.draw();

        //------------------------------------------------------------------
        //------------------------------------------------------------------


        ArrayList<Rectangle> rectangles = new ArrayList<>();
        rectangles.add(new Rectangle(5, 10));
        rectangles.add(new Rectangle(3, 7));

        ShapeTest.drawShapes(rectangles);

        ArrayList<Circle> circles = new ArrayList<>();
        circles.add(new Circle(2));
        circles.add(new Circle(6));

        ShapeTest.drawShapes(circles);

    }
}
//------------------------------------------------------------------
//------------------------------------------------------------------
abstract class Shape  {
    abstract void draw();
}
//------------------------------------------------------------------
//------------------------------------------------------------------
class Rectangle extends Shape {
    private int length;
    private int width;

    public Rectangle(int length, int width)
    {
        this.length=length;
        this.width=width;
    }

    public int areaRectangle() {
        return length * width;
    }

    @Override
    public void draw() {
        System.out.println("Believe me, I drew a rectangle\n");
    }
}
//------------------------------------------------------------------
//------------------------------------------------------------------
class Circle extends Shape {
    private double radius;

    public Circle(double radius)
    {
        this.radius = radius;
    }

    public double areaCircle() {
        return (radius*radius*Math.PI);
    }

    @Override
    public void draw()
    {
        System.out.println("Believe me, I drew a circle\n");
    }
}
//------------------------------------------------------------------
//------------------------------------------------------------------
class ShapeTest {
    public static void drawShapes(ArrayList<? extends Shape> shapes) {
        System.out.println("HII");
        for (int i = 0; i < shapes.size(); i++){
            shapes.get(i).draw();
        }
    }
}

