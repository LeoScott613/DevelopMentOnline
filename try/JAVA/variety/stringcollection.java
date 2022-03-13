package JAVA.variety;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.Scanner;
public class stringcollection {
    public static void main(String args[]) {
        Collection<String> q=new ArrayList<>();
        Scanner in=new Scanner(System.in);
        String line;
        for(int i=0;i<3;i++) {
            line=in.nextLine();
            q.add(line);
        }
        Iterator<String> iq=q.iterator();
        while(iq.hasNext())
            System.out.print(iq.next());
        in.close();
    }
}
