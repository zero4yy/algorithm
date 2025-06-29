#include <iostream>

using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;

void insert(string str) {
    int p = 0;
    for(int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}
int query(string str) {
    int p = 0;
    for(int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main() {
    int n;
    cin >> n;
    // while(n--) {
    //     string op, str;
    //     cin >> op >> str;
    //     if(op == "I") insert(str);
    //     else cout << query(str) << endl;
    // }
    while(n--) {
        string str;
        cin >> str;
        insert(str);
    }

    for(int i = 0; i <= idx; i ++) {
        for(int j = 0; j < 26; j ++) {
            cout << son[i][j] << ' ';
        }
        cout << endl;
    }
}

/*
4
abc
abdef
fadeg
ab
*/