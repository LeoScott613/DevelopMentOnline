package JAVA.utilapp;
import java.util.*;
public class calculator {
    public static void main(String[] args) {
        char sign;
        int a,b;
        Scanner in=new Scanner(System.in);
        //disadvanage: only can input the number line by line
        a=in.nextInt();
        sign=in.next().charAt(0);
        b=in.nextInt();
        in.close();
        int result=0;
        if(sign=='+')
            result=a+b;
        else if(sign=='-')
            result=a-b;
        else if(sign=='*'||sign=='x')
            result=a*b;
        else if(sign=='/'){
            try {
                result=a/b;
            }
            catch(ArithmeticException e1) {
                System.out.println("error");
                return ;
            }
        }
        else {
            try {
                throw new RuntimeException();
            }
            catch(RuntimeException e2) {
                System.out.println("Your input is illegal");
                return ;
            }
        }
        System.out.println(result);
    }
}