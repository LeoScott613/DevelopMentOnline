package JAVA;

public class exception2 {
    public static void main(String args[]) throws hxException{
        if(true)
            throw new hxException();
    }
}
class hxException extends RuntimeException{//ͨ�������������췽��
    private static final String greet="˵HelloWorld�������";
    public hxException(){
        super(greet);
    }
    public hxException(String s){
        super(greet);
    }
}
