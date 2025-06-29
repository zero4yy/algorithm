#include<bits/stdc++.h>
#include<windows.h>
#include <synchapi.h>
#define endl '\n'
typedef long long ll;
using namespace std;
vector<string> vt;
int k;
string str;
ll ans;
bool cmp(string a, string b) {
    if(a.size() != b.size())
        return a.size() < b.size();
    else
        return a < b;
}
void generate(string s, char ch) {
    if(s.size() > 6) return;
    if(!s.empty()) vt.push_back(s);
    for(char c = ch + 1; c <= 'z'; ++c) 
        generate(s + c, c);
}
int main() {
    generate("", 'a' - 1);
    //sort(vt.begin(), vt.end());
    ifstream ifs("input.txt");
    ofstream ofs("output.txt");
    ifs >> k;
    for(int i = 0; i < k; ++i) {
        ifs >> str;
        auto it = find(vt.begin(), vt.end(), str);
        if(it != vt.end()) {
            ans = distance(vt.begin(), it) + 1;
        } else {
            ans = -1;
        }
        ofs << ans << endl;
    }
    
    //输出所有字典序
    for(int i = 0; i < vt.size(); ++i) {
        ofs << i + 1 << ' ' << vt[i] << endl;
    }

    // 关闭文件
    ifs.close();
    ofs.close();

    return 0;
}

