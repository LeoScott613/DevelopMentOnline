# top命令
## 操作
**上下滑动**  
top的进程列表默认以pid排序，使用方向键上下滑动  

**kill 進程**  
在top运行时按k，终端会询问进程id，输入并enter，之后会出现Send PID xxxx signal [15/sigerm]，这是选择关闭方式。SIGTERM允许进程优雅地终止。使用SIGKILL来强制终止。*后面传送的这个是信号*  

**前台进程进后台**  
在一个运行的前台进程，比如minecraftserver，按下ctrl+z，这个任务会被stopped。使用jobs即可找到所有在后台运行的进程。jobs的命令可以是running stopped terminated。使用fg命令或bg %jobnumber将后台中的任务调到前台运行。%jobnumber是后台运行程序的顺序标号。  

**进程排序**  
在主界面按
* M 按内存使用情况排序
* P 按CPU使用率排序
* T 按使用时间排序
* N 按进程ID排序
