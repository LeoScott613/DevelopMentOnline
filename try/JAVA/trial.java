package JAVA;
import java.util.*;
public class trial {
    public static void main(String args[])
    {
        try{
            int i=1/0;
        }
        catch(RuntimeException e)
        {
            System.out.println("helloworld");
        };
    }
}
