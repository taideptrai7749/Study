import java.util.Scanner;

public class Ex2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the height: ");
        float height = sc.nextFloat();
        System.out.print("Enter the base: ");
        float base = sc.nextFloat();
        float area = (base * height) / 2;
        System.out.println("Area = " + area);
    }
}
