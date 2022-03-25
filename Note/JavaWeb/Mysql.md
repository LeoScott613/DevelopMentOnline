# MySQL
***��Ҫ����¼���û������룬URL��CJ***  

## OPERATION
����һ�����û����޸��û�����
```SQL
CREATE USER 'username'@'host' IDENTIFIED BY 'password';
SET PASSWORD FOR 'username'@'host'='PASSWORD';
```
�û���ص���Ϣ�ᱻ������MySQL.USER���С�user ���� MySQL ������Ҫ��һ��Ȩ�ޱ���������¼�������ӵ����������˺���Ϣ����Ҫע����ǣ��� user �������õ�����Ȩ�޶���ȫ�ּ��ģ��������������ݿ⡣��������й��ڸ����û�Ȩ�޵���Ϣ���й�Ȩ�޵��������ù̶��ĸ�ʽ����```'*command*_priv'```�������Ÿ��û���û��ִ��ĳ��command��Ȩ�ޡ�*��Щ�е�����������enum('N','Y')*�����Ҫ�޸�Ȩ�ޣ�����ʹ�� GRANT���Ϊ�û�����һЩȨ�ޣ�Ҳ����ͨ�� UPDATE������ user���ķ�ʽ������Ȩ��  

����һ���±�
```SQL
CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    column3 datatype,
   ....
);
```
Ȼ�������в���ֵ
```SQL
INSERT INTO table_name (column,column...)
VALUES (value,value...),(value,value,...),...;
```
**PS:�ڶ��е�values�м�'s'������ÿһ��ֵ�Ƕ�Ӧָ�����в����**

---

��¼MySQLʹ�õ�����:mysql -u *username* -p  
��װʱ���Զ�����MYSQL SHELL�Ļ�������  
mysql.exe����mysql server\bin��ʹ��mysql����ʱ����������Path��Ҫ����mysql server\bin��  
����TABLE��Ҫ��DATABASE����������Ҫ����DB���ܴ�������������֮ǰҪUSE *database_name*.Ҳ������������ʾ�������Ӳ�����������Ӧ�����ݿ�  
INSERT INTO *table_name*   
VALUES (V1,V2,V3)Ĭ������¶�Ӧ��ֵ�������  
UPDATA �ڲ���WHERE ��������ʱ���Ὣһ����column��ֵ���޸�  
��CREATE TABLEʱ��ȷ����column���Ͷ�Ӧ���������ͣ�����columnʹ��ALTER    
ALTER TABLE :  
ADD COLUMN  
DROP COLUMN   
MODIFY COLUMN  *change the type of certain column*  
RENAME COLUMN *old_column_name* TO *new_column_name*  

��mysql������Ҫconnector/j��jar��������Referenced Libraries��(*VSCode*)  

## MySQL��ʽ
MySQL��ʽָ������������ݿ�ʱӦ�����ص�ԭ��һ������������Ϊ**����ʽ**��  
* ��һ��ʽ��ÿ�в��ɲ�֣���ͬһ���в����ж��ֵ
* �ڶ���ʽ��ÿ�����������
* ������ʽ��������֮��û�д��ݺ���������ϵ

*������Ψһ��ʶ����ÿ�е��л�һ���С�*  
*�������ӷ�����������һ�л�һ���У������е�ֵ������ʶÿһ��*  
*���������������**Ψһֵ***  
*������ʽ����˵������Ҫ��ÿһ�е����ݶ�������ֱ����ض����ܼ�����*  

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