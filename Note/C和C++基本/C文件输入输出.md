# C file I/O
对文件进行输入输出的前提是**打开文件**。打开文件是为文件建立文件信息区和文件缓冲区的过程。文件信息区本质上是一个结构体变量（*就像显示缓冲实际上是一个二维数组一样*），存放文件有关信息。文件缓冲区是介于程序和磁盘之间的存储空间，对文件的输入和输出必须经过缓冲区。一个文件对应一个文件缓冲区。  
打开文件使用<code>fopen(*filename*,*method*)</code>  
|method|含义|如果文件不存在|
|---|---|---|
|r|只读|出错|
|w|只写|建立新文件|
|a|追加，在文件尾添加数据|出错| 

文件操作相关函数  
feof(FILE)  该函数判断对应文件指针中的位置标识是否已经到了EOF即文件的结尾处。如果已经到函数的结尾则返回1否则返回0  
fprintf(FILE," ",)  
fscanf(FILE," ",)  