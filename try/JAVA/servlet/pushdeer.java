import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class pushdeer extends HttpServlet {
    protected void doGet(HttpServletRequest request,HttpServletResponse response) {
        response.setContentType("text/html;charset:UTF-8");
        PrintWriter out=response.getWriter();
    }
}