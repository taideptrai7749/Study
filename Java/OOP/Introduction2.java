import java.util.Scanner;

class Rectangle {
    double length, width;

    public void getInformation() {
        Scanner sc = new Scanner(System.in);
        length = sc.nextDouble();
        width = sc.nextDouble();
    }

    public double getArea() {
        return width * length;
    }

    public double getPerimeter() {
        return 2 * (width + length);
    }

    public void display() {
        System.out.println("Area: " + getArea());
        System.out.println("Perimeter: " + getPerimeter());
    }
}

public class Introduction2 {
    public static void main(String[] args) {
        Rectangle r = new Rectangle();
        r.getInformation();
        r.display();
    }
}