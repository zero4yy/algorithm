#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int a, b;
int sum = 0; // 最大的约数个数
int number = 0; // 对应的数
// 计算某个数 n 的约数个数
int div(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            if (i == n / i) // 如果 i 是 n 的平方根，只计算一次
                count++;
            else // 否则，i 和 n/i 都是约数
                count += 2;
        }
    }
    return count;
}

int main() {
    ifstream ifs("testData/small_input3.txt");
    ofstream ofs("output3.txt");
    ifs >> a >> b;
    // 开始计时
    auto start = chrono::high_resolution_clock::now();
    // 遍历区间 [a, b]
    for (int i = a; i <= b; ++i) {
        int k = div(i); // 计算 i 的约数个数
        // 更新最大约数数及其对应的数
        if (k > sum) {
            sum = k;
            number = i;
        } else if (k == sum && i < number) {
            number = i;
        }
    }
    
    // 结束计时
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    // 输出结果
    ofs << "time: " << duration.count() << " ms" << endl;
    ofs << "x: " << number << " div(x): " << sum << endl;
    ifs.close();
    ofs.close();
    return 0;
}
