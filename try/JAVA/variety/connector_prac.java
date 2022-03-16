package JAVA.variety;
import java.sql.*;
public class connector_prac {
    public static final String user="root";
    public static final String password="171026";
    public static void main(String args[]) throws Exception {
        Class.forName("com.mysql.jdbc.Driver");
        Connection c=DriverManager.getConnection("jdbc:mysql:///mydb", user, password);
        Statement s=c.createStatement();
        ResultSet r=s.executeQuery("SELECT * FROM TB2");
        while(r.next()) {
            System.out.println(r.getString(1)+" "+r.getString(2)+" "+r.getString(3));
        }
    }
}
