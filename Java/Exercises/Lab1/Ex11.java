import java.util.Scanner;

public class Ex11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("The remainder of a/b is " + remainder(a, b));
    }

    public static int remainder(int a, int b) {
        return a % b;
    }
}
