#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//流格式化输出：
//● std::fixed：以固定小数点格式显示浮点数。
//● std::setprecision(4)：设置小数点后4位精度。
//● std::setw(5)：设置输出字段宽度为5个字符。
//● std::left：设置左对齐。


int main()
{
    system("chcp 65001");
    {
        // double pi = 3.141592653589793;
        // int num = 42;
        // //设置浮点数的显示精度
        // std::cout << "Pi with default precision: " << pi << std::endl;
        // std::cout << "Pi with 4 decimal places: " << std::fixed <<
        //     std::setprecision(4) << pi << std::endl;
        // // 设置字段宽度和对齐方式
        // std::cout << "Number with width 5: |" << std::setw(5) << num << "|" <<
        //     std::endl;
        // std::cout << "Number with width 5 (left aligned): |" << std::left <<
        //     std::setw(5) << num << "|" << std::endl;
    }
    {
        // ofstream专门用于文件创建与写入，ifstream专门用于文件打开和读取
        // std::ofstream outfile("output.txt");
        // if (!outfile)
        // {
        //     std::cerr << "Can't open output file" << std::endl;
        //     return 1;
        // }
        // // 向文件中写入数据
        // outfile << "这是第一行。\n";
        // outfile << "这是第二行，数字：" << 100 << std::endl;
        // outfile << "浮点数：" << 3.14159 << std::endl;
        //
        // outfile.close();
        // std::cout << "Data written to output.txt" << std::endl;
    }
    {
        // std::ifstream infile("output.txt");
        // if (!infile)
        // {
        //     std::cerr << "Can't open input file" << std::endl;
        //     return 1;
        // }
        // std::string line;
        // // 逐行读取文件内容
        // while (std::getline(infile, line))
        // {
        //     std::cout << line << std::endl;
        // }
        // infile.close();
    }
    {
        // //fstream可以同时进行读写操作
        // // 创建一个 fstream 对象，并以读写模式打开文件 "data.txt"
        // std::fstream file("data.txt",
        //                   std::ios::in | std::ios::out | std::ios::app);
        // //std::ios::in：以读取模式打开文件。
        // //std::ios::out：以写入模式打开文件。
        // //std::ios::app：以追加模式写入文件（数据会被添加到文件末尾）。
        // //如果文件不存在，使用 std::ios::in 和 std::ios::out 组合可能无法创建新文件。
        // //在这种情况下，可以添加 std::ios::trunc 或 std::ios::ate 标志，或者先创建文件。
        // if (!file)
        // {
        //     std::cerr << "无法打开文件" << std::endl;
        //     return 1;
        // }
        // // 向文件末尾追加数据
        // file << "这是追加的一行数据。\n";
        // // 将文件指针移动到文件开头以读取内容
        // file.seekg(0, std::ios::beg);
        // std::string line;
        // std::cout << "文件内容如下：" << std::endl;
        // // 逐行读取文件内容并输出到控制台
        // while (std::getline(file, line))
        // {
        //     std::cout << line << std::endl;
        // }
        // file.close();
    }
    {
        //● std::stringstream：同时具备 std::istringstream（输入流）和 std::ostringstream（输出流）的功能
        //既可以从字符串中读取数据，也可以向字符串中写入数据。
        //● std::istringstream：仅用于从字符串中读取数据。
        //● std::ostringstream：仅用于向字符串中写入数据。
        //std::stringstream 常用于以下场景：

        //1. 将其他数据类型转换为字符串。
        //2. 将字符串解析为其他数据类型。
        //3. 构建复杂的字符串。
        // int id = 101;
        // std::string name = "Alice";
        // double score = 95.5;
        // std::stringstream ss;
        // // 向字符串流中写入数据
        // ss << "ID: " << id << ",Name:" << name << ",Score:" << score;
        // std::string result = ss.str(); // 获取构建的字符串
        // std::cout << "Constructed String: " << result << std::endl;
    }
    {
        // std::string data = "2024 John Hello";
        // std::stringstream ss(data);
        // int year;
        // std::string name;
        // std::string greeting;
        // // 从字符串流中读取数据
        // ss >> year >> name >> greeting;
        // std::cout << "Year: " << year << ", Name: " << name
        //     << ", Greeting: " << greeting << std::endl;
    }
    {
        // 字符串转换为整数和浮点数
        std::string numStr = "12345";
        std::string floatStr = "98.76";
        int number;
        double decimal;

        std::stringstream ss1(numStr);
        ss1 >> number;

        std::stringstream ss2(floatStr);
        ss2 >> decimal;

        std::cout << "字符串 \"" << numStr << "\" 转换为整数：" << number << std::endl;
        std::cout << "字符串 \"" << floatStr << "\" 转换为浮点数：" << decimal <<
            std::endl;

        // 数字转换为字符串
        int num = 6789;
        double dec = 12.34;
        std::stringstream ss3;
        ss3 << num << " and " << dec;

        std::string combinedStr = ss3.str();
        std::cout << "数字转换为字符串：" << combinedStr << std::endl;
    }
    {
        std::string csvData = "John,25,80.5";
        std::string name;
        int age;
        double score;

        std::stringstream ss(csvData);
        std::getline(ss, name, ','); // 使用逗号作为分隔符
        ss >> age;
        ss.ignore(1); // 忽略逗号
        ss >> score;

        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Score: " << score << std::endl;
    }

    return 0;
}
