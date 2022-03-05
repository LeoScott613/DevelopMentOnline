package JAVA;
import java.sql.*;

public class conn2 {
    public static final String u = "root";
    public static final String p = "171026";

    public static void main(String args[]) throws Exception {
        Class.forName("com.mysql.jdbc.Driver");
        Connection c = DriverManager.getConnection("jdbc:mysql:///mydb", u, p);
        Statement s = c.createStatement();
        ResultSet r = s.executeQuery("SELECT * FROM TB2");
        while (r.next())
            System.out.println(r.getString("CHUNK"));
    }
}
