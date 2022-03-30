import java.sql.*;
import java.util.Scanner;
public class bookshelf_manager {
    public static void main(String[] args) throws Exception {
        //customized
        Scanner in=new Scanner(System.in);
        System.out.println("enter your user name");
        String user=in.nextLine();
        System.out.println("enter your user password");
        String password=in.nextLine();

        Class.forName("com.mysql.cj.jdbc.Driver");
        Connection bookshelf=DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb",user, password);
        Statement stmt=bookshelf.createStatement();
        ResultSet rs=stmt.executeQuery("SELECT ID FROM BOOKSHELF");
        ResultSetMetaData dataOfBookshelf=rs.getMetaData();
        int lineCount=0;
        while(rs.next()) {
            lineCount++;
        }

        boolean switc=true;
        while(switc) {
            System.out.println("enter the name of book:");
            String bookName=in.nextLine();
            System.out.println("enter the importance of book:");
            int importance=in.nextInt();
            System.out.println("Have you finished it yet? (true/false)");
            boolean completion=in.nextBoolean();
            int affected=stmt.executeUpdate("INSERT INTO BOOKSHELF VALUES ("+(++lineCount)+",\'"+bookName+"\',"+
            importance+','+completion+");");
            System.out.println(affected+" row affected");
            //update operation above

            System.out.println("if you want to continue?(1/0)");
            int intswitc=in.nextInt();
            if(intswitc==0)
                switc=false;
            else
                switc=true;
        }

        in.close();
        bookshelf.close();
    }
}
