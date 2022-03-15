import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class pushdeer extends HttpServlet {
    protected void doGet(HttpServletRequest request,HttpServletResponse response) {
        response.setContentType("text/html;charset:UTF-8");
        PrintWriter out=response.getWriter();
        String content=request.getParameter("content");
        String pushSite="https://api2.pushdeer.com/message/push?pushkey=%20PDU2524TD9q37WmTnU0ZMI7X4EEG8BEdj6TbCaKh&text="+content;
        response.setStatus(response.SC_MOVED_TEMPORARILY);
        response.setHeader("Location", pushSite); 
    }
}