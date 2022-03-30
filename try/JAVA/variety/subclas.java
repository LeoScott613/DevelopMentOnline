public class subclas {
    public static void main(String[] args) throws privateExp{
        up aUp=new up(1926);
        sub aSub=new sub(0);
        System.out.println(aSub.getAge());
        aSub.setAge(1926);
        //System.out.println(aUp.getSecret());     no
        System.out.println(aSub.getAge());
        aSub.getSecret();
    }
}

class up {
    private int Age;
    private String Secret;
    public up(int getage) {
        Age=getage;
        Secret="you're elegant";
    }
    public int getAge() {
        return Age;
    }
    public void setAge(int age) {
        Age=age;
        getSecret();  //ok in this class
    }
    private String getSecret() {
        return Secret;
    }
}

class sub extends up {
    public sub(int a) {
        super(a);
    }
    //can I redefine the method of the superclass?
    public void setAge(int age) {
        /*Age=age;*/   //Age is private in the superclass
        super.setAge(age);
    }
    public void getSecret() throws privateExp {
        /*String s=super.getSecret();*/    //.getSecret in the superclass is private
        throw new privateExp();
    }
}

class privateExp extends RuntimeException{
    private final static String greet="no no no! Never try to access a private method!---lhx";
    public privateExp() {
        super(greet);
    }
}