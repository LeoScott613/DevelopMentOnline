package JAVA.variety;
import JAVA.variety.imp;
public class clas {
    //this instance is for show how to use Class
    public static void main(String[] args) {
        Class<imp> cls=imp.class;//Class is a raw type
        System.out.println(cls.getName());
    }
}
