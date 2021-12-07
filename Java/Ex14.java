import java.util.Scanner;

public class Ex14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (isPalindrome(n)) {
            System.out.println("This is a palindrome number");
        } else {
            System.out.println("This is not a palindrome number");
        }
    }

    public static boolean isPalindrome(int n) {
        int originalNum = n;
        int reverseNum = 0;
        while (n > 0) {
            int rem = n % 10;
            reverseNum = reverseNum * 10 + rem;
            n = n / 10;
        }
        if (originalNum == reverseNum)
            return true;
        return false;
    }
}
