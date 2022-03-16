//package JAVA.servlet;
import java.sql.*;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.util.LinkedList;
public class cityServ extends HttpServlet {
    private static final String user="root";
    private static final String password="171026";
    private Connection con=null;
    private Statement stat=null;
    private ResultSet r=null;
    private String printTable=new String("<table style=\"text-align:center;\" border=\"1\">");
    public cityServ() throws SQLException,ClassNotFoundException{
        super();
        init_db();
    }
    public void init_db() throws SQLException,ClassNotFoundException{
        Class.forName("com.mysql.cj.jdbc.Driver");
        con=DriverManager.getConnection("jdbc:mysql:///world", user, password);
        stat=con.createStatement();
        r=stat.executeQuery("SELECT * FROM CITY");
        ResultSetMetaData rdata=r.getMetaData();//get all column details
        int columnCount=rdata.getColumnCount();
        LinkedList<Integer> link=new LinkedList<>();
        for(int i=1;i<=columnCount;i++)//the link store the column type
            link.add(rdata.getColumnType(i));
        //for(int i=1;i<=columnCount;i++)
        //    r.getObject(i);

        //the columncount index starts from 1.......sucks

        while(r.next()){
            //r.previous();
            printTable+="<tr>";
            for(int i=1;i<=columnCount;i++)
                printTable+="<td>"+r.getObject(i).toString()+"</td>";
            //printTable+="<tr><td>"+r.getInt(1)+"</td><td>"+r.getString(2)+"</td><td>"+r.getString(3)+"</td><td>"+r.getString(4)+"</td><td>"+r.getInt(5)+"</td></tr>";
            printTable+="</tr>";
        }
    }
    protected void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException,ServletException{
        response.setContentType("text/html;charset:GBK");
        PrintWriter out=response.getWriter();
        out.println("<html><title>CityÊý¾Ý¿â</title><body>");
        out.println(printTable);
        out.println("</table></body></html>");
    }
}