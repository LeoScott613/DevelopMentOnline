# comprehensive
* return a.exec();是消息循环函数，有了这个函数，窗口才会一直存在。这个函数在qt的库函数中，标准库函数程序无法使用  
* 最开始新建一个工程，选择widget以创建一个空白的程序  
* 一个工程包含三个部分(现在看来): .pro; /Hearders; /Sources;  
* 最初Sources包含了两个文件:main.cpp和widge.cpp. main.cpp是程序入口
* QApplication类: The QApplication class manages the GUI application's control flow and main settings. 在程序的开头通常有这样的定义:QApplication a(argc, argv). 在程序的末尾使用的消息循环函数就是定义的a对象的exec()成员。*int exec(), 是static public member，类似的还有.beep(). 它们都可以在QApplication的帮助文档中找到。把指针放在QApplication上并按F1就可以查看*
* 按键，是一个对象。创建一个按键对象首先要引用相关头文件，\<QPushButton>