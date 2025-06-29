//
// Created by Luzius on 2024/2/1.
//
//快速幂思想其实很简单，就是公式的转换
//1、当指数是偶数时，我们可以让指数除以2，底数乘以底数
//2、当指数是奇数时，我们可以将指数变为奇数
//
//指数是偶数，2^10 = 4^5
//指数是奇数，4^5 = 4 * 4^4
//指数是偶数， 4 * 4^4 = 4 * 16^2
//指数是偶数，4 * 16^2 = 4 * 256^1
//指数是奇数， 4 * 256^1=4 * 256 * 256^0
//指数为0时停止，那么答案就是计算 4 * 256 = 1024

#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull a, b;
//ull fpow(){
//    ull ans = 1;
//    while(b){//b不为0时执行
//        if(b&1){
//            ans *= a;
//            b -= 1;
//        }
//        else{
//            a *= a;
//            b /= 2;
//        }
//    }
//    return ans;
//}
ull fpow(){//精简版 a^11 = a^8 * a^2 * a^1
    ull ans = 1;
    while(b){
        if(b&1)ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
int main(){
    cin >> a >> b;
    cout << fpow();
}