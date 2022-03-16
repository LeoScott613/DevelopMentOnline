package JAVA.variety;

public class mutli_thread {
    public static void main(String args[]) throws InterruptedException {
        ThreadL thr=new ThreadL();
        thr.start();
        ThreadM thm=new ThreadM();
        thm.start();
    }
}
class ThreadL extends Thread {
    public ThreadL() {
        super();
    }
    public void run() {
        for(int i=0;i<30;i++) {
            System.out.println(1);
        }
    }
}
class ThreadM extends Thread {
    public ThreadM() {
        super();
    }
    public void run() {
        for(int i=0;i<30;i++) {
            System.out.println(0);
        }
    }
}
class KillThread extends Thread {
    private static ThreadM tm;
    private static ThreadL tl;
    public KillThread(ThreadM intm,ThreadL intl) {
        super();
        tm=intm;
        tl=intl;
    }
    public void run() {
        try{
            tm.wait();
            tl.wait();
        }
        catch(InterruptedException ie) {
            ie.printStackTrace();
        }
    }
}