package JAVA.variety;
import java.lang.Object;
public class tostring {
    public static void main(String[] args) {
        book coreJ=new book("Core Java Volume I",false);
        System.out.println(coreJ.toString());
    }
}
class book extends Object {
    private String name;
    private boolean completion;
    public book(String s,boolean c) {
        //construction
        this.name=s;
        this.completion=c;
    }
    public book() {
        //allow to contruct empty
        this.name="default";
        this.completion=false;
    }
    public String toString() {
        String comp;
        if(completion)
            comp="yes";
        else comp="no";
        return new String("Name:"+this.name+"\nCompletion:"+comp);
    }
}