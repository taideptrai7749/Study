
import java.util.Scanner;
import java.util.Random;

public class GuessNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        int randomNum = rand.nextInt(21);
        int n = sc.nextInt();
        randomGame(n, randomNum);
    }

    public static void randomGame(int n, int randomNum) {
        Scanner sc = new Scanner(System.in);
        boolean stop = false;
        while (stop != true) {
            if (n < randomNum) {
                System.out.print("Too low, try again: ");
                n = sc.nextInt();
            } else if (n > randomNum) {
                System.out.print("Too big, try again: ");
                n = sc.nextInt();
            } else {
                System.out.println("Congratulations, you've done it");
                stop = true;
            }
        }
    }
}