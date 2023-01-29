class people:
    def __init__(self,name:str):
        self.name=name
        self.possession=None
    def set_possession(self,possession:str):
        self.possession=possession
    def get_possession(self) -> str:
        return self.possession

def exchange(a:people,b:people):
    temp=people('sacrifice')
    temp.set_possession(a.get_possession())
    a.set_possession(b.get_possession())
    b.set_possession(temp.get_possession())


alice=people('alice')
bob=people('bob')
alice.set_possession('milk')
bob.set_possession('sperm')

control=input('who you wanna control?\n')
target=input('who do you want to exchange with?\n')
exchange(alice,bob)
print('current possession of alice:{}'.format(alice.get_possession()))
print('current possession of bob:{}'.format(bob.get_possession()))