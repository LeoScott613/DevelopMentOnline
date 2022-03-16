package JAVA.variety;
import java.sql.*;

public class connector {
    public final static String u = "root";
    public final static String p = "171026";

    public static void main(String args[]) throws Exception {//must 
        Class.forName("com.mysql.jdbc.Driver");//load the driver
        Connection conn=DriverManager.getConnection("jdbc:mysql:///mydb", u, p);//get connection to the database
        Statement stat=conn.createStatement();
        ResultSet rs=stat.executeQuery("SELECT * FROM TB2");
        ResultSetMetaData rms=rs.getMetaData();
        System.out.println(rms.getColumnCount());
        while(rs.next())
        {
            System.out.println(rs.getString(3));
        }
    }
}
