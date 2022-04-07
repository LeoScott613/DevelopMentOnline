# JQuery
## What is JQuery
JQuery is a javascript library, including these functions:  
* HTML 元素选取
* HTML 元素操作
* CSS 操作
* HTML 事件函数
* JavaScript 特效和动画
* HTML DOM 遍历和修改
* AJAX
* Utilities
JQuery is a javascript file in essence, 所以在html文档中用\<script>标签去引入
```html
<head>
<script src="jquery-1.10.2.min.js"></script>
</head>
```
## jQuery 语法
可以使用jQuery选取HTML元素，并对选取的元素执行某些操作。基础语法:```$(selector).action()```    
实例:  
* $(this).hide() - 隐藏当前元素
* $("p").hide() - 隐藏所有 \<p> 元素
* $("p.test").hide() - 隐藏所有 class="test" 的 \<p> 元素
* $("#test").hide() - 隐藏 id="test" 的元素

所有jQuery函数都应位于一个document ready函数中。这是为了防止文档在完全加载（就绪）之前运行 jQuery 代码，即在 DOM 加载完成后才可以对 DOM 进行操作。  
如果在文档没有完全加载之前就运行函数，操作可能失败。下面是两个具体的例子：  
* 试图隐藏一个不存在的元素
* 获得未完全加载的图像的大小

```javascript
$(document).ready(function(){
 
   // 开始写 jQuery 代码...
 
});
```