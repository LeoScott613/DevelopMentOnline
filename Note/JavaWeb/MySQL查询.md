#  ��ѯ
## ������ѯ
ֱ��ʹ��SELECT FROM�����׸����
## ������ѯ
��WHERE���һЩ**ȷ�е�**��ѯ������  
condition�������������ʽ������ʹ�õķ�����=,<,>,<=,>=,!=���������ʽ֮��������߼����������������*�߼�������֮һ��������*���߼��������AND OR NOT  
**ǿ����һ���ֶε�ֵ���ܺ�NULL���бȽϣ���NAME=NULL����������ʽ�ǲ��Եģ���ȷ��Ӧ����NAME IS NULL����NAME IS NOT NULL**
## ģ����ѯ
��WHERE���һЩ**ģ����**��ѯ������  
ʹ��ͨ��������ģ����ѯ������ͨ�����*,%,-�����Ƿֱ��ʾ**�����ַ�����������ַ������������ַ�**��\*��%�����ö��ȽϺ���⡣_����˼��"*���λ��û��ָ���ַ�������ֻҪ��������λ�õ�Ҫ��ģ��������λ�õ��ַ���ʲô��������Ҫ�ķ�Χ*"��

```SQL
-- ������ѯ
SELECT * FROM BOOKSHELF;
SELECT ID FROM BOOKSHELF;

-- ������ѯ
SELECT * FROM BOOKSHELF WHERE ID=1;
SELECT * FROM BOOKSHELF WHERE ID>1;

-- ģ��������ѯ
SELECT * FROM BOOKSHELF WHERE NAME LIKE 'C++%';
SELECT * FROM BOOKSHELF WHERE NAME LIKE '_++%';
SELECT * FROM BOOKSHELF WHERE NAME LIKE '% %';--��ѯ�������ո���ֶ�
```

>**��˼**  
LIKE���������������  
SELECT��������Ч�Ĳ�ѯ��ʽ��  
��ƽ��ʹ�ò�ѯ�ĳ�������Щ��  