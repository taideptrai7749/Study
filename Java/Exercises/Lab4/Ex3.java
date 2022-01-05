import java.util.Scanner;
class Student{
    private int id;
    private String firstName;
    private String lastName;
    public Student(){

    }
    public Student(int id, String firstName, String lastName){
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
    }
    public int getID(){
        return this.id;
    }
    public String getFirstName(){
        return this.firstName;
    }
    public String getLastName(){
        return this.lastName;
    }
    public void setID(int id){
        this.id = id;
    }
    public void setFirstName(String firstName){
        this.firstName = firstName;
    }
    public void setLastName(String lastName){
        this.lastName = lastName;
    }
    public String getName(){
        return this.firstName + " " + this.lastName;
    }
    public String toString(){
        return "Student[id=" + this.id + ", firstName=" + this.firstName +", lastName=" + this.lastName + "]";
    }
}
public class Ex3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student st = new Student();
        String fn = sc.nextLine();
        String ln = sc.nextLine();
        int identification = sc.nextInt();
        
        st.setID(identification);
        st.setFirstName(fn);
        st.setLastName(ln);
        System.out.println(st.getName());
        System.out.println(st.toString());
    }
}
