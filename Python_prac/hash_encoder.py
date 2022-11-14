# encoder, method:md5,sha256
from hashlib import sha256
from hashlib import md5
encode_box=input("Please input the string you want to encode:").encode('utf-8')   # 字符串经过encode了之后才能被哈希加密
encode_method=input("Please input the method you want to encode(sha256 or md5):").encode('utf-8')    # 每个字符串对象都内建了encode方法，因此可以直接用.调用，类似的内建方法还有很多
if encode_method=='sha256'.encode('utf-8'):       # 一个字符串在调用了encode方法之后和原字符串进行判等时是不会通过的
    encoder=sha256()
    encoder.update(encode_box)
elif encode_method=='md5'.encode('utf-8'):
    encoder=md5()
    encoder.update(encode_box)
else:
    print("You choose the wrong method, the progrom is gong to exit!")
    exit()
print('Encoded result is:',encoder.hexdigest())
