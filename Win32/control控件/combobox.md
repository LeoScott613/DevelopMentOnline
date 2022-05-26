## digest
要创建一个combo box，同样需要Create window，毕竟combo box**本质也是一个window**，但是还需要将选项加入combo box实例中  
通过SendMessage发送一个CB_ADDSTRING消息来添加一个选项到combo box中。之后发送CB_SETCURSEL消息，就可以显示出一个默认的选项。要想实现下拉之类的效果，需要在程序中响应combo box回传的信息。回传的信息是WB_COMMAND类型的。  

## details
