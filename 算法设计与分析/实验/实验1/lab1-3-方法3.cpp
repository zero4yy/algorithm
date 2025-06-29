//筛+约数定理
#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 5;
bool vis[N];                                                  //vis[i] = true表示i被筛掉，不是素数
int prime[50000];  
int a, b;
int sum = 0; // 最大的约数个数
int number = 0; // 对应的数
int k = 0;
void optimal_E_sieve(int n){
    for(int i = 2; i <= sqrt(n); i++)                           //筛选掉非素数
        if(!vis[i])
            for(int j = i * i; j <= n; j += i)vis[j] = true;  //标记非素数
    //下面来记录素数
    for(int i = 2; i <= n; i++)
        if(!vis[i]) prime[++k] = i;                            //记录素数prime[1]=2, prime[2]=3, ......
    return;
}
int div(int _n) { 
    int ans = 1;
    int n = _n;

    for(int i = 1; i <= k; ++i) {
        int y = prime[i];
        if(y * y > n) break; // 如果质数大于 sqrt(n)，结束循环
        int cnt = 0;
        while(n % y == 0) n /= y, cnt++; // 分解质因数，cnt 记录质数幂
        ans *= (cnt + 1); //使用约数定理公式
    }

    // 若n > 1，则剩下的 n 为一个幂次为1的质数
    if(n > 1) ans *= 2;
    return ans;
}
int main() {
    ifstream ifs("testData/small_input3.txt");
    ofstream ofs("output3.txt");
    ifs >> a >> b;
    int sqrt_b = sqrt(b);
    // 开始计时
    auto start = chrono::high_resolution_clock::now();

    optimal_E_sieve(sqrt_b); //只需要筛到 sqrt(b) 范围内的质数
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