class first(object):          #小写object
    def __init__(self,string):#必备的初始化函数，self代指本类
        self.string=string    #python的变量是不需要声明的所以直接self.拿来用

python=first('Hello world.')
print(python.string)          #符号.用来调用成员