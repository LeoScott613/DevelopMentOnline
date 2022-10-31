from enum import Enum,auto  # 引入enum类型的方法，Enum是类型名，enum是包名
# auto用来自动给枚举变量绑定值（感觉不如C/C++）

class meiju(Enum):
    freshman=auto()
    sophermore=auto()
    
    #获取类中的成员，不能直接用meiju.freshman
    def __str__(self):
        return f'{self.name(self.value)}'

for student in meiju:
    print(student.name,' ',student.value)