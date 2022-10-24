earth=50
def one():
    global earth
    earth=40   #声明完后要在新行赋值
    print('earth in one:'+str(earth))
one()
print('earth in main:'+str(earth))
#总结：函数内要想操作全局变量，要加global关键字，相当于引入全局变量到函数里，否则操作的是局部变量，即使同名