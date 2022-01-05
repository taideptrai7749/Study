class Fraction{
    private int numerator;
    private int denominator;
    public Fraction(){

    }
    public Fraction(int num, int den){
        this.numerator = num;
        this.denominator = den;
    }
    public Fraction (Fraction f){
        this.numerator = f.numerator;
        this.denominator = f.denominator;
    }
    public Fraction add(Fraction f){
        int x = (this.numerator*f.denominator) + (this.denominator*f.numerator);
        int y = this.denominator * f.denominator;
        this.numerator = x/gcd(x,y);
        this.denominator = y/gcd(x,y);
        return this;
    }
    public Fraction sub(Fraction f){
        int x = (this.numerator*f.denominator) + (this.denominator*(-f.numerator));
        int y = this.denominator * f.denominator;
        this.numerator = x/gcd(x,y);
        this.denominator = y/gcd(x,y);
        return this;
    }
    public int gcd(int a, int b) {
        if(b == 0) return a;
        else
        return gcd(b, a%b);
    }
    public String toString(){
        return this.numerator + "/" + this.denominator;
    }
}

public class Ex4 {
    public static void main(String[] args) {
        Fraction f1 = new Fraction(3,4);
        Fraction f2 = new Fraction(5,6);
        f1.sub(f2);
        System.out.println(f1.toString());
    }
}
