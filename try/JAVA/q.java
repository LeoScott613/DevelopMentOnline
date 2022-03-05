package JAVA;
import java.util.LinkedList;
import java.util.Queue;
public class q{
    public static void main(String args[])
    {
        Queue<String> qu=new LinkedList<>();
        qu.add("Ni");
        qu.add("Hao");
        while(qu.size()>0)
            System.out.println(qu.poll());
    }
}