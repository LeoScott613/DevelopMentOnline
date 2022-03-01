import java.util.Scanner;
public class P1980 {
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt(), lookfor=in.nextInt();
        int count=0;
        for(int i=1;i<=n;i++)
            for(int bakup=i;bakup>0;bakup/=10)
            {
                int qu=bakup%10;
                if(qu==lookfor)
                    count++;
            }
        System.out.println(count);
        in.close();
    }
}
