class Point{
    private float x = 0.0f;
    private float y = 0.0f;
    public Point(){
        
    }
    public Point(float x, float y){
        this.x = x;
        this.y = y;
    }
    public float getX(){
        return this.x;
    }
    public float getY(){
        return this.y;
    }
}

public class Ex1 {
    public static void main(String[] args) {
        Point p = new Point();
        System.out.println(p.getY());
    }
}
