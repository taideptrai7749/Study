import java.util.Scanner;
class Rectangle {
    private float width = 1.0f;
    private float length = 1.0f;
    public Rectangle(){

    }
    public Rectangle(float width, float length){
        this.width = width;
        this.length = length;
    }
    public float getWidth(){
        return this.width;
    }
    public float getLength(){
        return this.length;
    }
    public void setWidth(float width){
        this.width = width;
    }
    public void setLength(float length){
        this.length = length;
    }
    public String toString(){
        return "Rectangle [width: " + this.width + ", length: "+this.length+ "]";
    }
}
public class Ex2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float width = sc.nextFloat();
        float length = sc.nextFloat();
        Rectangle rec = new Rectangle();
        rec.setWidth(width);
        rec.setLength(length);
        System.out.println(rec.toString());
    }
}
