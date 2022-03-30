import java.util.Iterator;
import java.util.LinkedList;
public class collection {
    public static void main(String args[]) {
        LinkedList<Integer> linklist=new LinkedList<>();
        for(int i=0;i<20;i++)
            linklist.add(i);
        Iterator<Integer> it=linklist.iterator();
        while(it.hasNext()) {
            System.out.println("element in linklist is "+it.next());
        }
    }
}
