package JAVA.variety;
import java.util.*;
public class exception1 {
    public static void main(String args[]) throws Exception{
        int taboo;
        Scanner in=new Scanner(System.in);
        taboo=in.nextInt();
        in.close();
        if(taboo==114514)
            throw new Exception();
        System.out.println("©ирт");
    }
}
