package JAVA.variety;

public class imple{
    public static void main(String args[]) {
        imp i=new imp();
        i.print();
    }
}
class imp implements interf {
    public imp() {}
    public void print() {
        System.out.println("You smart");
    }
}
