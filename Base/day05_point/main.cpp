#include <iostream>

int main()
{
    system("chcp 65001"); // 设置控制台编码为UTF-8
    //定义ptr2并且赋值，指向var地址
    // int var = 10;
    // int *ptr2 = &var;
    // //ptr_address 存储ptr2的地址
    // int ** ptr_address = &ptr2;
    // std::cout << "var 的地址为: " << &var << std::endl;
    // std::cout << "ptr2 存储的值为: " << ptr2 << std::endl;
    // std::cout << "ptr2 地址为: " << &ptr2 << std::endl;
    // std::cout << "ptr_address 的值为: " << ptr_address << std::endl;
    int ival3 = 42;
    //pval3 被初始化，但没有指向任何对象
    int *pval3 = 0;
    //pval4被初始化，指向ival3的地址
    int* pval4 = &ival3;
    //将pval3的指向改为pval4的指向，二者同时指向ival3
    // pval3 = pval4;
    // std::cout <<"ival3 的地址为：" << &ival3 << std::endl;
    // std::cout <<"pval3 指向的地址为 " << pval3 << std::endl;
    // std::cout <<"pval4 指向的地址为 " << pval4 << std::endl;
    //以指针为例，指针是内存中的对象，像其他对象一样也有自己的地址，
    // 因此允许把指针的地址再存放到另一个指针当中。通过＊的个数可以区分指针的级别。
    // 也就是说，＊＊表示指向指针的指针，＊＊＊表示指向指针的指针的指针，以此类推：
    // int ival4= 1024;
    // // pival4指向了int型的数
    // int *pival4 = &ival4;
    // //ppi指向了一个int型的指针
    // int ** ppi = &pival4;
    //
    // std::cout << "The value of ival\n"
    //     << "direct value: " << ival4 << "\n"
    //     << "indirect value: " << *pival4 << "\n"
    //     << "doubly indirect value : " << **ppi
    //     << std::endl;
    //引用本身不是一个对象，因此不能定义指向引用的指针。
    // 但指针是对象，所以存在对指针的引用
    int init = 42;
    // pinit是一个int型的指针
    int *pinit = nullptr;
    // 当其为空指针时不能解引用它，如果没有设置为空指针，倒是可以解引用，不过没什么用,还很危险
    // rpinit是一个对指针pinit的引用
    int *& rpinit = pinit;
    // rpinit引用了一个指针，因此给rpinit赋值&init就是令pinit指向init
    rpinit = &init;
    //解引用rpinit可以得到init的值，同样也是可以像指针一样修改
    *rpinit = 100;
    std::cout<<init<<std::endl;
    std::cout<<*pinit<<std::endl;
    std::cout<<*rpinit<<std::endl;
    return 0;
}
