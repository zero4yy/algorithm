//
// Created by Luzius on 2024/1/29.
//
//https://www.lanqiao.cn/problems/192/learning/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int main()
{
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++)cin >> A[i];
    sort(A, A + N);
    if(A[0] == A[N - 1]){
        cout << N; return 0;
    }
    int d = 0;
    for(int i = 1; i < N; i++)d = __gcd(d, A[i] - A[i - 1]);

    cout << (A[N - 1] - A[0]) / d + 1;
    return 0;
}