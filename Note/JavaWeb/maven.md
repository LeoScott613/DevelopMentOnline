maven项目的基础要求是什么：目录结构是固定的，要按照它的要求建文件夹。然后是pom.xml文件一定要写。这样它最基础的要求才能完成  
## pom.xml的基础
总之，project内包含的4个标签是硬性要求，分别是modelVersion, groupId, artifactId, version. properties标签内的那三个不是硬性要求但是因具体情况而几乎必须要。dependencies内引入的就是项目需要的jar包了。不过，**maven不能识别本地jar包**。
```xml
<project>
    <modelVersion>4.0.0</modelVersion>
    <groupId>Leo.Scott</groupId>
    <artifactId>My-project</artifactId>
    <version>1.0-Snapshot</version>

    <properties>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
        <maven.compiler.source>18</maven.compiler.source>
        <maven.compiler.target>18</maven.compiler.target>
    </properties>

    <dependencies></dependencies>

</project>
```
因为maven**不能识别本地jar包**，所以必须把jar包添加到maven仓库才能用。添加到本地仓库执行的maven命令就是像这样的```mvn install:install-file -Dfile=D:\Development\Eclipse22-06\VariousWeb\side-load\apache\servlet\10\servlet-api.jar -DgroupId=apache -DartifactId=servlet -Dversion=10 -Dpackaging=jar```。注意，其中Dfile指定的路径必须是绝对路径，否则它报错“需要一个项目来执行本操作”。然而即使在一个项目中，它也会找不到文件。  
安装到本地仓库后，可以在dependency中引用本地仓库里的包了。groupId，artifactId和version是安装时指定的，它们也会体现在这个包所在的目录结构上，为{groupId}/{artifactId}/{version}。如何通过命令行列出所有本地仓库可用的依赖和它们的Id以及version？暂时不明白   

maven添加依赖是去远程仓库（一般是中心仓库）寻找对应的jar包到本地进行编译而不像初学时所有的库都是本地调用的。前往maven repository网站即可以找到许多可以用的依赖并且方便地添加到自己的项目中作为自己的项目的依赖。总是是**远程的**。  

## mvn使用
执行mvn compile就会把src/main/java中的源文件编译了，以同样的目录结构输出到target/classes中  