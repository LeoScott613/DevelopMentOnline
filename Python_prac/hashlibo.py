from hashlib import sha256
from hashlib import md5
hasher=sha256()
md5mode=md5()
name=b'lhx'  #byte type
name2=b'fyy'

hasher.update(name)  #传入name给这个hash对象
md5mode.update(name)
print('SHA256加密结果',hasher.hexdigest())  #输出十六进制的hash加密结果
print('MD5加密结果',md5mode.hexdigest())

hasher.update(name2)
md5mode.update(name2)
print('SHA256加密结果',hasher.hexdigest())
print('MD5加密结果',md5mode.hexdigest())

hasher.update(name)  # 不会输出和刚才一样的结果了，update起到拼接作用。最终结果是等价于hasher.update(name+name2+name)的
md5mode.update(name)
print('SHA256加密结果',hasher.hexdigest())
print('MD5加密结果',md5mode.hexdigest())