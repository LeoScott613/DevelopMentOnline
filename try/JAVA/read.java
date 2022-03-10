package JAVA;
import java.util.Scanner;
import java.io.IOException;
import java.nio.file.*;
public class read {
    public static void main(String args[]) throws IOException{
        Scanner fin=new Scanner(Paths.get("my"),"UTF-8");
        String let=fin.nextLine();
        System.out.println(let);
        fin.close();
    }
}
