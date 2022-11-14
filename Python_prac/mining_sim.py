#模拟挖矿的过程:proof of work
from hashlib import sha256
from random import randint
class block:
    def __init__(self,transaction,randnum):
        self.transaction=transaction
        self.randnum=randnum

random_macro=20020610    # 随机数的规模

transer=input('from:').encode('utf-8')
receiver=input('to:').encode('utf-8')
bitcoin=input('value:').encode('utf-8')
sign=input('signature:').encode('utf-8')
transaction=[transer,receiver,bitcoin,sign] # 建立一个事务

randnum=randint(0,random_macro) # 属于本区块的随机数
print('answer should be:',randnum,'\n')
encoder=sha256()
for element in transaction:
    encoder.update(element)
encoder.update(str(randnum).encode('utf-8')) # 插入随机数来生成哈希值，该随机数要转字符串，然后编码为utf-8
hash_of_block=encoder.hexdigest()

# 接下来开始mining
CreateBlock=False
for randx in range(0,random_macro):
    new_encoder=sha256()
    for element in transaction:
        new_encoder.update(element)
    new_encoder.update(str(randx).encode('utf-8'))   # 生成包含当前随机数的哈希值

    if new_encoder.hexdigest()==hash_of_block:  # 如果当前的随机数是这个哈希值
        print('|---finish mining, the random number is:',randx,'---|') # 就把这个随机数输出
        CreateBlock=True # 既然找到了随机数，那就要确认这个区块了，通过bool变量向循环外传递信息
        break

if CreateBlock:
    block_=block(transaction,randx)