import java.util.Scanner;
public class P5720 {
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        int a=in.nextInt();
        int counting=1;
        while(a>1)
        {
            a/=2;
            counting++;
        }
        System.out.println(counting);
        in.close();
    }
}
