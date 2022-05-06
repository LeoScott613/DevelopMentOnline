# string
string str;声明了一个string类型的变量之后，如果没有初始化，默认构造函数会将str初始化为空字符串。s.~string()可以删除这个字符串并释放内存。对一个有内容的字符串，要获取它的长度，使用std.length()或者str.size()。str.empty()检查字符串是否为空。在使用完一个字符串之后可以用str.~string()删除。如果在之后对这个字符串进行输出操作会出现乱码  
string对象几种初始化方式
```cpp
string str("......");
string stt(str);
string sty(6,'.');//it should be an char
string stu(str,2);//start from 0
string sti(str,2,4);//4 representing length you want to copy
```
string对象可以进行的一部分操作
```cpp
swap(str1,str2);
str += "...";
str.append(str0);
str=str1 + str2;
str=str2 + str2;
str.clear();
str.~string();
```
string对象可以用下标访问也可以用迭代器访问  
迭代器访问及相关操作
```cpp
string::iterator iter=str.begin();
iter++;
iter--;
char c=*iter;
while(iter!=str.end())
    iter++;
iter--;
cout<<*iter<<endl;
```
---
## 对getline()的专门笔记  
这个函数接受两个参数，一个输入流对象和一个string对象，比如```getline(cin,str);```getline从输入流的下一行读取，并将读取的内容保存到string对象中**但是不包含换行符**，因为getline读取到换行符后就停止读取并返回了。对于cin来说，也是读入到换行符就停止并且不包括换行符。

---
## 对stringstream的专门笔记
stringstream类型包含在\<sstream>头文件中。stringstream类型可以用来存储整数转化为字符串的结果或者作为转化为整数的字符串的存储对象。这个类型的好处是方便，缺点是对stringstream类型进行构造和析构会耗费CPU大量时间。对一个stringstream进行重复使用可以节省时间。只要在每次需要再次使用stringstream对象之前进行clear()操作就可以了。**在复用stringstream对象之前一定要进行clear()操作**  
以下是int，stringstream和string相关的操作。使用<<和>>操作符
```cpp
int a(100);
stringstream ss;
string str;
ss << a;
ss >> str;
str = ss.str();

ss.clear();
string age="19";
ss << age;
ss >> a;
```

---
## 附加putchar()和getchar()
*其实就是输出一个字符和读入一个字符orz*  
**PS**:数字1与字符1之间的ASCII距离是48( *即一个'0'* )
```cpp
char c;
c = getchar();
putchar(c);
```
需要注意的是```getchar()会读入回车和空格等字符```。如果在输入字符前有数字的输入并且换行了，此时使用getchar()会将换行读进程序(因为这个换行符存在缓冲区里)。倘若不想让换行赋给程序中的变量，就单独用一次getchar()将\n读取掉(但是这也不是保险的做法，最好是关注缓冲区的情况)    
   
## 加法运算符(在String类型中的定义)
+运算符是将右操作数append到左操作数。用这个运算符可以从一个字符串的开头对字符串进行追加。
```cpp
str="Hello"+str;
```
这样就是从开头追加一个内容为"Hello"的字符串。