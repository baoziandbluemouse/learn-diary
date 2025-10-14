---
date: 2025-05-06
---





# **max_element**（）与**min_element**（）


```cpp
vector<int> n;
int maxPosition = max_element(n.begin(),n.end()) - n.begin(); //最大值下标

int minPosition = min_element(n.begin(),n.end()) - n.begin();//最小值下标

2）普通数组
int a[]={1,2,3,4};
int maxPosition = max_element(a,a+2) - a; //最大值下标

int minPosition = min_element(a,a+2) - a;//最小值下标

使用*可以解引用，返回的是迭代器

```
