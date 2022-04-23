# MySQL
***重要：登录，用户，密码，URL，CJ***  

## OPERATION
建立一个新用户和修改用户密码
```SQL
CREATE USER 'username'@'host' IDENTIFIED BY 'password';
SET PASSWORD FOR 'username'@'host'='PASSWORD';
```
用户相关的信息会被保存在MySQL.USER表中。user 表是 MySQL 中最重要的一个权限表，用来记录允许连接到服务器的账号信息。需要注意的是，在 user 表里启用的所有权限都是全局级的，适用于所有数据库。这个表中有关于各个用户权限的信息。有关权限的列名采用固定的格式，即```'*command*_priv'```，代表着该用户有没有执行某个command的权限。*这些列的数据类型是enum('N','Y')*。如果要修改权限，可以使用 GRANT语句为用户赋予一些权限，也可以通过 UPDATE语句更新 user表的方式来设置权限  

建立一个新表
```SQL
CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    column3 datatype,
   ....
);
```
在创建新表的时候可以添加主键约束等约束条件
```SQL
CREATE TABLE table_name (
    column1 datatype PRIMARY KEY,
    column2 datatype,
    ...
); --方式1
CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    ...
    PRIMARY KEY (column_name);
); --方式2
```
即使表已经存在也可以添加主键约束
```SQL
ALTER TABLE table_name ADD PRIMARY KEY (column_name); --方式1
ALTER TABLE BookShelf MODIFY ID INT PRIMARY KEY;--方式2，感觉没有方式1方便，因为方式2需要知道对应列的数据类型
```
当然也可以删除主键约束。有两种方式，一是在知道某一列是主键列时使用，第二种知道或者不知道都可以使用。
```SQL
-- 方式1
ALTER TABLE BookShelf MODIFY ID INT;
-- 方式2
ALTER TABLE BookShelf DROP PRIMARY KEY;
```
然后往表中插入值
```SQL
INSERT INTO table_name (column,column...)
VALUES (value,value...),(value,value,...),...;
```
**PS:第二行的values有加's'，并且每一个值是对应指定的列插入的**

---

登录MySQL使用的命令:mysql -u *username* -p  
安装时会自动添加MYSQL SHELL的环境变量  
mysql.exe放在mysql server\bin。使用mysql命令时，环境变量Path中要包含mysql server\bin。  
创建TABLE需要与DATABASE关联，所以要存在DB才能创建表。创建表之前要USE *database_name*.也可以在命令提示符里添加参数来启动对应的数据库  
INSERT INTO *table_name*   
VALUES (V1,V2,V3)默认情况下对应将值横向插入  
UPDATA 在不加WHERE 限制条件时，会将一整个column的值都修改  
在CREATE TABLE时就确定了column数和对应的数据类型，添加column使用ALTER    
ALTER TABLE :  
ADD COLUMN  
DROP COLUMN   
MODIFY COLUMN  *change the type of certain column*  
RENAME COLUMN *old_column_name* TO *new_column_name*  

与mysql连接需要connector/j的jar包，放在Referenced Libraries中(*VSCode*)  

## MySQL事务
事务(transaction)是访问并可能操作各种数据项的一个数据库操作序列，这些操作是一个不可分割的。也就是说，一套事务中的操作要么都执行，要么都不执行。  
举例来说，进行转账涉及两个数据库操作
1. 从被转账户划出款项
2. 将款项划入目标账户

这两个操作就可以看作一个**事务**，因为二者要么都执行要么都不执行，任何一个没有执行都会导致问题  

一个事务具备**ACID特性**：
1. 原子性(Atomicity)：事务中的全部操作在数据库中是不可分割的，要么全部完成，要么全部不执行
2. 一致性(Consistency)：几个并行执行的事务，其执行结果必须与按某一顺序 串行执行的结果相一致
3. 隔离性(Isolation)：事务的执行不受其他事务的干扰，事务执行的中间结果对其他事务必须是透明的
4. 持久性(Durability):对于任意已提交事务，系统必须保证该事务对数据库的改变不被丢失，即使数据库出现故障

事务的ACID特性由关系数据库系统(DBMS)来实现。比如，DBMS采用**日志**来保证事务的原子性、一致性和持久性。**日志记录了事务对数据库所作的更新**，如果某个事务在执行过程中发生错误，就可以根据日志撤销事务对数据库已做的更新，使得数据库回滚到执行事务前的初始状态。  
对于事务的隔离性，DBMS是采用**锁机制**来实现的。当多个事务同时更新数据库中相同的数据时，只允许持有锁的事务能更新该数据，其他事务必须等待，直到前一个事务释放了锁，其他事务才有机会更新该数据。  
*但锁机制也会导致死锁这种问题*  

## MySQL范式
MySQL范式指的是在设计数据库时应该遵守的原则，一般有三个，称为**三大范式**。  
* 第一范式：每列不可拆分，即同一列中不能有多个值
* 第二范式：每列与主键相关
* 第三范式：主键列之间没有传递函数依赖关系

*主键：唯一标识表中每行的列或一组列。*  
*上述句子分析：主键是一列或一组列，这列中的值用来标识每一行*  
*所以主键必须包含**唯一值***  
*第三范式换个说法，即要求每一列的数据都和主键直接相关而不能间接相关*  

## MySQL DATATYPE
### String DATATYPE
|Data type|	Description|
|---|---|
|CHAR(size)	|A FIXED length string (can contain letters, numbers, and special characters). The size parameter specifies the column length in characters - can be from 0 to 255. Default is 1
|VARCHAR(size)|	A VARIABLE length string (can contain letters, numbers, and special characters). The size parameter specifies the maximum column length in characters - can be from 0 to 65535
|BINARY(size)|	Equal to CHAR(), but stores binary byte strings. The size parameter specifies the column length in bytes. Default is 1
|VARBINARY(size)|	Equal to VARCHAR(), but stores binary byte strings. The size parameter specifies the maximum column length in bytes.
|TINYBLOB|	For BLOBs (Binary Large OBjects). Max length: 255 bytes
|TINYTEXT|	Holds a string with a maximum length of 255 characters
|TEXT(size)	|Holds a string with a maximum length of 65,535 bytes
|BLOB(size)	|For BLOBs (Binary Large OBjects). Holds up to 65,535 bytes of data
|MEDIUMTEXT	|Holds a string with a maximum length of 16,777,215 characters
|MEDIUMBLOB	|For BLOBs (Binary Large OBjects). Holds up to 16,777,215 bytes of data
|LONGTEXT	|Holds a string with a maximum length of 4,294,967,295 characters
|LONGBLOB	|For BLOBs (Binary Large OBjects). Holds up to 4,294,967,295 bytes of data
|ENUM(val1, val2, val3, ...)	|A string object that can have only one value, chosen from a list of possible values. You can list up to 65535 values in an ENUM list. If a value is inserted that is not in the list, a blank value will be inserted. The values are sorted in the order you enter them
|SET(val1, val2, val3, ...)|	A string object that can have 0 or more values, chosen from a list of possible values. You can list up to 64 values in a SET list

---
### Numeric DATATYPE
BIT
BOOLEAN
INT
INTEGER
FLOAT
DOUBLE