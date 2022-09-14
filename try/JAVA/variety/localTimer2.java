import java.util.Timer;
import java.util.TimerTask;
import java.util.Scanner;
public class localTimer2 {
    public static void main(String args[]) {
        Timer water=new Timer();
        TimerTask drink=new TimerTask() {
            public void run() {
                System.out.println("You should drink water");
                //water.cancel();  //should keep reminding
            }
        };
        Scanner in=new Scanner(System.in);
        System.out.println("你想隔多久喝一次水:");
        int duration=in.nextInt();
        
        water.schedule(drink,duration*1000,duration*1000);
        String blank;
        System.out.println("记录了，你可以做任何事情");
        while(true) {
            blank=in.nextLine();
            if(blank.equals("exit")) {
                water.cancel();
                break;
            }
        }
        in.close();
    }
}