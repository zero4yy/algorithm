#include <bits/stdc++.h>

using namespace std;

// 区间合并 按左端点进行排序
// 比较右端点
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ans;
        for(auto &interval : intervals) {
            if(!ans.empty() && interval[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            } else {
                ans.emplace_back(interval);
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}