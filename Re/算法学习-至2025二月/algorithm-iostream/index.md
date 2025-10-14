---
title: cpp输入输出提速底层分析
description: 如何提速
date: 2024-12-28
image: card-normal.jpg
categories:
  - cpp
tags:
  - cpp
---
**学习视频链接**:https://www.bilibili.com/video/BV1UH4y1z7JU/
## 为何cpp输入输出会变慢（和C相比）
1. iostream i/o 与 stdio i/o **保持同步**带来的耗时（取消同步流）
2. cin 与 cout **存在绑定**耗费时间
3. **endl**相比\n 耗时
> 上述三个原因对于c来说都是没有的，因此在cpp中使用c风格的输入输出可以极大的提速。
> 但是c风格的输入输出更适合格式化输出，没有cin和cout的便捷，因此想要同时拥有便捷和速度的话就要解决这三个问题


### 取消同步流
什么是同步流？
同步指的是c输出输入与cpp输出输入**保持同步**，由于cpp为了兼容c，c输出输入与cpp输出输入使用的是**同一块缓冲区**，我们将其称为**c流缓冲区**
![同步流解析图](算法学习-至2025二月/algorithm-iostream/tongbuliu.png)
如图所示，这个同步操作带来了耗时，我们可以通过以下代码取消同步流
```cpp
ios::sync_with_stdio(false);
```

### 取消cin与cout绑定
什么是cin与cout绑定？
这是使输入输出更加安全的一个操作，绑定**指的是每次cin输入前都会刷新cout缓冲区**


![解除绑定后的程序](算法学习-至2025二月/algorithm-iostream/cin1.png)




![未解除绑定的程序](算法学习-至2025二月/algorithm-iostream/cin2.png)




![解除绑定，但人为刷新缓冲区的程序](算法学习-至2025二月/algorithm-iostream/cin3.png)


解除绑定操作如下
```cpp
cin.tie(0);
cout.tie(0);
```
>值得注意的是，cout.tie(0)这个语句似乎是多余的，因为cout本来就与null绑定了,不过由于大家都这么写，所以还是写上


### 用'\n'代替endl
为何endl会比'\n'慢？
实际上**endl='\n' + 强制刷新缓冲区**
也就是说
```cpp
cout<<'\n'<<flush;
```
与
```cpp
cout<<endl;
```
是一样的，所以就是这个多出来的**强制刷新缓冲区**导致的耗时
'\n'本身是**不会**刷新缓冲区的，他会在**下一行代码执行时刷新缓冲区**
endl本身是**会**刷新缓冲区的，并且，**在下一行代码执行时他还会再次刷新**
也就是说，**endl**会比'\n'多刷新一次缓冲区，所以会慢一些
> 其实这也是一种安全性的措施，endl保证了在程序崩溃时，能完成输出，而'\n'则不能


### 总结
使cpp风格输入输出提速的解决方法就是
1. 取消同步流
2. 取消cin与cout绑定
3. 用'\n'代替endl
```cpp
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cout<<something<<'\n';
```

