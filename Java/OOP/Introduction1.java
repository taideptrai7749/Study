import java.util.Scanner;

class Student {
    String name;
    int age;

    public void getInformation() {
        Scanner sc = new Scanner(System.in);
        name = sc.nextLine();
        age = sc.nextInt();
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

public class Introduction1 {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.getInformation();
        s1.display();
    }
}
