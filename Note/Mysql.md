# MySQL
**重要：登录，用户，密码，URL，CJ**  
会自动添加MYSQL SHELL的环境变量  
把mysql server\bin添加到环境变量Path中，可以使用mysql命令。因为mysql.exe在mysql server\bin  
创建TABLE需要与DATABASE关联，所以要存在DB才能创建表。创建表之前要USE *database_name*.也可以在命令提示符里添加参数来启动对应的数据库  
SELECT *column* FROM *table*  
SHOW DATABASES;SHOW TABLES;  
INSERT INTO *table_name*   
VALUES (V1,V2,V3)默认情况下对应将值横向插入  
UPDATA 在不加WHERE 限制条件时，会将一整个column的值都修改  
在CREATE TABLE时就确定了column数和对应的数据类型，添加column使用ALTER    
ALTER TABLE :  
ADD COLUMN  
DROP COLUMN   
MODIFY COLUMN  *change the type of certain column*  
RENAME COLUMN *old_column_name* TO *new_column_name*  

与mysql连接需要connector/j的jar包  