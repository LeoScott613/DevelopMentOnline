//package JAVA.servlet;
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class GetAssBack extends HttpServlet{
    protected void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException,ServletException {
        response.setContentType("text/html;charset:UTF-8");
        PrintWriter printw=response.getWriter();
        String name=request.getParameter("name");
        printw.println(
            "<html>"+
    "<title>"+
       " Get Your Ass Back Fool!"+
   " </title>"+
   " <body>"+
       " <h1>Please get out of my way," +name+"</h1>"+
    "</body>"+
"</html>"
        );
    }
}
