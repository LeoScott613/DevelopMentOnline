package JAVA;

public class exception2 {
    public static void main(String args[]) throws hxException{
        if(true)
            throw new hxException();
    }
}
class hxException extends RuntimeException{//通常定义两个构造方法
    private static final String greet="说HelloWorld的奇妙方法";
    public hxException(){
        super(greet);
    }
    public hxException(String s){
        super(greet);
    }
}
