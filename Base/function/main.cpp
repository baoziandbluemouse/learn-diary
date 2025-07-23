#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
//C++中函数参数的传递方式主要有以下三种：

//传值调用（Pass by Value）
//函数接收参数的副本，函数内对参数的修改不会影响原始数据。

//传引用调用（Pass by Reference）
//函数接收参数的引用，函数内对参数的修改会影响原始数据。

//传指针调用（Pass by Pointer）
//函数接收指向参数的指针，函数内通过指针可以修改原始数据。

//返回值同理,返回还有返回对象

class Person
{
public:
    std::string name;
    int age;

    Person(std::string s, int a): name(std::move(s)), age(a)
    {
    }
};

Person createPerson(std::string name, int age)
{
    //返回对象
    return {std::move(name), age};
}

int& getMax(int& a, int& b)
{
    //要确保返回的对象在函数外部仍然有效（即不能返回局部变量的引用）
    if (a > b)
        return a;
    else
        return b;
}

int* allocateArray(int size)
{
    int* arr = new int[size];
    for (int i = 0; i < size; ++i)
        arr[i] = i * 2;
    return arr;
}

//函数重载规则
//函数名相同。
//参数列表（类型、数量或顺序）不同。
//返回类型不参与重载的区分。
//仅返回类型不同的重载是非法的。
//默认参数可能会与重载产生冲突，使用时需谨慎。

//函数参数可以指定默认值，调用函数时可以省略这些参数，默认值将被使用。
//如果不省略这个参数，就会用提供的值替代默认值。
//默认参数必须从右端开始，不能跳过中间参数。
//如果同时使用默认参数和重载，可能会产生歧义，需谨慎设计。
void displayInfo(const std::string& name, int age = 18,
                 const std::string& city = "Unknown");

// 函数定义
void displayInfo(const std::string& name, int age, const std::string& city)
{
    std::cout << "Name: " << name
        << ", Age: " << age
        << ", City: " << city << std::endl;
}

//内连函数（Inline Function）
//内联函数通过在函数前加inline关键字，建议编译器将函数代码嵌入到调用处，减少函数调用的开销。
//编译器对inline关键字的处理是建议性质，最终是否内联由编译器决定。
//过度使用内联函数可能导致代码膨胀。
inline int add(int a, int b) { return a + b; }


void greet() { std::cout << "Hello World!" << std::endl; }

// 高阶函数，接受函数指针作为参数
void execute(void (*func)())
{
    func(); // 调用传入的函数
}

//回调函数类型定义
using Callback = void (*)();

// 函数接收回调
void registerCallback(Callback cb)
{
    std::cout << "Before callback" << std::endl;
    cb(); // 执行回调
    std::cout << "After callback" << std::endl;
}

// 回调函数
void myCallback() { std::cout << "Callback executed!" << std::endl; }


void executeCallback(Callback cb) { cb(); }

int main()
{
    {
        //返回引用
        int x = 10;
        int y = 20;
        int& max = getMax(x, y);
        std::cout << "Max: " << max << std::endl;
        max = 30; // 修改引用
        std::cout << "After modification, y: " << y << std::endl;
    }
    {
        //createPerson函数返回一个Person对象。
        //这种方式避开了拷贝函数，以拷贝对象
        //现代编译器通过返回值优化（RVO）减少对象拷贝，提高效率。
        Person person = createPerson("Alice", 25);
        std::cout << "Name: " << person.name << ", Age: " << person.age <<
            std::endl;
    }
    {
        displayInfo("Bob", 25, "New York"); // 全部参数传递
        displayInfo("Charlie", 30); // 省略city
        displayInfo("Diana"); // 省略age和city
    }
    {
        //Lambda表达式是C++11引入的匿名函数，便于在需要函数对象的地方快速定义和使用函数。
        //它允许定义内联的、小型的可调用对象，无需单独定义函数。
        //语法:
        //[ capture_list ] ( parameter_list ) -> return_type {
        // function body
        //}
        //捕获列表（Capture List）：指定如何访问外部变量。
        //[]:不捕获任何变量。
        //[&]:按引用捕获所有外部变量。
        //[=]:按值捕获所有外部变量。
        //[&x, y]:按引用捕获x，按值捕获y。

        //参数列表（Parameter List）：类似普通函数的参数列表。
        // 可以省略类型（C++14及以上支持自动类型推断）。

        //返回类型（Return Type）：可指定返回类型，也可省略，编译器自动推断。
        std::vector<int> v{5, 8, 6, 9, 2, 3, 1};
        std::sort(v.begin(), v.end(),
                  [](const int a, const int b)-> bool { return a > b; });
        std::cout << "Sorted data: ";
        for (const auto num : v)
            std::cout << num << " ";
        std::cout << std::endl;

        int sum = 0;
        int* sum_adr = &sum;
        std::for_each(v.begin(), v.end(), [sum_adr](int n) { *sum_adr += n; });
    }
    {
        //函数指针
        //指向函数的指针变量，保存函数的地址，可以通过指针调用函数。
        // 定义函数指针
        // 语法: 返回类型 (*指针变量名)(参数类型列表) = 函数名;(加不加&都可以,函数名就相当于函数地址）
        void (*funcPtr)() = greet;
        // 通过指针调用函数
        // 如果是有返回值的函数，函数指针解引用可以得到这个值
        // 但不解引用也可以得到，不解引用就相当于直接使用这个函数
        //funcPtr();
        //和指向数组的指针对比
        int array[5] = {1, 2, 3, 4, 5};
        int (*parray)[5] = &array; // 指向数组的指针
        //将函数指针作为参数传递给高阶函数
        execute(funcPtr);
    }
    {
        //回调函数
        //通过函数指针传递的函数，通常用于在特定事件发生时执行自定义操作。
        registerCallback(myCallback);
    }
    {
        // 函数指针也可以指向Lambda表达式，但仅限于不捕获外部变量的Lambda。
        // 不捕获外部变量的Lambda
        // 捕获外部变量的Lambda无法转换为普通函数指针。
        Callback cb = []() { std::cout << "Callback executed!" << std::endl; };
        executeCallback(cb);
    }
    return 0;
}
