import java.util.Scanner;

public class P5726 {
    public final static int maxn = 1000;

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        double n, goal[], max = 0, min = 11;
        goal = new double[maxn];
        n = in.nextDouble();
        for (int i = 0; i < n; i++) {
            goal[i] = in.nextDouble();
            if (max < goal[i])
                max = goal[i];
            if (min > goal[i])
                min = goal[i];
        }
        double allup = 0, number = 0;
        boolean maxc = true, minc = true;
        for (int i = 0; i < n; i++) {
            if (maxc && goal[i] == max)
                maxc = false;
            else if (minc && goal[i] == min)
                minc = false;
            else {
                allup += goal[i];
                number++;
            }
        }
        double ans = allup / number;
        System.out.printf("%.2f", ans);
        in.close();
    }
}