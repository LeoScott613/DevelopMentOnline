from enum import Enum
class gender(Enum):
    Male='Male'
    Female='Female'

    # def __str__(self):
    #     return f'{self.name(self.value)}'

# tinydict={'Name':'Leo','Age':20,'Gender':gender.Male}    # 这会导致输出gender.Male这种没用的字符串

tinydict={'Name':'Leo','Age':20,'Gender':'Male'}
print('his name:',tinydict['Name'])
print('his age:',tinydict['Age'])
print('his gender:',tinydict['Gender'])
print('the \'tinydict\' has ',len(tinydict),' keys')
print('original:',str(tinydict))
del tinydict
print('\n---The dictionary has been deleted---')