#include <iostream>
#include <cstring>

class MyString
{
public:
    // 构造函数
    MyString(const char* str = nullptr)
    {
        if (str)
        {
            size_ = std::strlen(str);
            data_ = new char[size_ + 1];
            std::strcpy(data_, str);
        }
        else
        {
            size_ = 0;
            data_ = new char[1];
            data_[0] = '\0';
        }
        std::cout << "Constructor called.\n";
    }

    // 拷贝构造函数
    MyString(const MyString& other) : size_(other.size_)
    {
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
        std::cout << "Copy constructor called.\n";
    }

    // 拷贝赋值运算符
    MyString& operator=(const MyString& other)
    {
        //拷贝赋值最重要的是自赋值检查，还有内存管理
        std::cout << "Copy assignment operator called.\n";
        if (this == &other) //this是指针，所以内容是地址
            return *this; // 自赋值检查

        delete[] data_; // 释放现有资源

        size_ = other.size_;
        data_ = new char[size_ + 1];
        std::strcpy(data_, other.data_);
        return *this;
    }

    // 析构函数
    ~MyString()
    {
        delete[] data_;
        std::cout << "Destructor called.\n";
    }

    void print() const { std::cout << data_ << "\n"; }

private:
    char* data_;
    std::size_t size_;
};


class MoveExample
{
public:
    // 构造函数
    MoveExample(int size) : size_(size), data_(new int[size])
    {
        std::cout << "Constructor called.\n";
    }

    // 拷贝构造函数
    MoveExample(const MoveExample& other) : size_(other.size_),
                                            data_(new int[other.size_])
    {
        std::copy(other.data_, other.data_ + size_, data_);
        std::cout << "Copy constructor called.\n";
    }

    // 移动构造函数
    MoveExample(MoveExample&& other) noexcept : size_(other.size_),
                                                data_(other.data_)
    {
        other.size_ = 0;
        other.data_ = nullptr;
        std::cout << "Move constructor called.\n";
    }

    // 拷贝赋值运算符
    MoveExample& operator=(const MoveExample& other)
    {
        std::cout << "Copy assignment operator called.\n";
        if (this == &other)
            return *this;

        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        std::copy(other.data_, other.data_ + size_, data_);
        return *this;
    }

    // 移动赋值运算符
    // 移动赋值和拷贝赋值都要对象先有构造出来，如果无构造用等于号，会直接调用拷贝构造或移动构造
    MoveExample& operator=(MoveExample&& other) noexcept
    {
        std::cout << "Move assignment operator called.\n";
        if (this == &other)
            return *this;

        delete[] data_;
        size_ = other.size_;
        data_ = other.data_;

        other.size_ = 0;
        other.data_ = nullptr;
        return *this;
    }

    // 析构函数
    ~MoveExample()
    {
        delete[] data_;
        std::cout << "Destructor called.\n";
    }

private:
    int size_;
    int* data_;
};


int main()
{
    // MyString s1("Hello");
    // MyString s2 = s1; // 调用拷贝构造函数
    // MyString s3;
    // s3 = s1; // 调用拷贝赋值运算符
    //
    // s1.print();
    // s2.print();
    // s3.print();
    {
        MoveExample ex1(100); // Constructor
        MoveExample ex2 = ex1; // Copy Constructor
        MoveExample ex3 = MoveExample(200); // Move Constructor

        MoveExample ex4(300);
        ex4 = ex1; // Copy Assignment
        ex4 = MoveExample(400); // Move Assignment
    }
    return 0;
}
