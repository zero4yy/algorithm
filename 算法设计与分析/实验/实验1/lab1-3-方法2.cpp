#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a, b;
int sum = 0; // 最大的约数个数
int number = 0; // 对应的数
int main() {   
    ifstream ifs("testData/small_input3.txt");
    ofstream ofs("output3.txt");
    ifs >> a >> b;
    vector<int> divi(b + 1, 0);
    // 开始计时
    auto start = chrono::high_resolution_clock::now();
    for(int i = 1; i <= b; ++i)
        for(int j = i; j <= b; j += i)
            divi[j]++;
    // 遍历区间 [a, b]
    for (int i = a; i <= b; ++i) {
        int k = divi[i]; // 计算 i 的约数个数
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
