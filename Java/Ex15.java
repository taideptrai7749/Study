import java.util.Scanner;

public class Ex15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int stop = 1;
        int mode;
        double money;
        while (stop == 1) {
            System.out.println("----Menu----");
            System.out.println("1. Coca");
            System.out.println("2. Pepsi");
            System.out.println("3. Sprite");
            System.out.println("4. Snack");
            System.out.println("5. Shutdown Machine");
            System.out.print("Please enter the number: ");
            mode = sc.nextInt();
            while (mode > 5 || mode < 1) {
                System.out.print("Wrong input, try again: ");
                mode = sc.nextInt();
            }
            switch (mode) {
                case 1:
                    System.out.println("The price of Coca is 2$. Enter the amount of money");
                    money = sc.nextDouble();
                    if (money >= 2) {
                        System.out.println("Your change is " + (money - 2) + "$");
                    } else {
                        System.out.println("Not enough money to buy this item. Select again");
                    }
                    break;
                case 2:
                    System.out.println("The price of Pepsi is 4$. Enter the amount of money");
                    money = sc.nextDouble();
                    if (money >= 4) {
                        System.out.println("Your change is " + (money - 4) + "$");
                    } else {
                        System.out.println("Not enough money to buy this item. Select again");
                    }
                    break;
                case 3:
                    System.out.println("The price of Sprite is 1$. Enter the amount of money");
                    money = sc.nextDouble();
                    if (money >= 1) {
                        System.out.println("Your change is " + (money - 1) + "$");
                    } else {
                        System.out.println("Not enough money to buy this item. Select again");
                    }
                    break;
                case 4:
                    System.out.println("The price of Snack is 5$. Enter the amount of money");
                    money = sc.nextDouble();
                    if (money >= 5) {
                        System.out.println("Your change is " + (money - 5) + "$");
                    } else {
                        System.out.println("Not enough money to buy this item. Select again");
                    }
                    break;
                case 5:
                    System.out.println("Machine is shutting down");
                    stop = 0;
                    break;
            }
        }
    }
}