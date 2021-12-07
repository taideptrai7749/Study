import java.util.Scanner;

public class Ex6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        check(n);
    }

    public static void check(int n) {
        if (n % 2 == 0)
            System.out.println("This is an even number");
        else
            System.out.println("This is an odd number");
    }
}
