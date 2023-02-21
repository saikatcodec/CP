
abstract class Shape {
    public String s;


    Shape(String s) {
        this.s = s;
        System.out.println("I am in shape");
    }
}

class Rectangle extends Shape {
    int hight, weight;


    Rectangle(int hight, int weight, String s) {
        super(s);
        this.hight = hight;
        this.weight = weight;
        System.out.println("I am in rect " + this.s);
    }
}



public class simple {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(3, 4, "Black");

        System.out.println(r1.hight + " " + r1.s);
    }
}