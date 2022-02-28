# CCTYPE
*include\<cctype\>*  
包含了对单个字符进行判断的一些函数。通常用来判断某个字符是哪一类字符。适用于string对象的字符，也适用于任何字符型字面值常量或字符型变量。  

---
以下是一些在cctype中可能常用的函数
|cctype定义的函数|功能|
|---|---|
|isalnum(c)|如果c是字母或数字则返回**true**|
|isalpha(c)|如果c是字母则返回**true**|
|isdigit(c)|如果c是数字则返回**true**|
|islower(c)|如果c是小写字母则返回**true**|
|isupper(c)|如果c是大写字母则返回**true**|
|tolower(c)|如果c是大写字母，则返回其小写字母，否则直接返回c|
|toupper(c)|如果c是小写字母，则返回其大写字母，否则直接返回c|