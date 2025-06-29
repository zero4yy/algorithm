#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
const int N = 15;
using namespace std;
int n;
ll ans;
bitset<N> vis;
string t;
vector<string> vt;
void dfs(int dep, string& s) {
    if(dep == n) {
        vt.push_back(s);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            s[dep] = i + '0';
            vis[i] = 1;
            dfs(dep + 1, s);
            vis[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs >> n;
    string s(n, '\0');
    char c;
    for(int i = 0; i < n; ++i) {
        ifs >> c;
        t.push_back(c);
    }
    dfs(0, s);
    //for(auto y : vt) cout << y << endl;
    ans = find(vt.begin(), vt.end(), t) - vt.begin();
    ofs << ans << endl;
    t = vt[ans + 1];
    for(char y : t) ofs << y << ' ' ;
    ifs.close();
    ofs.close();
    return 0;
}
