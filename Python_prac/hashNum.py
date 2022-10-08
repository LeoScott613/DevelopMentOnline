# 哈希函数
# 哈希值不仅和不可变对象本身的值有关，还和其所在的内存地址有关
number=613
h_number=hash(number)
name='leo scott'
h_name=hash(name)

print(h_number)
print(h_name)
