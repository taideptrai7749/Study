import java.util.Scanner;

public class Ex7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char c = sc.next().charAt(0);
        if (isAlphanumeric(c)) {
            System.out.println("This is an alphanumerical character");
        } else {
            System.out.println("This is not an alphanumerical character");
        }
    }

    public static boolean isAlphanumeric(char c) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            return true;
        } else {
            return false;
        }
    }
}
