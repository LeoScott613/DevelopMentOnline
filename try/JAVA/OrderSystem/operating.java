package JAVA.OrderSystem;
import java.util.Scanner;
public class operating {
    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int number=in.nextInt();
        item[] shelf=new item[number];
        for(int i=0;i<number;i++) {
            shelf[i]=new item();
        }
        for(int i=0;i<number;i++) {
            shelf[i].new_id(in.nextInt());
            shelf[i].new_name(in.next());
            shelf[i].new_date(in.nextLong());
            shelf[i].new_address(in.next());
        }
        //operation remains blank
        in.close();
    }
}
