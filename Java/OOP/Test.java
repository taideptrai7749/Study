
class Student {
    private int age;
    private String name;

    public Student(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public Student(Student s) {
        age = s.age;
        name = s.name;
    }

    public void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }

}

public class Test {
    public static void main(String[] args) {
        Student s1 = new Student(18, "Phuong Tai");
        Student s2 = new Student(s1);

        s1.display();
        s2.display();
    }
}