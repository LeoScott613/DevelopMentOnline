public class statik {
    public static void main(String[] args) {
        MethodBucket.setNumber(111);
        int result=MethodBucket.getDoubleNumber();
        System.out.println(result);
    }
}
class MethodBucket {
    private static int number;
    public static void setNumber(int i) {
        number=i;
    }
    public static int getDoubleNumber() {
        return number*2;
    }
}
