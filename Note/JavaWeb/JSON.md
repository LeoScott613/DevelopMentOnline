#  JavaScript Object Notation
json是一种轻量级的数据交换**格式**，采用完全独立于编程语言的文本格式来存储和表示数据。json具有简洁清晰的层次结构。json这套标记符分为构造字符、字符串、数字和字面值。*PS：字面值就是true flase null*。构造字符有6个，是组成json结构的一些字符。  
**构造字符是：** {}[]:;  
键值对，格式是key:value  
键值对之间用, 分隔  
json有数组，用方括号合起来的一组值就是一个数组  
数组本身是可以作为值的  
json不同于js对象  
要实现从json字符串转换为JS对象，使用JSON.parse()  