public class clas {
    public static void main(String args[])
    {
        lhx l=new lhx(8);
        System.out.println(l.getN());
    }
}

class lhx{
    private int n;

    public lhx(int a)
    {
        n=a;
    }

    public int getN()
    {
        return n;
    }
}
