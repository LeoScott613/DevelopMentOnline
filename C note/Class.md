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
private:
    int osi;
};//注意引号
```
类中同样可以包含构造函数(*其实到目前为止，一个类还是和一个结构体很类似*)