import java.util.Scanner;

public class Ex8 {
    public static Integer findMax(Integer arr[]) {
        Integer max = new Integer(arr[0]);
        for (int i = 0; i < arr.length; i++) {
            if (max <= arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Maximum value of the array: " + findMax(arr));
    }
}
