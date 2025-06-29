#include <bits/stdc++.h>

using namespace std;


// 对于height[i], 找左边最近的比它小的数，找右边最近的比它小的数
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        stack<int> st;
        // 找左边最近的比它小的数
        for(int i = 0; i < n; i ++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }

        vector<int> right(n, n);
        st = stack<int>();
        // 找右表最近的比它小的数
        for(int i = n - 1; i >= 0; i --) {
            while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if(!st.empty()) right[i] = st.top();
            st.push(i);
        }

        // for(auto x : left) cout << x << ' ' << endl;
        // for(auto x : right) cout << x << ' ' << endl;

        // left+1 ~ right-1
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};

int main() {

    return 0;
}