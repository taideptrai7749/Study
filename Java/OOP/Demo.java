import java.util.Scanner;

class Rectangle {
    public Rectangle(double d, double w) {
        System.out.println(d * w);
    }

    public Rectangle(int d, int w) {
        System.out.println(d * w);
    }

}

public class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double height = sc.nextDouble();
        double width = sc.nextDouble();
        int h = sc.nextInt();
        int w = sc.nextInt();
        Rectangle rectangle1 = new Rectangle(height, width);
        Rectangle rectangle2 = new Rectangle(h, w);
    }
}