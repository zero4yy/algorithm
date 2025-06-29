#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

const int N = 10;
int path[N];
bool st[N];
int n;

void dfs(int u) {
    if(u == n) {
        for(int i = 0; i < n; i ++) cout << path[i] << ' ';
        cout << endl;
    }

    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    //algorithm库函数：next_permutation
    int num[] = {1, 2, 3};
    do{
        cout << num[0] << ' ' << num[1] << ' '<< num[2] << endl;
    } while(next_permutation(num, num + 3));
    
    return 0;
}