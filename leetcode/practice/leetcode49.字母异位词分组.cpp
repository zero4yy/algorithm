#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ranges>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> group;
        for(string& s : strs) {
            string sort_s = s;
            ranges::sort(sort_s); 
            group[sort_s].push_back(s);
        }
        
        ans.reserve(group.size());
        for(auto [_, value] : group) {
            ans.push_back(value);
        }
        return ans;
    }
};
int main() {

    return 0;
}