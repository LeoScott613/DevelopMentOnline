列表1=['lhx','fyy',1021]
print(列表1[0]+' and '+列表1[1]+' started from '+str(列表1[-1]))
# 以上用索引的方式把列表的值输出

listForappend=['dead']
listForappend.append(' ')
listForappend.append('cells')
# 列表可以添加元素

for i in listForappend:
    print(i,end='')
    if i=='cells':
        print('\noutput accomplished')
        break
# 以上用循环的方式把列表的值输出

listc=[1,2,3,4,4,3]
print('1 shows up for '+str(listc.count(1)))
print('4 shows up for '+str(listc.count(4)))
# list的count方法

print()
print('listc:'+str(listc))
print('listc列表的长度是'+str(len(listc)))
# 内置的len方法