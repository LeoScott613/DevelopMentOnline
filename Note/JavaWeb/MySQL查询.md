#  ��ѯ
## ������ѯ
ֱ��ʹ��SELECT FROM�����׸����
## ������ѯ
��WHERE���һЩ**ȷ�е�**��ѯ������  
condition�������������ʽ������ʹ�õķ�����=,<,>,<=,>=,!=���������ʽ֮��������߼����������������*�߼�������֮һ��������*���߼��������AND OR NOT  
**ǿ����һ���ֶε�ֵ���ܺ�NULL���бȽϣ���NAME=NULL����������ʽ�ǲ��Եģ���ȷ��Ӧ����NAME IS NULL����NAME IS NOT NULL**
## ģ����ѯ
��WHERE���һЩ**ģ����**��ѯ������  
ʹ��ͨ��������ģ����ѯ������ͨ�����*,%,-�����Ƿֱ��ʾ**ƥ�����У���ƥ�����ַ���ֻ��ƥ�䵥���ַ�**��

```SQL
SELECT * FROM BOOKSHELF;
SELECT ID FROM BOOKSHELF;

SELECT * FROM BOOKSHELF WHERE ID=1;
SELECT * FROM BOOKSHELF WHERE ID>1;

SELECT * FROM BOOKSHELF WHERE NAME LIKE 'C++%';
```