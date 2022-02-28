# Class
类内部的成员有三种访问标号: public, private, protected
|标号|成员特性|
|---|---|
|public|可以被所有使用该类型的代码访问|
|private|仅可以被类成员访问|
一个类的例子
```cpp
class Temp{
public:
    int number;
    void display();//此处是成员函数的声明
private:
    int osi;
};//注意引号

void Temp::display()//此处是成员函数的定义
{
    std::cout<<"HelloClass!"<<number<<std::endl;
}
```
::是**范围解析运算符**，当一个成员函数**不在类的内部进行定义**而在类的外部进行时，使用这个运算符才能使这个定义定位到这个类的对应成员函数  
要调用一个类对象的成员和调用一个结构体变量的运算符一样
```cpp
Temp first_try, second_try;
first_try.number=114514;
first_try.display();
```
类中同样可以包含构造函数(*其实到目前为止，一个类还是和一个结构体很类似*)  
一个类对象中可以包含不同的成员。直接对类对象进行的操作在没有经过定义的情况下是**非法的**。比如对上述的```first_try```和```second_try```直接进行相加或输出(```first_try+second_try```)(```cout<<first_try;```)都是**非法的**，因为class Temp中并没有定义相关的操作

类的实现的原理:**数据抽象和封装**