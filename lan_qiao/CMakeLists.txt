cmake_minimum_required(VERSION 3.27)
project(lan_qiao)

set(CMAKE_CXX_STANDARD 17)

add_executable(lan_qiao
        GCD和LCM/gcd和lcm.cpp
        "GCD和LCM/等差数列.cpp"
        快速幂/快速幂.cpp
        快速幂/模运算.cpp
        快速幂/越狱.cpp
        素数/素数判定.cpp
        素数/素数筛.cpp
        素数/选数.cpp
        素数/质因数分解.cpp
        素数/素数筛_LR.cpp
        二叉树/二叉树的存储.cpp
        二叉树/二叉树的遍历.cpp
        前缀和与差分/前缀和_求和.cpp
        前缀和与差分/前缀和_可获得的最小取值.cpp
        前缀和与差分/前缀和_异或运算.cpp
        前缀和与差分/差分模板.cpp
        dfs/dfs模板.cpp
        dfs/dfs与排列.cpp)
