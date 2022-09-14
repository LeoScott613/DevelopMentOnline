# Spring
首先，Spring MVC是基于servlet技术做出来的框架。然后Spring Web Flow是基于Spring MVC的框架。Spring Web Flow是执行流程用的。而Spring MVC和Spring Web Flow的配置和使用都需要用到一大堆xml所以出现了Spring Boot来简化这个过程。  
*Spring框架的配置文件spring.xml放在src/main/resources下，这个过程是**元数据配置**。通过配置可以获取Spring应用上下文（context）*要获取到这个配置，在程序中使用：
```java
ApplicationContext context=new CLassPathXmlApplicationContext("spring.xml");
//当spring.xml内容是UserService这个bean的定义时：
UserService userService=context.getBean("userService",UserService.class);
//这样，userService这个对象就能够使用了
```

Spring框架的基本功能由**4个子模块**提供，分别是spring-core spring-beans spring-context和spring expression  

## spring-beans
对beans的支持。该模块有几个核心接口：BeanFactory, BeanDfinition, BeanPostProcessor。