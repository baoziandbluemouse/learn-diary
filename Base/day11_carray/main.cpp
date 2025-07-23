#include <iostream>
#include <cstring>
#include <vector>

char* my_strcpy(char* dest, const char* src)
{
    //使用一个指针记录目标字符串的起始地址
    char* orginal_dest = dest;
    //遍历源字符串，直到遇到结束符'\0'
    while (*src != '\0')
    {
        *dest = *src; // 将源字符串的字符复制到目标字符串
        dest++; // 移动目标字符串指针到下一个位置
        src++; // 移动源字符串指针到下一个位置
    }
    *dest = '\0'; // 在目标字符串的末尾添加结束符'\0'
    return orginal_dest;
}

int main()
{
    //c风格的数组，不能将数组的内容拷贝给其他数组作为其初始值，也不能用数组为其他数组赋值
    //复合类型的数组定义
    {
        int* ptrs[10]; // 定义一个指针数组，包含10个int类型的指针
        //不存在引用数组
        //int &refs[10]; // 错误，不能定义引用数组
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        // 定义一个整型数组
        int (*ptr)[10] = &arr;
        // 定义一个指向整型数组的指针,整型数组的容量是10,数据类型是int
        int (&ref)[10] = arr;
        // 但可以定义一个引用，引用整型数组,整型数组的容量是10,数据类型是int
    }
    //数组不具备越界检测，所以在使用下标访问数组元素的时候，一定要注意防止越界，不要超过或等于数组元素个数
    //在一些情况下数组的操作实际上是指针的操作，这一结论有很多隐含的意思。
    //其中一层意思是当使用数组作为一个auto变量的初始值时，推断得到的类型是指针而非数组
    //当使用decltype关键字时上述转换不会发生，decltype（ia）返回的类型是由10个整数构成的数组：
    {
        int arr[5] = {0, 1, 2, 3, 4};
        auto it = arr; // it的类型是int*，指向数组的第一个元素
        decltype(arr) it2 = {0, 1, 2, 3, 4};
        // it2的类型是int[5]，是一个数组
        // 获取c风格数组的元素个数方式,使用sizeof运算符
        int len = sizeof(arr) / sizeof(int);
        std::cout << "Length of arr: " << len << std::endl;
    }
    //可以说，在c风格数组中，指针就是起到一个迭代器的作用
    {
        //为了方便遍历数组，C++11提供了获取最后元素的下一个位置的指针，以及指向首元素的指针
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int* beg = std::begin(ia);
        int* end = std::end(ia);
        for (auto it = beg; it != end; ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    //c++支持使用c风格字符串，但其并不好用，安全性也不高，如果不考虑兼容c，尽量少用
    {
        char* msg = "hello world!";
        //此类数组结尾必会有一个空字符'\0'，表示字符串的结束
        //一定要注意的是，如果使用cstring里的函数来处理字符串，必须确保字符串以'\0'结尾，否则会导致未定义行为
        //c风格字符串的长度可以通过strlen函数来获取
        int len = std::strlen(msg);
        //c风格字符串要大小比较要使用strcmp函数
        //如果两个字符串相等，strcmp返回0；如果前面的字符串较大，返回正值；如果后面的字符串较大，返回负值：
        const char ca1[] = "A string example";
        const char ca2[] = "A different string example";
        if (strcmp(ca1, ca2) < 0)
        {
            std::cout << "ca1 is less than ca2" <<
                std::endl;
        }
        else
        {
            std::cout << "ca1 is not less than ca2" <<
                std::endl;
        }
        //一般来说，c++使用c风格，是为了与旧代码衔接，或者兼容c语言
        //c++提供了一些函数来与旧代码斜街
        {
            //混用string对象和C风格字符串
            //c_str函数的返回值是一个C风格的字符串。
            std::string s("Hello World");
            //注意返回const char *
            const char* str = s.c_str();
            //使用数组初始化vector对象
            int arr[] = {1, 2, 3, 4, 5};
            std::vector<int> v(arr, arr + 5);
            //或者用
            std::vector<int> v2(std::begin(arr),
                                std::end(arr));
            for (auto i : v2)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    }
    const char* src = "Hello, World!";
    char dest[50];
    my_strcpy(dest, src);
    std::cout << "Source string: " << src << std::endl;
    std::cout << "Copied string: " << dest << std::endl;
    //指针和多维数组
    {
        //大小为3的数组，每个元素是含有4个整数的数组
        //因为多维数组实际上是数组的数组，所以由多维数组名转换得来的指针实际上是指向第一个内层数组的指针：
        int ia[3][4];
        //p指向含有4个整数的数组
        int (*p)[4] = ia;
        //将p修改为指向ia数组的尾部
        p = &ia[2];
    }
    {
        //使用指针遍历二维数组
        //输出ia中每个元素的值,每个内存数组各占一行
        //p指向含有4个整数的数组
        int ia[3][4] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12}};
        for (auto p = ia; p != ia + 3; ++p)
        {
            //q指向4个整数的数组的首元素
            for (auto q = *p; q != *p + 4; ++q)
            {
                std::cout << *q << ' ';
            }
            std::cout << std::endl;
        }
        //c++11提供的begin和end也可以用于多维数组
        // p指向ia的第一个数组
        for (auto p = std::begin(ia); p != std::end(ia); ++
             p)
        {
            // q指向内存数组的首元素
            for (auto q = std::begin(*p); q != std::end(*p);
                 ++q)
            {
                // 输出q所指的整数值
                std::cout << *q << ' ';
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
