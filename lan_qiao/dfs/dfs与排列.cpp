//
// Created by Luzius on 2024/4/2.
//
#include<bits/stdc++.h>
typedef long long ll;
const int N = 15;
using namespace std;
int n;
bool vis[N];
int a[N];
void dfs(int depth) {
    if(depth > n) {
        for(int i = 1; i <= n; i++)
            cout << setw(5) << a[i] << " \n"[i == n];
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            a[depth] = i;
            vis[i] = 1;
            dfs(depth + 1);
            vis[i] = 0;
        }
    }

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    dfs(1);
    return 0;
}
