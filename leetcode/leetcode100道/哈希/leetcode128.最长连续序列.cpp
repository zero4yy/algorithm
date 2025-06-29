#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        
        for(int x : st) {
            if(st.count(x - 1)) continue; // x - 1 在集合中，跳过元素 x
            
            // 否则，从 x 开始，查找连续的 y
            int y = x + 1;
            while(st.count(y)) y ++;

            // 更新最长序列的长度
            ans = max(ans, y - x);
        }
        return ans;
    }
};
int main() {

    return 0;
}