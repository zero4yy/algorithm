#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(int i, int k) {
        int d = k - path.size();
        if(d == 0) {
            ans.emplace_back(path);
            return;
        }
        if(i < d) return;
        for(int j = i; j >= 1; j --) {
            path.push_back(j);
            dfs(j - 1, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k);
        return ans;
    }
};


int main() {

}