#include <iostream>
typedef char * pstring;
int main()
{
    //类型别名
    pstring str = "Hello, World!";
    const pstring str2 = "Hello, World!";
    //str2是char * const 类型，属于常量指针

    //auto用法
    //auto 初始化时要注意一条声明语句只能有一个基本数据类型
    //所以该语句中所有变量的初始基本数据类型都必须一样：
    //auto sz = 0, pi = 3.14; 错误
    //对于复合类型
    //例如指针，auto一般会忽略掉顶层const，同时底层const则会保留下来
    {
        int i = 0, &r = i;
        // a是一个整数，类型是r所引用的类型
        auto a = r;
        // cr是一个常量引用，ci是int类型的常量
        const int ci = i, &cr = ci;
        // b是一个整数，ci顶层const被忽略了
        auto b = ci;
        // c是一个整数，cr是ci的别名，ci本身是一个顶层const
        auto c = cr;
        // d 是一个整型指针，i是整型
        auto d = &i;
        // e是一个指向整数常量的指针，对常量对象取地址是一种底层const
        auto e = &ci;
    }
    //decltype用法
    {
        //decltype处理顶层const和引用的方式与auto有些许不同。
        //如果decltype使用的表达式是一个变量，则decltype返回该变量的类型（包括顶层const和引用在内）：
        const int ci = 0, &cj = ci;
        //x是const int类型
        decltype(ci) x = 0;
        //y是一个const int&类型，y绑定到x
        decltype(cj) y = x;
        //错误，z是一个引用,引用必须初始化
        //decltype(cj) z;
        //如果decltype使用的表达式不是一个变量，则decltype返回表达式结果对应的类型。
        {
            //decltype的结果可以是引用各类型
            int i = 42, *p = &i, &r = i;
            //正确，假发的结果是int，因此b是一个未初始化的int
            decltype(r + 0) b;
            //错误，c是int&，必须初始化
            //decltype(*p) c;
            //*p是解引用，可以理解为对原对象的引用，因此c是一个int&类型
            //一个特殊的情况就是使用一个括号会导致出现引用
            //decltype的表达式如果加上了括号的变量，结果就是引用
            //错误，d是int&，必须初始化
            //decltype((i)) d;
            //正确,e是一个未被初始化的int类型值
            decltype(i) e;
            //切记：decltype（（variable））（注意是双层括号）的结果永远是引用
            //而decltype（variable）结果只有当variable本身就是一个引用时才是引用。
        }
    }
    return 0;
}
