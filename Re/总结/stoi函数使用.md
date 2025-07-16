---
date: 2025-04-07
tags:
  - "#cpp"
---
```cpp
#include <bits/stdc++.h>

using namespace std;

  

int main()

{

    int n, m;

    // 示例字符串

    string numStr1 = "123";

    string numStr2 = "456abc";

  

    // 基本用法

    n = stoi(numStr1);

    cout << "n 的值: " << n << endl;

  

    // 使用 idx 参数

    size_t pos;

    m = stoi(numStr2, &pos);

    cout << "m 的值: " << m << endl;

    cout << "转换停止的位置: " << pos << endl;

  

    // 使用不同的基数

    string binaryStr = "1010";

    int binaryNum = stoi(binaryStr, nullptr, 2);

    cout << "二进制字符串 1010 转换后的十进制值: " << binaryNum << endl;

  

    return 0;

}
```


```cpp
int stoi (const string&  str, size_t* idx = 0, int base = 10);
int stoi (const wstring& str, size_t* idx = 0, int base = 10);
```

str是要转换的字符串，idx可以用于记录该字符串到哪个下标为止都是数字，base可以用于告诉编辑器，假如字符串本来就是数字，那么这串数字是几进制。（stoi会转为十进制整数）