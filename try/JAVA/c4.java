package JAVA;

import java.sql.*;
import java.util.Scanner;

public class c4 {
    public static void main(String args[]) throws Exception {//这是在首部声明可能抛出的异常类型
        Scanner in = new Scanner(System.in);
        System.out.println("Please enter user and password line by line");
        String user = in.nextLine();
        String pass = in.nextLine();
        capsule mydb=new capsule(user,pass);
        mydb.init();
        mydb.exe("DELETE FROM TB2 WHERE ID = 7;");
        in.close();
    }
}

class capsule {
    private static String user;
    private static String pass;
    static Connection c;
    static Statement s;
    static ResultSet r;

    public capsule(String u, String p) throws Exception {
        user = u;
        pass = p;
    }

    public void init() throws Exception {
        Class.forName("com.mysql.jdbc.Driver");
        c = DriverManager.getConnection("jdbc:mysql:///mydb", user, pass);
        s = c.createStatement();
    }

    public void exe(String query) throws Exception {
        //s.executeQuery(query);
        //don't use query
        s.execute(query);
    }
/*
    public void outp() throws Exception {
        while (r.next())
            System.out.println(r.getString("QUOTE_CHUNK"));
    }
*/
}
