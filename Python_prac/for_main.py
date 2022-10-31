class thread:
    def __init__(self):
        self.serialId=1
    def run(self):
        for x in range(5):   #range 5=0 1 2 3 4
            print(x,end=' ')
        print()
        for x in range(3,6): #range 3 6=3 4 5
            print(x,end=' ')
        print()
        for x in range(6,10,2): #range 6 10 2=6 8, 2是步长
            print(x,end=' ')
        print()
# main=thread()
# main.run()
# 被import之后以上两句是会被执行的

#summary:range函数产生的值不会包含终点值的。起点值默认是1