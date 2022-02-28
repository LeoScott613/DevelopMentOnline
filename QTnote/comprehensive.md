# comprehensive
* return a.exec();是消息循环函数，有了这个函数，窗口才会一直存在。这个函数在qt的库函数中，标准库函数程序无法使用  
* 最开始新建一个工程，选择widget以创建一个空白的程序  
* 一个工程包含三个部分(现在看来): .pro; /Hearders; /Sources;  
* 最初Sources包含了两个文件:main.cpp和widge.cpp. main.cpp是程序入口
* QApplication类: The QApplication class manages the GUI application's control flow and main settings. 在程序的开头通常有这样的定义:QApplication a(argc, argv). 在程序的末尾使用的消息循环函数就是定义的a对象的exec()成员。*int exec(), 是static public member，类似的还有.beep(). 它们都可以在QApplication的帮助文档中找到。把指针放在QApplication上并按F1就可以查看*
* 按键，是一个对象。创建一个按键对象首先要引用相关头文件，\<QPushButton>
* QApplication类和MainWindow类分别定义在QApplication和mainwindow.h中。而widget类的定义也一样，包含在widget.h中。
* 用代码实现一个label的添加，过程：
    * 在widget.h或者mainwindow.h中引入QLabel头文件
    * 在widget.h或者mainwindow.h中关于Widget类的定义中添加私有的QLabel类型的指针对象
    * 在widget.cpp或者mainwindow.cpp中为this->*指针对象名*创建一个动态对象，用QLabel构造函数进行创建。QLabel("内容"，父对象）是QLabel构造函数。*父对象通常就是 this指针指向的对象*。与this关联之后，这个label才会显示出来
