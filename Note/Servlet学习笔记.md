# Servletѧϰ�ʼǳ�����
*JavaWeb�ɹ������ˣ��Ҿ��úܿ���*  
����servlet��ʲô�����⣺**�����ϣ�Servlet��һ����**��һ�������ڷ������ϵ��ࡣ����������ĺ�ʵ�õĹ��ܡ����˶���  
## Servlet��������ڷ�������
Servlet��������Ϊ�������Ŀ�ִ�г���ֱ�����еģ������ڷ������е�**Web����**�����С�Web�������Խ�HTTPЭ���е�����ת��ΪJava���󣬾ͱ���**HttpServletRequest**��**HttpServletResponse**�����ֶ���Servlet������Web�����еĸ���������Java����������JVM�С�  
����أ�Servlet�������õĹ����ǣ�  
1. �ͻ��˶Է���������HTTP����
2. �������յ��������������ָ��Web�����ģ�*��������ص�URL*������ת��������
3. Web��������HTTP�������ݣ���������
4. ���������URL����ʵ���ĸ�Servlet����������
5. Servlet����
6. Web���������������ݷ��ظ�������
## Servlet�Ĺ���ʵ��
Servlet���ڷǱ�׼�⺯���������ڱ���servlet�����ʱ������Ҫ����Servlet-api.jar�����ġ����servlet��Ҫ�����ݿ����ӣ���Ҳ��Ҫ���ݿ����ӿ��jar����ʹ��javac����servletԴ����ʱ���-cp������*-cp������������ǵ�ַ�����ǵ�ַ���滹��Ҫ���Ͼ�����ļ�������ͨ���*������ʵ�������Ͼ���һ��.javaԴ�ļ�����.class�ļ��Ĺ��̣�ֻ�������������class����һ��servlet���Ͼ���д��ʱ���Ǽ̳���HttpServlet���   
�ܼ�̵�һ��Servlet�����ǰ�����һ��servlet�ر���Ҫ��  
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
