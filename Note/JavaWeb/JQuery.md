# JQuery
## What is JQuery
JQuery is a javascript library, including these functions:  
* HTML Ԫ��ѡȡ
* HTML Ԫ�ز���
* CSS ����
* HTML �¼�����
* JavaScript ��Ч�Ͷ���
* HTML DOM �������޸�
* AJAX
* Utilities
JQuery is a javascript file in essence, ������html�ĵ�����\<script>��ǩȥ����
```html
<head>
<script src="jquery-1.10.2.min.js"></script>
</head>
```
## jQuery �﷨
����ʹ��jQueryѡȡHTMLԪ�أ�����ѡȡ��Ԫ��ִ��ĳЩ�����������﷨:```$(selector).action()```    
ʵ��:  
* $(this).hide() - ���ص�ǰԪ��
* $("p").hide() - �������� \<p> Ԫ��
* $("p.test").hide() - �������� class="test" �� \<p> Ԫ��
* $("#test").hide() - ���� id="test" ��Ԫ��

����jQuery������Ӧλ��һ��document ready�����С�����Ϊ�˷�ֹ�ĵ�����ȫ���أ�������֮ǰ���� jQuery ���룬���� DOM ������ɺ�ſ��Զ� DOM ���в�����  
������ĵ�û����ȫ����֮ǰ�����к�������������ʧ�ܡ�������������������ӣ�  
* ��ͼ����һ�������ڵ�Ԫ��
* ���δ��ȫ���ص�ͼ��Ĵ�С

```javascript
$(document).ready(function(){
 
   // ��ʼд jQuery ����...
 
});
```