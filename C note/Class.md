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
Temp first_try;
first_try.number=114514;
first_try.display();
```
类中同样可以包含构造函数(*其实到目前为止，一个类还是和一个结构体很类似*)