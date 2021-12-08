import java.util.Scanner;

public class Ex13 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("The reversed number is: " + reverse(n));
    }

    public static int reverse(int n) {
        int reversedNum = 0;
        while (n > 0) {
            int rem = n % 10;
            reversedNum = reversedNum * 10 + rem;
            n = n / 10;
        }
        return reversedNum;
    }
}
