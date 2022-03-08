package JAVA;
import java.sql.*;
import java.util.*;
public class c5 {
    public static final String user="root";
    public static final String password="171026";
    public static void main(String args[]) throws Exception{
        Class.forName("com.mysql.jdbc.Driver");
        Connection c=DriverManager.getConnection("jdbc:mysql:///mydb", user, password);
        Statement s=c.createStatement();
        Scanner in=new Scanner(System.in);
        String command=in.nextLine();
        s.execute(command);
        in.close();
    }
}
