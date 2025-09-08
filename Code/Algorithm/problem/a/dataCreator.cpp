#include <bits/stdc++.h>

using ll = long long;

unsigned long long sd = time(NULL);
unsigned long long lst = 13371 + time(NULL);

ll ri(ll l, ll r)
{
    sd = sd * sd + (sd) ^ lst;
    lst = sd % (r - l + 1) + l;
    return lst;
}

std::string lowercase = "abcdefghijklnmopqrstuvwxyz";
std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    // 编译std.cpp
    system("g++ std.cpp -o std");
    std::cout << "std compiled" << '\n';
    // 编译std.cpp
    //  system("g++ std2.cpp -o std");
    //  std::cout << "std2 compiled" << '\n';

    int nums[] = {1, 2, 3};
    for (const auto &num : nums)
    {
        // 生成data[num].in
        std::string inpath = std::string("data") + std::to_string(num) + ".in";
        std::ofstream in(inpath.c_str(), std::ios::out);

        // 生成输入数据区域
        int T = ri(1, 3);
        in << T << '\n';
        while (T--)
        {
            int n = ri(1, 10);
            int k = ri(0, 20);
            in << n << " " << k << "\n";
            for (int i = 0; i < n; i++)
            {
                in << ri(0, 10) << " ";
            }
            in << "\n";
        }

        std::cout << "data" << num << " in,ok\n";
        in.close();
        // system调用std.exe去生成输出数据
        std::string outpath = std::string("data") + std::to_string(num) + ".out";
        std::string cmd = std::string("std.exe < ") + inpath + " > " + outpath;
        system(cmd.c_str());
        std::cout << "data" << num << " out,ok\n";
        std::cout << "===============\n";

        // system调用std.exe去生成输出数据
        // outpath = std::string("[std2]data") + std::to_string(num) + ".out";
        // cmd = std::string("std2.exe < ") + inpath + " > " + outpath;
        // system(cmd.c_str());
        // std::cout << "生成数据点" << num << "的输出数据，完成！\n";
        // std::cout << "===============\n";
    }
    return 0;
}