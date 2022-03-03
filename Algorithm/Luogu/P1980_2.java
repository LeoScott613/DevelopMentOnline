import java.util.Scanner;

public class P1980_2 {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), what = in.nextInt();
        inf solu = new inf();
        for (int i = 1; i <= n; i++) {
            solu.update(i);
            solu.search(what);
        }
        System.out.println(solu.allup());
        in.close();
    }
}

class inf {
    private int what;
    private int curnumb;
    private int count;

    public inf() {
        count = 0;
        what = 0;
        curnumb = 0;
    }

    public void update(int n) {
        curnumb = n;
    }

    public void search(int x) {
        what = x;
        int bakup = curnumb;
        while (bakup > 0) {
            if (bakup % 10 == what)
                count++;
            bakup /= 10;
        }
    }

    public int allup()
    {
        return count;
    }
}
