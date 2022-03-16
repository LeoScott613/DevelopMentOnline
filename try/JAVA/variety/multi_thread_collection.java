package JAVA.variety;
import java.util.Iterator;
import java.util.LinkedList;
public class multi_thread_collection {
    public static void main(String args[]) {
        thread1 tlis1=new thread1();
        thread2 tlis2=new thread2();
        tlis1.start();
        tlis2.start();
    }
}
class thread1 extends Thread {
    public static LinkedList<Character> list1;
    public thread1() {
        super();
        list1=new LinkedList<>();
        for(char i='a';i<'g';i++) {
            list1.add(i);
        }
    }
    public void run() {
        Iterator<Character> iter=list1.iterator();
        while(iter.hasNext()) {
            System.out.println("list1, element:"+iter.next());
        }
    }
}
class thread2 extends Thread {
    public static LinkedList<Integer> list2;
    public thread2() {
        super();
        list2=new LinkedList<>();
        for(int i=0;i<7;i++) {
            list2.add(i);
        }
    }
    public void run() {
        Iterator<Integer> iter=list2.iterator();
        while(iter.hasNext()) {
            System.out.println("list2, element:"+iter.next());
        }
    }
}
