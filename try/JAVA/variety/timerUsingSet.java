import java.util.Timer;
import java.util.TimerTask;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
public class timerUsingSet {
    public static void main(String args[]) {
        List<Timer> dicipline=new ArrayList<>();
        for(int i=0;i<3;i++)
            dicipline.add(new Timer());

        List<TimerTask> tasks=new ArrayList<>();
        TimerTask drink=new TimerTask() {
            public void run() {
                System.out.println("You should drink water");
                //water.cancel();  //should keep reminding
            }
        };
        TimerTask game=new TimerTask() {
            public void run() {
                System.out.println("You should play game");
                //water.cancel();  //should keep reminding
            }
        };
        TimerTask exercise=new TimerTask() {
            public void run() {
                System.out.println("You should exercise");
                //water.cancel();  //should keep reminding
            }
        };
        tasks.add(drink);
        tasks.add(game);
        tasks.add(exercise);

        Scanner in=new Scanner(System.in);

        List<Integer> duration=new ArrayList<>();
        System.out.println("你想隔多久喝一次水:");
        duration.add(in.nextInt());
        System.out.println("你想隔多久玩一次游戏:");
        duration.add(in.nextInt());
        System.out.println("你想隔多久运动一次:");
        duration.add(in.nextInt());

        Iterator<Timer> monitor=dicipline.iterator();
        Iterator<TimerTask> plan=tasks.iterator();
        Iterator<Integer> delay=duration.iterator();

        for(int i=dicipline.size();i>0;i--) {
            int _delay=delay.next();
            monitor.next().schedule(plan.next(),_delay*1000,_delay*1000);
        }

        String blank;
        System.out.println("记录了，你可以做任何事情，输入exit退出");
        while(true) {
            blank=in.nextLine();
            if(blank.equals("exit")) {
                Iterator<Timer> killer=dicipline.iterator();
                while(killer.hasNext())
                    killer.next().cancel();
                break;
            }
        }
        in.close();
        /*
        一些注意点:
        每一个Timer仅对应唯一一个线程。
        Timer不保证任务执行的十分精确。
        Timer类的线程安全的。
        */
    }
}