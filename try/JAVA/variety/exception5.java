

public class exception5 {
    public static void main(String args[]) throws hxcx{
        if(true)
            throw new hxcx();
    }
}
class hxcx extends RuntimeException{
    private static final String greet="This is a customized exception information. It actually doesn't represent anything.";
    public hxcx(){
        super(greet);
    }
}
