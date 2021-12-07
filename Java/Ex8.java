import java.util.Scanner;

public class Ex8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("a/ S = " + sum(n));
        System.out.println("b/ P = " + factorial(n));
        System.out.println("c/ S = " + exponent(n));
        System.out.println("d/ S = " + fraction(n));
        System.out.println("e/ Result = " + sigma(n));
    }

    public static int sum(int n) {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s = s + i;
        }
        return s;
    }

    public static int factorial(int n) {
        if (n == 1 || n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    public static int powerOf(int n, int k) {
        int s = 1;
        for (int i = 0; i < k; i++) {
            s = s * n;
        }
        return s;
    }

    public static int exponent(int n) {
        int s = 0;
        for (int i = 0; i <= n; i++) {
            s = s + powerOf(2, i);
        }
        return s;
    }

    public static double fraction(int n) {
        double s = 0;
        for (int i = 1; i <= n; i++) {
            s = s + 1 / (i * 2.0);
        }
        return s;
    }

    public static int sigma(int n) {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s = s + powerOf(i, 2);
        }
        return s;
    }
}
