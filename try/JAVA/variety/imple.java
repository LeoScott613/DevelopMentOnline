package JAVA.variety;

public class imple{
    public static void main(String args[]) {
        imp i=new imp();//construct purely an implementation object
        i.print();
        interf inface=new imp();//construct an interface object
        inface.print();
    }
}
class imp implements interf {
    public imp() {}
    public void print() {
        System.out.println("You smart");
    }
}
