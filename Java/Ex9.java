import java.util.Scanner;

public class Ex9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("First digit: " + firstDigit(n));
        System.out.println("Last digit: " + lastDigit(n));
    }

    public static int lastDigit(int n) {
        return n % 10;
    }

    public static int firstDigit(int n) {
        while (n >= 10) {
            n = n / 10;
        }
        return n;
    }
}
