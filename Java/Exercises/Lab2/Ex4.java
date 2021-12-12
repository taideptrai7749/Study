import java.util.Scanner;

public class Ex4 {
    public static int findSpecifiedElelemt(int arr[]) {
        boolean[] flag = new boolean[arr.length];
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            flag[i] = true;
        }
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] == arr[j])
                    flag[j] = false;
            }
        }
        for (int i = 0; i < arr.length; i++) {
            if (flag[i] == true) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Number of specified value in the array: " + findSpecifiedElelemt(arr));
    }
}
