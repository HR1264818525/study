# Qt

## 核心知识梳理
1.Q_OBJECT宏是干什么？moc 工具做了什么，如果删掉 Q_OBJECT 会发生什么？

答：Q_OBJECT 是qt中的一个类似于库的一个集合，里面包含了c++代码中一写特定的结构； 
moc工具对c++代码进行解读分析，使得Qt能够运行c++代码，删除Q_OBJECT后续的c++程序将无法调用到特定的Qt库而无法运行


2.Q_PROPERTY(int result READ result NOTIFY resultChanged FINAL)
READ 后面的result()函数职责是什么？
NOTIFY 绑定的信号作用是什么，NOTIFY 信号必须满足什么规则？

答：result()函数负责取得调用c++函数的结果
信号作用：在调用结束之前发送给Qt这一信号，信号对应相应的槽函数
不清楚什么规则

3.setContextProperty("calc", calc)：
它把什么给到 QML 环境？字符串"calc"是什么？
不清楚，字符串calc是对应调用的类

