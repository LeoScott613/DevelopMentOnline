# comprehensive
* return a.exec();����Ϣѭ������������������������ڲŻ�һֱ���ڡ����������qt�Ŀ⺯���У���׼�⺯�������޷�ʹ��  
* �ʼ�½�һ�����̣�ѡ��widget�Դ���һ���հ׵ĳ���  
* һ�����̰�����������(���ڿ���): .pro; /Hearders; /Sources;  
* ���Sources�����������ļ�:main.cpp��widge.cpp. main.cpp�ǳ������
* QApplication��: The QApplication class manages the GUI application's control flow and main settings. �ڳ���Ŀ�ͷͨ���������Ķ���:QApplication a(argc, argv). �ڳ����ĩβʹ�õ���Ϣѭ���������Ƕ����a�����exec()��Ա��*int exec(), ��static public member�����ƵĻ���.beep(). ���Ƕ�������QApplication�İ����ĵ����ҵ�����ָ�����QApplication�ϲ���F1�Ϳ��Բ鿴*
* ��������һ�����󡣴���һ��������������Ҫ�������ͷ�ļ���\<QPushButton>
* QApplication���MainWindow��ֱ�����QApplication��mainwindow.h�С���widget��Ķ���Ҳһ����������widget.h�С�
* �ô���ʵ��һ��label����ӣ����̣�
    * ��widget.h����mainwindow.h������QLabelͷ�ļ�
    * ��widget.h����mainwindow.h�й���Widget��Ķ��������˽�е�QLabel���͵�ָ�����
    * ��widget.cpp����mainwindow.cpp��Ϊthis->*ָ�������*����һ����̬������QLabel���캯�����д�����QLabel("����"����������QLabel���캯����*������ͨ������ thisָ��ָ��Ķ���*����this����֮�����label�Ż���ʾ����
