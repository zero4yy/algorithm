//
// Created by Luzius on 2024/2/1.
//
//埃氏筛：2~n之间的素数，当n=10^7时，约10M。由于埃氏筛只能用于处理约n=10^7的问题
#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e7 + 5;
bool visit[N];                                                  //visit[i] = true表示i被筛掉，不是素数
int prime[N];                                                   //存放素数，它记录visit[i] = false的项
int E_sieve(int n){                                             //埃氏筛法，计算[2, n]内的素数
    int k = 0;                                                  //统计素数个数
    for(int i = 2; i <= n; i++)                                 //从第一个素数2开始。可优化（1）
        if(!visit[i]){
            prime[++k] = i;                                     //i是素数，存储到prime[]中
            for(int j = 2 * i; j <= n; j += i)visit[j] = true;  //i的倍数，都不是素数。可优化（2）
        }
    return k;                                                   //返回素数个数
}
//优化
//(1)用来做筛除的数2、3、5…等，最多到sqrt(n)就可以了。例如，求n = 100以内的素数，用2、3、5、7筛就足够了。其原理和试除法一样：非素数k，必定可以被一个小于等于
//的素数整除，被筛掉。这个优化很大。
//(2)for(int j=2*i; j<=n; j+=i) 中的j = 2*i优化为 j = i*i。例如i = 5时，2*5、3*5、4*5已经在前面i = 2, 3, 4的时候筛过了。这个优化较小。
int optimal_E_sieve(int n){
    for(int i = 2; i <= sqrt(n); i++)                           //筛选掉非素数
        if(!visit[i])
            for(int j = i * i; j <= n; j += i)visit[j] = true;  //标记非素数
    //下面来记录素数
    int k = 0;
    for(int i = 2; i <= n; i++)
        if(!visit[i])prime[++k] = i;                            //记录素数prime[1]=2, prime[2]=3, ......
    return k;
}
int main(){
    int n; cin >> n;
    cout << optimal_E_sieve(n) << '\n';
    for (int i = 1; i <= optimal_E_sieve(n); i++)cout << prime[i] << " ";
}