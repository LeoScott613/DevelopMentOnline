## 获取内容
获取一个edit里的内容，用Edit_GetLine宏，定义在windowsx.h中，需要手动引入这个头文件   
Edit_GetLine(1,2,3,4)，分别是edit控件句柄，第几行(0-based)，接收字符数据的地址，最大读取字符数  
也可以用sendmessage的方式传递一个消息给edit控件，不过用宏更加方便  

## style
ES_NUMBER 只允许输入数字到这个框  