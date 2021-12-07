import java.util.Scanner;

public class Ex10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("Sum of Digit: " + sumOfDigit(n));
        System.out.println("Product of Digit: " + productOfDigit(n));
    }

    public static int sumOfDigit(int n) {
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            sum = sum + rem;
            n = n / 10;
        }
        return sum;
    }

    public static int productOfDigit(int n) {
        int product = 1;
        while (n > 0) {
            int rem = n % 10;
            product = product * rem;
            n = n / 10;
        }
        return product;
    }
}
