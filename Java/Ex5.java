import java.util.Scanner;

public class Ex5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        System.out.println("The minimum value of the 3 inputs is " + minimum(a, b, c));
    }

    public static int minimum(int a, int b, int c) {
        if (a <= b && a <= c) {
            return a;
        } else if (b < c) {
            return b;
        } else {
            return c;
        }
    }
}
