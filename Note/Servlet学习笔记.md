# Servlet学习笔记初步版
*JavaWeb成功入门了，我觉得很开心*  
关于servlet是什么的问题：**本质上，Servlet是一个类**，一个运行在服务器上的类。这个类有它的很实用的功能。仅此而已  
## Servlet如何运行在服务器中
Servlet并不是作为服务器的可执行程序直接运行的，而是在服务器中的**Web容器**中运行。Web容器可以将HTTP协议中的文字转化为Java对象，就比如**HttpServletRequest**和**HttpServletResponse**这两种对象。Servlet运行在Web容器中的概念类似于Java程序运行在JVM中。  
具体地，Servlet发挥作用的过程是：  
1. 客户端对服务器发出HTTP请求
2. 服务器收到请求，如果请求是指向Web容器的（*请求了相关的URL*），就转由它处理
3. Web容器剖析HTTP请求内容，创建对象
4. 根据请求的URL决定实用哪个Servlet来处理请求
5. Servlet处理
6. Web容器将处理后的内容返回给服务器
## Servlet的功能实现
Servlet属于非标准库函数，所以在编译servlet程序的时候，是需要连接Servlet-api.jar这个库的。如果servlet还要与数据库连接，则也需要数据库连接库的jar包。使用javac编译servlet源代码时添加-cp参数（*-cp参数后面跟的是地址，但是地址后面还需要加上具体的文件名或者通配符*）。其实，本质上就是一个.java源文件产生.class文件的过程，只不过产生的这个class属于一个servlet，毕竟编写的时候是继承了HttpServlet类的   
很简短的一个Servlet，但是包含了一个servlet必备的要素  
```java
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class HelloWorld extends HttpServlet {
    protected void doGet(HttpServletRequest request,HttpServletResponse response) throws IOException,ServletException {
        response.setContentType("text/html;charset:UTF-8");
        PrintWriter out=response.getWriter();
        String name=request.getParameter("name");
        out.println("<html></html>");
    }
}
```
