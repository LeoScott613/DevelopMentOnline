val=10

def test1():
    global val
    val=5  #使全局变量的值改变为5
    print('test1 global val:',val)  #用逗号就不用强转了，因为逗号是分隔，加号是链接

def test2():
    val=8  #这里的val使属于test2的局部变量，对它修改不会影响第一行的val的值
    print('test2 val:',val)

class main(object):
    def __init__(self):
        global val
        test1()
        test2()
        print('current val:',val)

mainThread=main()