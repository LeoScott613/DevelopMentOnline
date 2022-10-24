class accumulator:
    def __init__(self,initial):
        self.space=initial
    def add(self,num):
        self.space+=num

class substractor:
    def __init__(self,initial):
        self.space=initial
    def sub(self,num):
        self.space-=num

acc=accumulator(0)
sub=substractor(100)
loop=10
while loop>=0:
    adder=int(input())
    acc.add(adder)
    print("accumulation: "+str(acc.space))
    loop-=1
while loop<10:
    suber=int(input())
    sub.sub(suber)
    print("substraction: "+str(sub.space))
    loop+=1
