#include <bits/stdc++.h>

using namespace std;
int n, m, k;
string s;
map<char, char> mp;
map<char, int> xh;

void work() {
    int len = s.length();
    int rea;
    for(int i = 1; i < len - 1; i ++) {
        // 处理 s[i]
        if(xh[s[i]] == 0) continue;
        rea = k % xh[s[i]];
        for(int j = 0; j < rea; j ++) {
            s[i] = mp[s[i]];
        }
    }
    cout << s << endl;
}
int main() {
    getline(cin, s);
    int len = s.length();
    for(int i= 1; i < len - 1; i ++) {
        xh[s[i]] = 0;
    }
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i ++){
        string xy;
        getline(cin, xy);
        mp[xy[1]] = xy[2];
    }
    char c;
    for(auto &y : xh) {
        if(mp.find(y.first) != mp.end() && mp[y.first] == y.first) continue;
        c = y.first;
        for(int i = 0; i < n; i ++) {
            if(mp.count(c) == 0) break;
            if(mp.count(c) != 0) {
                c = mp[c];
                xh[y.first] ++;
            }
            if(c == y.first) break;
        }
    }

    cin >> m;
    while(m --) {
        cin >> k;
        work();
    }
    return 0;
}