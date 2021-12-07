import java.util.Scanner;

public class Ex3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the fahrenheit degree: ");
        float f_degree = sc.nextFloat();
        System.out.println("The degree in Celcius: " + fToC(f_degree));

        System.out.print("Enter the celcius degree: ");
        float c_degree = sc.nextFloat();
        System.out.println("The degree in Fahrenheit: " + cToF(c_degree));
    }

    public static float fToC(float f) {
        return ((f - 32) * 5) / 9;
    }

    public static float cToF(float c) {
        return (9 * c) / 5 + 32;
    }
}
