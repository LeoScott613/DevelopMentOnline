package JAVA.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.*;
import javax.servlet.http.*;
public class HelloWorld extends HttpServlet {
    protected void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html;charset=UFT-8");
        PrintWriter out=response.getWriter();
        String name=request.getParameter("name");
        out.println(
            "<html>"+
                "<title>Greet</title>"+
                "<body>"+
                    "<h1>Hello, best wishes to you, "+name+"</h1>"+
                "</body>"+
            "</html>"
        );
    }
}
