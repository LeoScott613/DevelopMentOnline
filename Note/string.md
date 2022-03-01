# string
string str;������һ��string���͵ı���֮�����û�г�ʼ����Ĭ�Ϲ��캯���Ὣstr��ʼ��Ϊ���ַ�����s.~string()����ɾ������ַ������ͷ��ڴ档��һ�������ݵ��ַ�����Ҫ��ȡ���ĳ��ȣ�ʹ��std.length()����str.size()��str.empty()����ַ����Ƿ�Ϊ�ա���ʹ����һ���ַ���֮�������str.~string()ɾ���������֮�������ַ�����������������������  
string�����ֳ�ʼ����ʽ
```cpp
string str("......");
string stt(str);
string sty(6,'.');//it should be an char
string stu(str,2);//start from 0
string sti(str,2,4);//4 representing length you want to copy
```
string������Խ��е�һ���ֲ���
```cpp
swap(str1,str2);
str += "...";
str.append(str0);
str=str1 + str2;
str=str2 + str2;
str.clear();
str.~string();
```
string����������±����Ҳ�����õ���������  
���������ʼ���ز���
```cpp
string::iterator iter=str.begin();
iter++;
iter--;
char c=*iter;
while(iter!=str.end())
    iter++;
iter--;
cout<<*iter<<endl;
```
---
## ��getline()��ר�űʼ�  
���������������������һ�������������һ��string���󣬱���```getline(cin,str);```getline������������һ�ж�ȡ��������ȡ�����ݱ��浽string������**���ǲ��������з�**����Ϊgetline��ȡ�����з����ֹͣ��ȡ�������ˡ�����cin��˵��Ҳ�Ƕ��뵽���з���ֹͣ���Ҳ��������з���

---
## ��stringstream��ר�űʼ�
stringstream���Ͱ�����\<sstream>ͷ�ļ��С�stringstream���Ϳ��������洢����ת��Ϊ�ַ����Ľ��������Ϊת��Ϊ�������ַ����Ĵ洢����������͵ĺô��Ƿ��㣬ȱ���Ƕ�stringstream���ͽ��й����������ķ�CPU����ʱ�䡣��һ��stringstream�����ظ�ʹ�ÿ��Խ�ʡʱ�䡣ֻҪ��ÿ����Ҫ�ٴ�ʹ��stringstream����֮ǰ����clear()�����Ϳ����ˡ�**�ڸ���stringstream����֮ǰһ��Ҫ����clear()����**  
������int��stringstream��string��صĲ�����ʹ��<<��>>������
```cpp
int a(100);
stringstream ss;
string str;
ss << a;
ss >> str;
str = ss.str();

ss.clear();
string age="19";
ss << age;
ss >> a;
```

---
## ����putchar()��getchar()
*��ʵ�������һ���ַ��Ͷ���һ���ַ�orz*  
**PS**:����1���ַ�1֮���ASCII������48( *��һ��'0'* )
```cpp
char c;
c = getchar();
putchar(c);
```
��Ҫע�����```getchar()�����س��Ϳո���ַ�```������������ַ�ǰ�����ֵ����벢�һ����ˣ���ʱʹ��getchar()�Ὣ���ж�������(��Ϊ������з����ڻ�������)�����������û��и��������еı������͵�����һ��getchar()��\n��ȡ��(������Ҳ���Ǳ��յ�����������ǹ�ע�����������)    
   
## �ӷ������(��String�����еĶ���)
+������ǽ��Ҳ�����append������������������������Դ�һ���ַ����Ŀ�ͷ���ַ�������׷�ӡ�
```cpp
str="Hello"+str;
```
�������Ǵӿ�ͷ׷��һ������Ϊ"Hello"���ַ�����