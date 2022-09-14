#  查询
## 基础查询
直接使用SELECT FROM不多加赘述。
## 条件查询
用WHERE添加一些**确切的**查询的条件  
condition可以是条件表达式，可以使用的符号有=,<,>,<=,>=,!=。条件表达式之间可以用逻辑运算符连接起来。*逻辑的作用之一就是连接*。逻辑运算符有AND OR NOT  
**强调：一个字段的值不能和NULL进行比较，即NAME=NULL这个条件表达式是不对的，正确的应该是NAME IS NULL或者NAME IS NOT NULL**
## 模糊查询
用WHERE添加一些**模糊的**查询的条件  
使用通配符来添加模糊查询条件，通配符有*,%,-。它们分别表示**所有字符，多个任意字符，单个任意字符**。\*和%的作用都比较好理解。_的意思是"*这个位置没有指定字符，所以只要满足其他位置的要求的，不管这个位置的字符是什么都属于我要的范围*"。

```SQL
-- 基础查询
SELECT * FROM BOOKSHELF;
SELECT ID FROM BOOKSHELF;

-- 条件查询
SELECT * FROM BOOKSHELF WHERE ID=1;
SELECT * FROM BOOKSHELF WHERE ID>1;

-- 模糊条件查询
SELECT * FROM BOOKSHELF WHERE NAME LIKE 'C++%';
SELECT * FROM BOOKSHELF WHERE NAME LIKE '_++%';
SELECT * FROM BOOKSHELF WHERE NAME LIKE '% %';--查询书名带空格的字段
```

>**反思**  
LIKE起到运算符的作用吗？  
SELECT真的是最高效的查询方式吗？  
你平常使用查询的场景有哪些？  