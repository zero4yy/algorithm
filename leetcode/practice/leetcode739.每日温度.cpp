#include <bits/stdc++.h>

using namespace std;

// 最小堆
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int len = temperatures.size();
        vector<int> ans(len, 0);
        int x;
        for(int i = len - 1; i >= 0; i --) {
            x = temperatures[i];
            while(st.size() && st.top().second <= x) st.pop();
            if(st.size()) ans[i] = (st.top().first - i);
            else ans[i] = 0;
            st.push({i, x});
        }
        return ans;
    }
};

int main() {

}